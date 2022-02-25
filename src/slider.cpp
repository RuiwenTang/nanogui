/*
    nanogui/slider.cpp -- Fractional slider widget with mouse control

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/slider.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

Slider::Slider(Widget *parent)
    : Widget(parent),
      mValue(0.0f),
      mRange(0.f, 1.f),
      mHighlightedRange(0.f, 0.f) {
  mHighlightColor = Color(255, 80, 80, 70);
}

Vector2i Slider::preferredSize() const { return Vector2i(70, 16); }

bool Slider::mouseDragEvent(const Vector2i &p, const Vector2i & /* rel */,
                            int /* button */, int /* modifiers */) {
  if (!mEnabled) return false;

  const float kr = (int)(mSize.y() * 0.4f), kshadow = 3;
  const float startX = kr + kshadow + mPos.x() - 1;
  const float widthX = mSize.x() - 2 * (kr + kshadow);

  float value = (p.x() - startX) / widthX;
  value = value * (mRange.second - mRange.first) + mRange.first;
  mValue = std::min(std::max(value, mRange.first), mRange.second);
  if (mCallback) mCallback(mValue);
  return true;
}

bool Slider::mouseButtonEvent(const Vector2i &p, int /* button */, bool down,
                              int /* modifiers */) {
  if (!mEnabled) return false;

  const float kr = (int)(mSize.y() * 0.4f), kshadow = 3;
  const float startX = kr + kshadow + mPos.x() - 1;
  const float widthX = mSize.x() - 2 * (kr + kshadow);

  float value = (p.x() - startX) / widthX;
  value = value * (mRange.second - mRange.first) + mRange.first;
  mValue = std::min(std::max(value, mRange.first), mRange.second);
  if (mCallback) mCallback(mValue);
  if (mFinalCallback && !down) mFinalCallback(mValue);
  return true;
}

void Slider::draw(skity::Canvas *canvas) {
  Vector2f center = mSize.cast<float>() * 0.5f;
  float kr = (int)(mSize.y() * 0.4f), kshadow = 3;

  float startX = kr + kshadow + mPos.x();
  float widthX = mSize.x() - 2 * (kr + kshadow);

  Vector2f knobPos(startX + (mValue - mRange.first) /
                                (mRange.second - mRange.first) * widthX,
                   center.y() + 0.5f);

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);

  std::array<skity::Point, 2> pts{};
  std::array<skity::Color4f, 2> colors{};
  pts[0].x = startX;
  pts[0].y = center.y() - 3 + 1;
  pts[1].x = pts[0].x + widthX;
  pts[1].y = pts[0].y + 6;
  colors[0] = Color{0, mEnabled ? 32 : 10}.toColor();
  colors[1] = Color{0, mEnabled ? 128 : 210}.toColor();

  paint.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  skity::Rect rect =
      skity::Rect::MakeXYWH(startX, center.y() - 3 + 1, widthX, 6);

  canvas->drawRoundRect(rect, 2, 2, paint);

  if (mHighlightedRange.second != mHighlightedRange.first) {
    rect = skity::Rect::MakeXYWH(
        startX + mHighlightedRange.first * mSize.x(), center.y() - kshadow + 1,
        widthX * (mHighlightedRange.second - mHighlightedRange.first),
        kshadow * 2);

    paint.setShader(nullptr);
    paint.setFillColor(mHighlightColor.toColor());

    canvas->drawRoundRect(rect, 2, 2, paint);
  }


  paint.setMaskFilter(skity::MaskFilter::MakeBlur(skity::kOuter, kshadow * 2));

  paint.setFillColor(Color{0, 64}.toColor());
  canvas->drawCircle(knobPos.x(), knobPos.y(), kr, paint);

  paint.setMaskFilter(nullptr);

  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  paint.setStrokeColor(mTheme->mBorderDark.toColor());

  canvas->drawCircle(knobPos.x(), knobPos.y(), kr, paint);

  paint.setStyle(skity::Paint::kFill_Style);
  pts[0].x = 0;
  pts[0].y = center.y() - kr;
  pts[1].x = 0;
  pts[1].y = center.y() + kr;
  colors[0] = mTheme->mBorderLight.toColor();
  colors[1] = mTheme->mBorderMedium.toColor();

  paint.setShader(skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  canvas->drawCircle(knobPos.x(), knobPos.y(), kr, paint);

  colors[0] = mTheme->mBorderMedium.toColor();
  colors[1] = mTheme->mBorderLight.toColor();

  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setShader(skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  canvas->drawCircle(knobPos.x(), knobPos.y(), kr / 2, paint);

  paint.setStyle(skity::Paint::kFill_Style);
  paint.setShader(nullptr);
  paint.setFillColor(Color{150, mEnabled ? 255 : 100}.toColor());
  canvas->drawCircle(knobPos.x(), knobPos.y(), kr / 2, paint);
}

void Slider::save(Serializer &s) const {
  Widget::save(s);
  s.set("value", mValue);
  s.set("range", mRange);
  s.set("highlightedRange", mHighlightedRange);
  s.set("highlightColor", mHighlightColor);
}

bool Slider::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("value", mValue)) return false;
  if (!s.get("range", mRange)) return false;
  if (!s.get("highlightedRange", mHighlightedRange)) return false;
  if (!s.get("highlightColor", mHighlightColor)) return false;
  return true;
}

NAMESPACE_END(nanogui)
