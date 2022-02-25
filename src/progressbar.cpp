/*
    src/progressbar.cpp -- Standard widget for visualizing progress

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/progressbar.h>
#include <nanogui/serializer/core.h>

NAMESPACE_BEGIN(nanogui)

ProgressBar::ProgressBar(Widget *parent) : Widget(parent), mValue(0.0f) {}

Vector2i ProgressBar::preferredSize() const { return Vector2i(70, 12); }

void ProgressBar::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);

  std::array<skity::Point, 2> pts{};
  std::array<skity::Color4f, 2> colors{};
  pts[0].x = 1;
  pts[0].y = 1;
  pts[1].x = mSize.x() - 2;
  pts[1].y = mSize.y() - 2;
  colors[0] = Color{0, 32}.toColor();
  colors[1] = Color{0, 92}.toColor();

  paint.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  skity::Rect rect = skity::Rect::MakeXYWH(0, 0, mSize.x(), mSize.y());

  canvas->drawRoundRect(rect, 3, 3, paint);

  float value = std::min(std::max(0.0f, mValue), 1.0f);
  int barPos = (int)std::round((mSize.x() - 2) * value);

  pts[0].x = 0;
  pts[0].y = 0;
  pts[1].x = barPos + 1.5f;
  pts[1].y = mSize.y() - 1;
  colors[0] = Color{220, 100}.toColor();
  colors[1] = Color{128, 100}.toColor();

  paint.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  rect = skity::Rect::MakeXYWH(1, 1, barPos, mSize.y() - 2);

  canvas->drawRoundRect(rect, 3, 3, paint);
}

void ProgressBar::save(Serializer &s) const {
  Widget::save(s);
  s.set("value", mValue);
}

bool ProgressBar::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("value", mValue)) return false;
  return true;
}

NAMESPACE_END(nanogui)
