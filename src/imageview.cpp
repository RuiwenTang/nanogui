/*
    nanogui/imageview.cpp -- Widget used to display images.

    The image view widget was contributed by Stefan Ivanov.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/imageview.h>
#include <nanogui/screen.h>
#include <nanogui/theme.h>
#include <nanogui/window.h>

#include <cmath>

NAMESPACE_BEGIN(nanogui)

namespace {
std::vector<std::string> tokenize(const std::string& string,
                                  const std::string& delim = "\n",
                                  bool includeEmpty = false) {
  std::string::size_type lastPos = 0,
                         pos = string.find_first_of(delim, lastPos);
  std::vector<std::string> tokens;

  while (lastPos != std::string::npos) {
    std::string substr = string.substr(lastPos, pos - lastPos);
    if (!substr.empty() || includeEmpty) tokens.push_back(std::move(substr));
    lastPos = pos;
    if (lastPos != std::string::npos) {
      lastPos += 1;
      pos = string.find_first_of(delim, lastPos);
    }
  }

  return tokens;
}

}  // namespace

ImageView::ImageView(Widget* parent, std::shared_ptr<skity::Pixmap> image)
    : Widget(parent),
      mImage(std::move(image)),
      mScale(1.0f),
      mOffset(Vector2f::Zero()),
      mFixedScale(false),
      mFixedOffset(false),
      mPixelInfoCallback(nullptr) {
  updateImageParameters();
}

ImageView::~ImageView() = default;

Vector2f ImageView::imageCoordinateAt(const Vector2f& position) const {
  auto imagePosition = position - mOffset;
  return imagePosition / mScale;
}

Vector2f ImageView::clampedImageCoordinateAt(const Vector2f& position) const {
  auto imageCoordinate = imageCoordinateAt(position);
  return imageCoordinate.cwiseMax(Vector2f::Zero()).cwiseMin(imageSizeF());
}

Vector2f ImageView::positionForCoordinate(
    const Vector2f& imageCoordinate) const {
  return mScale * imageCoordinate + mOffset;
}

void ImageView::setImageCoordinateAt(const Vector2f& position,
                                     const Vector2f& imageCoordinate) {
  // Calculate where the new offset must be in order to satisfy the image
  // position equation. Round the floating point values to balance out the
  // floating point to integer conversions.
  mOffset = position - (imageCoordinate * mScale);

  // Clamp offset so that the image remains near the screen.
  mOffset = mOffset.cwiseMin(sizeF()).cwiseMax(-scaledImageSizeF());
}

void ImageView::center() { mOffset = (sizeF() - scaledImageSizeF()) / 2; }

void ImageView::fit() {
  // Calculate the appropriate scaling factor.
  mScale = (sizeF().cwiseQuotient(imageSizeF())).minCoeff();
  center();
}

void ImageView::setScaleCentered(float scale) {
  auto centerPosition = sizeF() / 2;
  auto p = imageCoordinateAt(centerPosition);
  mScale = scale;
  setImageCoordinateAt(centerPosition, p);
}

void ImageView::moveOffset(const Vector2f& delta) {
  // Apply the delta to the offset.
  mOffset += delta;

  // Prevent the image from going out of bounds.
  auto scaledSize = scaledImageSizeF();
  if (mOffset.x() + scaledSize.x() < 0) mOffset.x() = -scaledSize.x();
  if (mOffset.x() > sizeF().x()) mOffset.x() = sizeF().x();
  if (mOffset.y() + scaledSize.y() < 0) mOffset.y() = -scaledSize.y();
  if (mOffset.y() > sizeF().y()) mOffset.y() = sizeF().y();
}

void ImageView::zoom(int amount, const Vector2f& focusPosition) {
  auto focusedCoordinate = imageCoordinateAt(focusPosition);
  float scaleFactor = std::pow(mZoomSensitivity, amount);
  mScale = std::max(0.01f, scaleFactor * mScale);
  setImageCoordinateAt(focusPosition, focusedCoordinate);
}

bool ImageView::mouseDragEvent(const Vector2i& p, const Vector2i& rel,
                               int button, int /*modifiers*/) {
  if ((button & (1 << GLFW_MOUSE_BUTTON_LEFT)) != 0 && !mFixedOffset) {
    setImageCoordinateAt((p + rel).cast<float>(),
                         imageCoordinateAt(p.cast<float>()));
    return true;
  }
  return false;
}

bool ImageView::gridVisible() const {
  return (mGridThreshold != -1) && (mScale > mGridThreshold);
}

