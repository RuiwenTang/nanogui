/*
    nanogui/tabheader.cpp -- Widget used to control tabs.

    The tab header widget was contributed by Stefan Ivanov.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/tabheader.h>
#include <nanogui/theme.h>

#include <numeric>

NAMESPACE_BEGIN(nanogui)

TabHeader::TabButton::TabButton(TabHeader& header, const std::string& label)
    : mHeader(&header), mLabel(label) {
  rebuildLabelBlob();
}

Vector2i TabHeader::TabButton::preferredSize() const {
  // No need to call nvg font related functions since this is done by the tab
  // header implementation
  if (mLabel.empty()) {
    return Vector2i();
  }
  auto label_bounds = mLabelBlob->getBoundSize();
  int labelWidth = label_bounds.x;
  int buttonWidth =
      labelWidth + 2 * mHeader->theme()->mTabButtonHorizontalPadding;
  int buttonHeight =
      label_bounds.y + 2 * mHeader->theme()->mTabButtonVerticalPadding;
  return Vector2i(buttonWidth, buttonHeight);
}

void TabHeader::TabButton::calculateVisibleString() {
  // The size must have been set in by the enclosing tab header.
  // TODO wait skity implement line break
}

void TabHeader::TabButton::drawAtPosition(skity::Canvas* canvas,
                                          const Vector2i& position,
                                          bool active) {
  int xPos = position.x();
  int yPos = position.y();
  int width = mSize.x();
  int height = mSize.y();
  auto theme = mHeader->theme();

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);

  if (!active) {
    // Background gradients
    std::array<skity::Color4f, 2> colors{};
    colors[0] = theme->mButtonGradientTopPushed.toColor();
    colors[0] = theme->mButtonGradientBotPushed.toColor();
    std::array<skity::Point, 2> pts{};
    pts[0].x = xPos + 1;
    pts[0].y = yPos + 1;
    pts[1].x = width - 1;
    pts[1].y = height + 1;

    paint.setShader(
        skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

    skity::Rect rect =
        skity::Rect::MakeXYWH(xPos + 1, yPos + 1, width - 1, height + 1);

    // Draw the background.
    canvas->drawRoundRect(rect, theme->mButtonCornerRadius,
                          theme->mButtonCornerRadius, paint);

    paint.setShader(nullptr);
  }

  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  if (active) {
    paint.setStrokeColor(theme->mBorderLight.toColor());
    skity::Rect rect =
        skity::Rect::MakeXYWH(xPos + 0.5f, yPos + 1.5f, width, height + 1);

    canvas->drawRoundRect(rect, theme->mButtonCornerRadius,
                          theme->mButtonCornerRadius, paint);

    paint.setStrokeColor(theme->mBorderDark.toColor());
    rect = skity::Rect::MakeXYWH(xPos + 0.5f, yPos + 0.5f, width, height + 1);

    canvas->drawRoundRect(rect, theme->mButtonCornerRadius,
                          theme->mButtonCornerRadius, paint);
  } else {
    skity::Rect rect =
        skity::Rect::MakeXYWH(xPos + 0.5f, yPos + 1.5f, width, height);
    paint.setStrokeColor(theme->mBorderDark.toColor());
    canvas->drawRoundRect(rect, theme->mButtonCornerRadius,
                          theme->mButtonCornerRadius, paint);
  }

  // Draw the text with some padding
  float descent = mLabelBlob->getBlobDescent();
  int textX = xPos + mHeader->theme()->mTabButtonHorizontalPadding;
  int textY = yPos + mHeader->theme()->mTabButtonVerticalPadding + height +
              descent * 0.5f;
  canvas->drawTextBlob(mLabelBlob.get(), textX, textY, mHeader->mStylePaint);
}

void TabHeader::TabButton::drawActiveBorderAt(skity::Canvas* canvas,
                                              const Vector2i& position,
                                              float offset,
                                              const Color& color) {
  int xPos = position.x();
  int yPos = position.y();
  int width = mSize.x();
  int height = mSize.y();
  skity::Paint paint;
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeJoin(skity::Paint::kRound_Join);
  paint.setStrokeColor(color.toColor());
  paint.setStrokeWidth(mHeader->theme()->mTabBorderWidth);

  skity::Path path;
  path.moveTo(xPos + offset, yPos + height + offset);
  path.lineTo(xPos + offset, yPos + offset);
  path.lineTo(xPos + width - offset, yPos + offset);
  path.lineTo(xPos + width - offset, yPos + height + offset);

  canvas->drawPath(path, paint);
}

void TabHeader::TabButton::drawInactiveBorderAt(skity::Canvas* canvas,
                                                const Vector2i& position,
                                                float offset,
                                                const Color& color) {
  int xPos = position.x();
  int yPos = position.y();
  int width = mSize.x();
  int height = mSize.y();

  skity::Paint paint;
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  paint.setStrokeColor(color.toColor());

  skity::Rect rect = skity::Rect::MakeXYWH(xPos + offset, yPos + offset,
                                           width - offset, height - offset);

  canvas->drawRoundRect(rect, mHeader->theme()->mButtonCornerRadius,
                        mHeader->theme()->mButtonCornerRadius, paint);
}

void TabHeader::TabButton::rebuildLabelBlob() {
  mLabelBlob = nullptr;

  if (mLabel.empty()) {
    return;
  }

  mLabelBlob = skity::TextBlobBuilder{}.buildTextBlob(mLabel.c_str(),
                                                      mHeader->mStylePaint);
}

TabHeader::TabHeader(Widget* parent, const std::string& font)
    : Widget(parent), mFont(font) {
  mTheme = parent->theme();
  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(fontSize());

  if (font == "sans") {
    mStylePaint.setTypeface(mTheme->mFontNormal);
  } else {
    mStylePaint.setTypeface(mTheme->mFontBold);
  }

  mIconPaint.setStyle(skity::Paint::kFill_Style);
  int iconSize = mFontSize == -1 ? mTheme->mButtonFontSize : mFontSize;
  iconSize *= icon_scale();
  mIconPaint.setTextSize(iconSize);
  mIconPaint.setTypeface(mTheme->mFontIcons);

  skity::TextBlobBuilder builder;
  mIconLeftBlob =
      builder.buildTextBlob(mTheme->mTabHeaderLeftIcon.c_str(), mIconPaint);
  mIconRightBlob =
      builder.buildTextBlob(mTheme->mTabHeaderRightIcon.c_str(), mIconPaint);
}

void TabHeader::setActiveTab(int tabIndex) {
  assert(tabIndex < tabCount());
  mActiveTab = tabIndex;
  if (mCallback) mCallback(tabIndex);
}

int TabHeader::activeTab() const { return mActiveTab; }

bool TabHeader::isTabVisible(int index) const {
  return index >= mVisibleStart && index < mVisibleEnd;
}

void TabHeader::addTab(const std::string& label) { addTab(tabCount(), label); }

void TabHeader::addTab(int index, const std::string& label) {
  assert(index <= tabCount());
  mTabButtons.insert(std::next(mTabButtons.begin(), index),
                     TabButton(*this, label));
  setActiveTab(index);
}

int TabHeader::removeTab(const std::string& label) {
  auto element =
      std::find_if(mTabButtons.begin(), mTabButtons.end(),
                   [&](const TabButton& tb) { return label == tb.label(); });
  int index = (int)std::distance(mTabButtons.begin(), element);
  if (element == mTabButtons.end()) return -1;
  mTabButtons.erase(element);
  if (index == mActiveTab && index != 0) setActiveTab(index - 1);
  return index;
}

void TabHeader::removeTab(int index) {
  assert(index < tabCount());
  mTabButtons.erase(std::next(mTabButtons.begin(), index));
  if (index == mActiveTab && index != 0) setActiveTab(index - 1);
}

const std::string& TabHeader::tabLabelAt(int index) const {
  assert(index < tabCount());
  return mTabButtons[index].label();
}

int TabHeader::tabIndex(const std::string& label) {
  auto it =
      std::find_if(mTabButtons.begin(), mTabButtons.end(),
                   [&](const TabButton& tb) { return label == tb.label(); });
  if (it == mTabButtons.end()) return -1;
  return (int)(it - mTabButtons.begin());
}

void TabHeader::ensureTabVisible(int index) {
  auto visibleArea = visibleButtonArea();
  auto visibleWidth = visibleArea.second.x() - visibleArea.first.x();
  int allowedVisibleWidth = mSize.x() - 2 * theme()->mTabControlWidth;
  assert(allowedVisibleWidth >= visibleWidth);
  assert(index >= 0 && index < (int)mTabButtons.size());

  auto first = visibleBegin();
  auto last = visibleEnd();
  auto goal = tabIterator(index);

  // Reach the goal tab with the visible range.
  if (goal < first) {
    do {
      --first;
      visibleWidth += first->size().x();
    } while (goal < first);
    while (allowedVisibleWidth < visibleWidth) {
      --last;
      visibleWidth -= last->size().x();
    }
  } else if (goal >= last) {
    do {
      visibleWidth += last->size().x();
      ++last;
    } while (goal >= last);
    while (allowedVisibleWidth < visibleWidth) {
      visibleWidth -= first->size().x();
      ++first;
    }
  }

  // Check if it is possible to expand the visible range on either side.
  while (first != mTabButtons.begin() &&
         std::next(first, -1)->size().x() <
             allowedVisibleWidth - visibleWidth) {
    --first;
    visibleWidth += first->size().x();
  }
  while (last != mTabButtons.end() &&
         last->size().x() < allowedVisibleWidth - visibleWidth) {
    visibleWidth += last->size().x();
    ++last;
  }

  mVisibleStart = (int)std::distance(mTabButtons.begin(), first);
  mVisibleEnd = (int)std::distance(mTabButtons.begin(), last);
}

std::pair<Vector2i, Vector2i> TabHeader::visibleButtonArea() const {
  if (mVisibleStart == mVisibleEnd) return {Vector2i::Zero(), Vector2i::Zero()};
  auto topLeft = mPos + Vector2i(theme()->mTabControlWidth, 0);
  auto width = std::accumulate(
      visibleBegin(), visibleEnd(), theme()->mTabControlWidth,
      [](int acc, const TabButton& tb) { return acc + tb.size().x(); });
  auto bottomRight = mPos + Vector2i(width, mSize.y());
  return {topLeft, bottomRight};
}

std::pair<Vector2i, Vector2i> TabHeader::activeButtonArea() const {
  if (mVisibleStart == mVisibleEnd || mActiveTab < mVisibleStart ||
      mActiveTab >= mVisibleEnd)
    return {Vector2i::Zero(), Vector2i::Zero()};
  auto width = std::accumulate(
      visibleBegin(), activeIterator(), theme()->mTabControlWidth,
      [](int acc, const TabButton& tb) { return acc + tb.size().x(); });
  auto topLeft = mPos + Vector2i(width, 0);
  auto bottomRight =
      mPos + Vector2i(width + activeIterator()->size().x(), mSize.y());
  return {topLeft, bottomRight};
}

void TabHeader::performLayout() {
  Widget::performLayout();

  Vector2i currentPosition = Vector2i::Zero();
  // Place the tab buttons relative to the beginning of the tab header.
  for (auto& tab : mTabButtons) {
    auto tabPreferred = tab.preferredSize();
    if (tabPreferred.x() < theme()->mTabMinButtonWidth)
      tabPreferred.x() = theme()->mTabMinButtonWidth;
    else if (tabPreferred.x() > theme()->mTabMaxButtonWidth)
      tabPreferred.x() = theme()->mTabMaxButtonWidth;
    tab.setSize(tabPreferred);
    tab.calculateVisibleString();
    currentPosition.x() += tabPreferred.x();
  }
  calculateVisibleEnd();
  if (mVisibleStart != 0 || mVisibleEnd != tabCount()) mOverflowing = true;
}

Vector2i TabHeader::preferredSize() const {
  // Set up the nvg context for measuring the text inside the tab buttons.
  //  nvgFontFace(ctx, mFont.c_str());
  //  nvgFontSize(ctx, fontSize());
  //  nvgTextAlign(ctx, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
  Vector2i size = Vector2i(2 * theme()->mTabControlWidth, 0);
  for (auto& tab : mTabButtons) {
    auto tabPreferred = tab.preferredSize();
    if (tabPreferred.x() < theme()->mTabMinButtonWidth)
      tabPreferred.x() = theme()->mTabMinButtonWidth;
    else if (tabPreferred.x() > theme()->mTabMaxButtonWidth)
      tabPreferred.x() = theme()->mTabMaxButtonWidth;
    size.x() += tabPreferred.x();
    size.y() = std::max(size.y(), tabPreferred.y());
  }
  return size;
}

bool TabHeader::mouseButtonEvent(const Vector2i& p, int button, bool down,
                                 int modifiers) {
  Widget::mouseButtonEvent(p, button, down, modifiers);
  if (button == GLFW_MOUSE_BUTTON_1 && down) {
    switch (locateClick(p)) {
      case ClickLocation::LeftControls:
        onArrowLeft();
        return true;
      case ClickLocation::RightControls:
        onArrowRight();
        return true;
      case ClickLocation::TabButtons:
        auto first = visibleBegin();
        auto last = visibleEnd();
        int currentPosition = theme()->mTabControlWidth;
        int endPosition = p.x();
        auto firstInvisible = std::find_if(
            first, last, [&currentPosition, endPosition](const TabButton& tb) {
              currentPosition += tb.size().x();
              return currentPosition > endPosition;
            });

        // Did not click on any of the tab buttons
        if (firstInvisible == last) return true;

        // Update the active tab and invoke the callback.
        setActiveTab((int)std::distance(mTabButtons.begin(), firstInvisible));
        return true;
    }
  }
  return false;
}

void TabHeader::draw(skity::Canvas* canvas) {
  // Draw controls.
  Widget::draw(canvas);
  if (mOverflowing) drawControls(canvas);

  auto current = visibleBegin();
  auto last = visibleEnd();
  auto active = std::next(mTabButtons.begin(), mActiveTab);
  Vector2i currentPosition = mPos + Vector2i(theme()->mTabControlWidth, 0);

  // Flag to draw the active tab last. Looks a little bit better.
  bool drawActive = false;
  Vector2i activePosition = Vector2i::Zero();

  // Draw inactive visible buttons.
  while (current != last) {
    if (current == active) {
      drawActive = true;
      activePosition = currentPosition;
    } else {
      current->drawAtPosition(canvas, currentPosition, false);
    }
    currentPosition.x() += current->size().x();
    ++current;
  }

  // Draw active visible button.
  if (drawActive) active->drawAtPosition(canvas, activePosition, true);
}

void TabHeader::calculateVisibleEnd() {
  auto first = visibleBegin();
  auto last = mTabButtons.end();
  int currentPosition = theme()->mTabControlWidth;
  int lastPosition = mSize.x() - theme()->mTabControlWidth;
  auto firstInvisible = std::find_if(
      first, last, [&currentPosition, lastPosition](const TabButton& tb) {
        currentPosition += tb.size().x();
        return currentPosition > lastPosition;
      });
  mVisibleEnd = (int)std::distance(mTabButtons.begin(), firstInvisible);
}

void TabHeader::drawControls(skity::Canvas* canvas) {
  // Left button.
  bool active = mVisibleStart != 0;

  // Draw the arrow.
  int fontSize = mFontSize == -1 ? mTheme->mButtonFontSize : mFontSize;
  float ih = fontSize;
  ih *= icon_scale();
  Color arrowColor;
  if (active)
    arrowColor = mTheme->mTextColor;
  else
    arrowColor = mTheme->mButtonGradientBotPushed;

  mIconPaint.setFillColor(arrowColor.toColor());

  float yScaleLeft = 0.5f;
  float xScaleLeft = 0.2f;
  float leftIconDescend = mIconLeftBlob->getBlobDescent();
  Vector2f leftIconPos =
      mPos.cast<float>() +
      Vector2f(xScaleLeft * theme()->mTabControlWidth,
               yScaleLeft * (mSize.cast<float>().y() + leftIconDescend * 0.5f));
  canvas->drawTextBlob(mIconLeftBlob.get(), leftIconPos.x(), leftIconPos.y(),
                       mIconPaint);

  // Right button.
  active = mVisibleEnd != tabCount();
  // Draw the arrow.

  float rightWidth = mIconRightBlob->getBoundSize().x;
  if (active)
    arrowColor = mTheme->mTextColor;
  else
    arrowColor = mTheme->mButtonGradientBotPushed;
  mIconPaint.setFillColor(arrowColor.toColor());
  float yScaleRight = 0.5f;
  float xScaleRight =
      1.0f - xScaleLeft - rightWidth / theme()->mTabControlWidth;
  float rightDescend = mIconRightBlob->getBlobDescent();
  Vector2f rightIconPos =
      mPos.cast<float>() +
      Vector2f(mSize.cast<float>().x(),
               (mSize.cast<float>().y() + rightDescend * 0.5f) * yScaleRight) -
      Vector2f(xScaleRight * theme()->mTabControlWidth + rightWidth, 0);

  canvas->drawTextBlob(mIconRightBlob.get(), rightIconPos.x(), rightIconPos.y(),
                       mIconPaint);
}

TabHeader::ClickLocation TabHeader::locateClick(const Vector2i& p) {
  auto leftDistance = (p - mPos).array();
  bool hitLeft =
      (leftDistance >= 0).all() &&
      (leftDistance < Vector2i(theme()->mTabControlWidth, mSize.y()).array())
          .all();
  if (hitLeft) return ClickLocation::LeftControls;
  auto rightDistance =
      (p - (mPos + Vector2i(mSize.x() - theme()->mTabControlWidth, 0))).array();
  bool hitRight =
      (rightDistance >= 0).all() &&
      (rightDistance < Vector2i(theme()->mTabControlWidth, mSize.y()).array())
          .all();
  if (hitRight) return ClickLocation::RightControls;
  return ClickLocation::TabButtons;
}

void TabHeader::onArrowLeft() {
  if (mVisibleStart == 0) return;
  --mVisibleStart;
  calculateVisibleEnd();
}

void TabHeader::onArrowRight() {
  if (mVisibleEnd == tabCount()) return;
  ++mVisibleStart;
  calculateVisibleEnd();
}

NAMESPACE_END(nanogui)
