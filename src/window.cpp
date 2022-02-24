/*
    src/window.cpp -- Top-level window widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/layout.h>
#include <nanogui/opengl.h>
#include <nanogui/screen.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>
#include <nanogui/window.h>

NAMESPACE_BEGIN(nanogui)

Window::Window(Widget *parent, const std::string &title)
    : Widget(parent),
      mTitle(title),
      mButtonPanel(nullptr),
      mModal(false),
      mDrag(false) {
  mStylePaint.setTextSize(18.f);
  mStylePaint.setTypeface(mTheme->mFontBold);
  mStylePaint.setStyle(skity::Paint::kFill_Style);
  initTitleBlob();
}

Vector2i Window::preferredSize() const {
  if (mButtonPanel) mButtonPanel->setVisible(false);
  Vector2i result = Widget::preferredSize();
  if (mButtonPanel) mButtonPanel->setVisible(true);

  if (mTitleBlob == nullptr) {
    return result;
  }

  auto bounds = mTitleBlob->getBoundSize();
  // make some space for text shadow
  bounds.x += 2.f;
  bounds.y += 2.f;
  return result.cwiseMax(Vector2i(bounds.x, bounds.y));
}

Widget *Window::buttonPanel() {
  if (!mButtonPanel) {
    mButtonPanel = new Widget(this);
    mButtonPanel->setLayout(
        new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 4));
  }
  return mButtonPanel;
}

void Window::performLayout() {
  if (!mButtonPanel) {
    Widget::performLayout();
  } else {
    mButtonPanel->setVisible(false);
    Widget::performLayout();
    for (auto w : mButtonPanel->children()) {
      w->setFixedSize(Vector2i(22, 22));
      w->setFontSize(15);
    }
    mButtonPanel->setVisible(true);
    mButtonPanel->setSize(Vector2i(width(), 22));
    mButtonPanel->setPosition(
        Vector2i(width() - (mButtonPanel->preferredSize().x() + 5), 3));
    mButtonPanel->performLayout();
  }
}

void Window::draw(skity::Canvas *canvas) {
  int cr = mTheme->mWindowCornerRadius;
  int hh = mTheme->mWindowHeaderHeight;

  /* Draw window */
  canvas->save();
  skity::Path bound_path;
  bound_path.addRoundRect(skity::Rect::MakeXYWH(0, 0, mSize.x(), mSize.y()), cr,
                          cr);

  // draw shadow
  {
    mStylePaint.setMaskFilter(skity::MaskFilter::MakeBlur(
        skity::kOuter, mTheme->mWindowDropShadowSize));

    mStylePaint.SetFillColor(mTheme->mDropShadow.toColor());

    canvas->drawPath(bound_path, mStylePaint);
    mStylePaint.setMaskFilter(nullptr);
  }

  // draw window

  auto color =
      mMouseFocus ? mTheme->mWindowFillFocused : mTheme->mWindowFillUnfocused;

  mStylePaint.SetFillColor(color.toColor());

  canvas->drawPath(bound_path, mStylePaint);

  if (!mTitle.empty()) {
    /* Draw header */
    float descent = mTitleBlob->getBlobDescent();
    auto title_bounds = mTitleBlob->getBoundSize();
    float offset_y = descent * 0.5f;
    skity::RRect header_round = skity::RRect::MakeRectXY(
        skity::Rect::MakeXYWH(0, 0, mSize.x(), hh), cr, cr);
    {
      std::array<skity::Point, 2> pts{};
      std::array<skity::Color4f, 2> colors{};

      pts[0].x = 0;
      pts[0].y = 0;
      pts[1].x = 0;
      pts[1].y = hh;

      colors[0] = mTheme->mWindowHeaderGradientTop.toColor();
      colors[1] = mTheme->mWindowHeaderGradientBot.toColor();

      mStylePaint.setShader(
          skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

      canvas->drawRRect(header_round, mStylePaint);
      mStylePaint.setShader(nullptr);
    }

    mStylePaint.setStyle(skity::Paint::kStroke_Style);
    mStylePaint.setStrokeWidth(1.f);
    mStylePaint.SetStrokeColor(mTheme->mWindowHeaderSepTop.toColor());

    canvas->drawRRect(header_round, mStylePaint);

    skity::Path line_path;
    line_path.moveTo(0.5f, hh - 1.5f);
    line_path.lineTo(mSize.x() - 0.5f, hh - 1.5f);

    mStylePaint.SetStrokeColor(mTheme->mWindowHeaderSepBot.toColor());

    canvas->drawPath(line_path, mStylePaint);

    mStylePaint.setStyle(skity::Paint::kFill_Style);
    {
      mStylePaint.setMaskFilter(
          skity::MaskFilter::MakeBlur(skity::kOuter, 4.f));
      mStylePaint.SetFillColor(mTheme->mDropShadow.toColor());

      canvas->drawTextBlob(mTitleBlob.get(),
                           (mSize.x() - title_bounds.x) * 0.5f, hh + offset_y,
                           mStylePaint);

      mStylePaint.setMaskFilter(nullptr);
    }

    auto title_color =
        mFocused ? mTheme->mWindowTitleFocused : mTheme->mWindowTitleUnfocused;

    mStylePaint.SetFillColor(title_color.toColor());
    canvas->drawTextBlob(mTitleBlob.get(), (mSize.x() - title_bounds.x) * 0.5f,
                         hh + offset_y - 1, mStylePaint);
  }

  canvas->restore();
  Widget::draw(canvas);
}

void Window::dispose() {
  Widget *widget = this;
  while (widget->parent()) widget = widget->parent();
  ((Screen *)widget)->disposeWindow(this);
}

void Window::center() {
  Widget *widget = this;
  while (widget->parent()) widget = widget->parent();
  ((Screen *)widget)->centerWindow(this);
}

bool Window::mouseDragEvent(const Vector2i &, const Vector2i &rel, int button,
                            int /* modifiers */) {
  if (mDrag && (button & (1 << GLFW_MOUSE_BUTTON_1)) != 0) {
    mPos += rel;
    mPos = mPos.cwiseMax(Vector2i::Zero());
    mPos = mPos.cwiseMin(parent()->size() - mSize);
    return true;
  }
  return false;
}

bool Window::mouseButtonEvent(const Vector2i &p, int button, bool down,
                              int modifiers) {
  if (Widget::mouseButtonEvent(p, button, down, modifiers)) return true;
  if (button == GLFW_MOUSE_BUTTON_1) {
    mDrag = down && (p.y() - mPos.y()) < mTheme->mWindowHeaderHeight;
    return true;
  }
  return false;
}

bool Window::scrollEvent(const Vector2i &p, const Vector2f &rel) {
  Widget::scrollEvent(p, rel);
  return true;
}

void Window::refreshRelativePlacement() { /* Overridden in \ref Popup */
}

void Window::initTitleBlob() {
  if (mTitle.empty()) {
    return;
  }
  skity::TextBlobBuilder builder;

  mTitleBlob = builder.buildTextBlob(mTitle.c_str(), mStylePaint);
}

void Window::save(Serializer &s) const {
  Widget::save(s);
  s.set("title", mTitle);
  s.set("modal", mModal);
}

bool Window::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("title", mTitle)) return false;
  if (!s.get("modal", mModal)) return false;
  mDrag = false;
  return true;
}

NAMESPACE_END(nanogui)