bool ImageView::pixelInfoVisible() const {
  return mPixelInfoCallback && (mPixelInfoThreshold != -1) &&
         (mScale > mPixelInfoThreshold);
}

bool ImageView::helpersVisible() const {
  return gridVisible() || pixelInfoVisible();
}

bool ImageView::scrollEvent(const Vector2i& p, const Vector2f& rel) {
  if (mFixedScale) return false;
  float v = rel.y();
  if (std::abs(v) < 1) v = std::copysign(1.f, v);
  zoom(v, (p - position()).cast<float>());
  return true;
}

bool ImageView::keyboardEvent(int key, int /*scancode*/, int action,
                              int modifiers) {
  if (action) {
    switch (key) {
      case GLFW_KEY_LEFT:
        if (!mFixedOffset) {
          if (GLFW_MOD_CONTROL & modifiers)
            moveOffset(Vector2f(30, 0));
          else
            moveOffset(Vector2f(10, 0));
          return true;
        }
        break;
      case GLFW_KEY_RIGHT:
        if (!mFixedOffset) {
          if (GLFW_MOD_CONTROL & modifiers)
            moveOffset(Vector2f(-30, 0));
          else
            moveOffset(Vector2f(-10, 0));
          return true;
        }
        break;
      case GLFW_KEY_DOWN:
        if (!mFixedOffset) {
          if (GLFW_MOD_CONTROL & modifiers)
            moveOffset(Vector2f(0, -30));
          else
            moveOffset(Vector2f(0, -10));
          return true;
        }
        break;
      case GLFW_KEY_UP:
        if (!mFixedOffset) {
          if (GLFW_MOD_CONTROL & modifiers)
            moveOffset(Vector2f(0, 30));
          else
            moveOffset(Vector2f(0, 10));
          return true;
        }
        break;
    }
  }
  return false;
}

bool ImageView::keyboardCharacterEvent(unsigned int codepoint) {
  switch (codepoint) {
    case '-':
      if (!mFixedScale) {
        zoom(-1, sizeF() / 2);
        return true;
      }
      break;
    case '+':
      if (!mFixedScale) {
        zoom(1, sizeF() / 2);
        return true;
      }
      break;
    case 'c':
      if (!mFixedOffset) {
        center();
        return true;
      }
      break;
    case 'f':
      if (!mFixedOffset && !mFixedScale) {
        fit();
        return true;
      }
      break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      if (!mFixedScale) {
        setScaleCentered(1 << (codepoint - '1'));
        return true;
      }
      break;
    default:
      return false;
  }
  return false;
}

Vector2i ImageView::preferredSize() const { return mImageSize; }

void ImageView::performLayout() {
  Widget::performLayout();
  center();
}

void ImageView::draw(skity::Canvas* canvas) {
  Widget::draw(canvas);

  if (mImage == nullptr) {
    return;
  }

  canvas->save();

  skity::Rect rect =
      skity::Rect::MakeXYWH(0, 0, mSize.x(), mSize.y());

  canvas->clipRect(rect);

  drawImageBorder(canvas);

  // Calculate several variables that need to be send to OpenGL in order for the
  // image to be properly displayed inside the widget.
  const Screen* screen = dynamic_cast<const Screen*>(this->window()->parent());
  assert(screen);
  Vector2f screenSize = screen->size().cast<float>();
  Vector2f scaleFactor = mScale * imageSizeF().cwiseQuotient(screenSize);
  Vector2f positionInScreen = absolutePosition().cast<float>();
  Vector2f positionAfterOffset = positionInScreen + mOffset;
  Vector2f imagePosition = positionAfterOffset.cwiseQuotient(screenSize);

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setShader(skity::Shader::MakeShader(mImage));

  canvas->drawRect(
      skity::Rect::MakeXYWH(mOffset.x(), mOffset.y(), size().x() * mScale, size().y() * mScale),
      paint);

  if (helpersVisible()) drawHelpers(canvas);

  drawWidgetBorder(canvas);

  canvas->restore();
}

void ImageView::updateImageParameters() {
  if (mImage == nullptr) {
    return;
  }
  mImageSize.x() = mImage->Width();
  mImageSize.y() = mImage->Height();
}

void ImageView::drawWidgetBorder(skity::Canvas* canvas) const {
  skity::Paint paint;
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  paint.setStrokeColor(mTheme->mWindowPopup.toColor());

  skity::Rect rect =
      skity::Rect::MakeXYWH(0.5f, 0.5f, mSize.x() - 1, mSize.y() - 1);

  canvas->drawRect(rect, paint);

  paint.setStrokeColor(mTheme->mBorderDark.toColor());

  canvas->drawRoundRect(rect, mTheme->mButtonCornerRadius,
                        mTheme->mButtonCornerRadius, paint);
}

