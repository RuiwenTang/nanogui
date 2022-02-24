/*
    src/imagepanel.cpp -- Image panel widget which shows a number of
    square-shaped icons

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/imagepanel.h>
#include <nanogui/opengl.h>

NAMESPACE_BEGIN(nanogui)

ImagePanel::ImagePanel(Widget *parent)
    : Widget(parent),
      mThumbSize(64),
      mSpacing(10),
      mMargin(10),
      mMouseIndex(-1) {}

Vector2i ImagePanel::gridSize() const {
  int nCols = 1 + std::max(0, (int)((mSize.x() - 2 * mMargin - mThumbSize) /
                                    (float)(mThumbSize + mSpacing)));
  int nRows = ((int)mImages.size() + nCols - 1) / nCols;
  return Vector2i(nCols, nRows);
}

int ImagePanel::indexForPosition(const Vector2i &p) const {
  Vector2f pp = ((p - mPos).cast<float>() - Vector2f::Constant(mMargin)) /
                (float)(mThumbSize + mSpacing);
  float iconRegion = mThumbSize / (float)(mThumbSize + mSpacing);
  bool overImage = pp.x() - std::floor(pp.x()) < iconRegion &&
                   pp.y() - std::floor(pp.y()) < iconRegion;
  Vector2i gridPos = pp.cast<int>(), grid = gridSize();
  overImage &=
      ((gridPos.array() >= 0).all() && (gridPos.array() < grid.array()).all());
  return overImage ? (gridPos.x() + gridPos.y() * grid.x()) : -1;
}

bool ImagePanel::mouseMotionEvent(const Vector2i &p, const Vector2i & /* rel */,
                                  int /* button */, int /* modifiers */) {
  mMouseIndex = indexForPosition(p);
  return true;
}

bool ImagePanel::mouseButtonEvent(const Vector2i &p, int /* button */,
                                  bool down, int /* modifiers */) {
  int index = indexForPosition(p);
  if (index >= 0 && index < (int)mImages.size() && mCallback && down)
    mCallback(index);
  return true;
}

Vector2i ImagePanel::preferredSize() const {
  Vector2i grid = gridSize();
  return Vector2i(
      grid.x() * mThumbSize + (grid.x() - 1) * mSpacing + 2 * mMargin,
      grid.y() * mThumbSize + (grid.y() - 1) * mSpacing + 2 * mMargin);
}

void ImagePanel::draw(skity::Canvas *canvas) {
  Vector2i grid = gridSize();

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);

  for (size_t i = 0; i < mImages.size(); ++i) {
    Vector2i p = mPos + Vector2i::Constant(mMargin) +
                 Vector2i((int)i % grid.x(), (int)i / grid.x()) *
                     (mThumbSize + mSpacing);
    int imgw, imgh;

    imgw = mImages[i].first->Width();
    imgh = mImages[i].first->Height();

    float iw, ih, ix, iy;
    if (imgw < imgh) {
      iw = mThumbSize;
      ih = iw * (float)imgh / (float)imgw;
      ix = 0;
      iy = -(ih - mThumbSize) * 0.5f;
    } else {
      ih = mThumbSize;
      iw = ih * (float)imgw / (float)imgh;
      ix = -(iw - mThumbSize) * 0.5f;
      iy = 0;
    }

    paint.setShader(skity::Shader::MakeShader(mImages[i].first));
    paint.setAlphaF(mMouseIndex == (int)i ? 1.f : 0.7f);

    skity::Rect rect = skity::Rect::MakeXYWH(p.x() + ix, p.y() + iy, iw, ih);

    canvas->drawRoundRect(rect, 5, 5, paint);

    skity::Paint shadow_paint;
    shadow_paint.setStyle(skity::Paint::kFill_Style);
    shadow_paint.setColor(skity::ColorSetARGB(255, 0, 0, 0));
    shadow_paint.setMaskFilter(skity::MaskFilter::MakeBlur(skity::kNormal, 5));

    skity::Rect bound_rect =
        skity::Rect::MakeXYWH(p.x(), p.y(), mThumbSize, mThumbSize);

    canvas->drawRoundRect(bound_rect, 6, 6, shadow_paint);

    shadow_paint.setMaskFilter(nullptr);

    shadow_paint.setStyle(skity::Paint::kStroke_Style);
    shadow_paint.setStrokeWidth(1.f);
    shadow_paint.setColor(skity::ColorSetARGB(80, 255, 255, 255));

    canvas->drawRoundRect(bound_rect, 6, 6, shadow_paint);
  }
}

NAMESPACE_END(nanogui)