void ImageView::drawImageBorder(skity::Canvas* canvas) const {
  skity::Paint paint;
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);

  Vector2i borderPosition = mOffset.cast<int>();
  Vector2i borderSize = scaledImageSizeF().cast<int>();

  skity::Rect rect = skity::Rect::MakeXYWH(
      borderPosition.x() - 0.5f, borderPosition.y() - 0.5f, borderSize.x() + 1,
      borderSize.y() + 1);

  paint.setColor(skity::Color_WHITE);

  canvas->drawRect(rect, paint);
}

void ImageView::drawHelpers(skity::Canvas* canvas) const {
  // We need to apply mPos after the transformation to account for the position
  // of the widget relative to the parent.
  Vector2f upperLeftCorner =
      positionForCoordinate(Vector2f::Zero()) + positionF();
  Vector2f lowerRightCorner = positionForCoordinate(imageSizeF()) + positionF();
  if (gridVisible())
    drawPixelGrid(canvas, upperLeftCorner, lowerRightCorner, mScale);
  if (pixelInfoVisible()) drawPixelInfo(canvas, mScale);
}

void ImageView::drawPixelGrid(skity::Canvas* canvas,
                              const Vector2f& upperLeftCorner,
                              const Vector2f& lowerRightCorner, float stride) {
  skity::Path path;
  // Draw the vertical grid lines
  float currentX = upperLeftCorner.x();
  while (currentX <= lowerRightCorner.x()) {
    path.moveTo(std::round(currentX), std::round(upperLeftCorner.y()));
    path.lineTo(std::round(currentX), std::round(lowerRightCorner.y()));
    currentX += stride;
  }

  // Draw the horizontal grid lines
  float currentY = upperLeftCorner.y();
  while (currentY <= lowerRightCorner.y()) {
    path.moveTo(std::round(upperLeftCorner.x()), std::round(currentY));
    path.lineTo(std::round(lowerRightCorner.x()), std::round(currentY));
    currentY += stride;
  }

  skity::Paint paint;
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  paint.setStrokeColor({1.f, 1.f, 1.f, 0.2f});

  canvas->drawPath(path, paint);
}

void ImageView::drawPixelInfo(skity::Canvas* canvas, float stride) const {
  // Extract the image coordinates at the two corners of the widget.
  Vector2i topLeft = clampedImageCoordinateAt(Vector2f::Zero())
                         .unaryExpr([](float x) { return std::floor(x); })
                         .cast<int>();

  Vector2i bottomRight = clampedImageCoordinateAt(sizeF())
                             .unaryExpr([](float x) { return std::ceil(x); })
                             .cast<int>();

  // Extract the positions for where to draw the text.
  Vector2f currentCellPosition =
      (positionF() + positionForCoordinate(topLeft.cast<float>()));

  float xInitialPosition = currentCellPosition.x();
  int xInitialIndex = topLeft.x();

  // Properly scale the pixel information for the given stride.
  auto fontSize = stride * mFontScaleFactor;
  static constexpr float maxFontSize = 30.0f;
  fontSize = fontSize > maxFontSize ? maxFontSize : fontSize;

  while (topLeft.y() != bottomRight.y()) {
    while (topLeft.x() != bottomRight.x()) {
      writePixelInfo(canvas, currentCellPosition, topLeft, stride, fontSize);
      currentCellPosition.x() += stride;
      ++topLeft.x();
    }
    currentCellPosition.x() = xInitialPosition;
    currentCellPosition.y() += stride;
    ++topLeft.y();
    topLeft.x() = xInitialIndex;
  }
}

void ImageView::writePixelInfo(skity::Canvas* canvas,
                               const Vector2f& cellPosition,
                               const Vector2i& pixel, float stride,
                               float fontSize) const {
  auto pixelData = mPixelInfoCallback(pixel);
  auto pixelDataRows = tokenize(pixelData.first);

  // If no data is provided for this pixel then simply return.
  if (pixelDataRows.empty()) return;

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setFillColor(pixelData.second.toColor());
  paint.setTypeface(mTheme->mFontNormal);
  paint.setTextSize(fontSize);

  float yOffset = (stride - fontSize * pixelDataRows.size()) / 2;
  for (size_t i = 0; i != pixelDataRows.size(); ++i) {
    canvas->drawSimpleText2(pixelDataRows[i].data(),
                            cellPosition.x() + stride / 2,
                            cellPosition.y() + yOffset, paint);
    yOffset += fontSize;
  }
}

NAMESPACE_END(nanogui)
