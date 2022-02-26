/*
    src/vscrollpanel.cpp -- Adds a vertical scrollbar around a widget
    that is too big to fit into a certain area

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>
#include <nanogui/vscrollpanel.h>

NAMESPACE_BEGIN(nanogui)

VScrollPanel::VScrollPanel(Widget *parent)
    : Widget(parent),
      mChildPreferredHeight(0),
      mScroll(0.0f),
      mUpdateLayout(false) {}

void VScrollPanel::performLayout() {
  Widget::performLayout();

  if (mChildren.empty()) return;
  if (mChildren.size() > 1)
    throw std::runtime_error("VScrollPanel should have one child.");

  Widget *child = mChildren[0];
  mChildPreferredHeight = child->preferredSize().y();

  if (mChildPreferredHeight > mSize.y()) {
    child->setPosition(
        Vector2i(0, -mScroll * (mChildPreferredHeight - mSize.y())));
    child->setSize(Vector2i(mSize.x() - 12, mChildPreferredHeight));
  } else {
    child->setPosition(Vector2i::Zero());
    child->setSize(mSize);
    mScroll = 0;
  }
  child->performLayout();
}

Vector2i VScrollPanel::preferredSize() const {
  if (mChildren.empty()) return Vector2i::Zero();
  return mChildren[0]->preferredSize() + Vector2i(12, 0);
}

bool VScrollPanel::mouseDragEvent(const Vector2i &p, const Vector2i &rel,
                                  int button, int modifiers) {
  if (!mChildren.empty() && mChildPreferredHeight > mSize.y()) {
    float scrollh =
        height() * std::min(1.0f, height() / (float)mChildPreferredHeight);

    mScroll = std::max(
        (float)0.0f,
        std::min((float)1.0f,
                 mScroll + rel.y() / (float)(mSize.y() - 8 - scrollh)));
    mUpdateLayout = true;
    return true;
  } else {
    return Widget::mouseDragEvent(p, rel, button, modifiers);
  }
}

bool VScrollPanel::scrollEvent(const Vector2i &p, const Vector2f &rel) {
  if (!mChildren.empty() && mChildPreferredHeight > mSize.y()) {
    float scrollAmount = rel.y() * (mSize.y() / 20.0f);
    float scrollh =
        height() * std::min(1.0f, height() / (float)mChildPreferredHeight);

    mScroll = std::max(
        (float)0.0f,
        std::min((float)1.0f,
                 mScroll - scrollAmount / (float)(mSize.y() - 8 - scrollh)));
    mUpdateLayout = true;
    return true;
  } else {
    return Widget::scrollEvent(p, rel);
  }
}

void VScrollPanel::draw(skity::Canvas *canvas) {
  if (mChildren.empty()) return;
  Widget *child = mChildren[0];
  child->setPosition(
      Vector2i(0, -mScroll * (mChildPreferredHeight - mSize.y())));
  mChildPreferredHeight = child->preferredSize().y();
  float scrollh =
      height() * std::min(1.0f, height() / (float)mChildPreferredHeight);

  if (mUpdateLayout) child->performLayout();

  canvas->save();
  canvas->clipRect(skity::Rect::MakeHW(mSize.x(), mSize.y()));
  if (child->visible()) {
    canvas->translate(child->position().x(), child->position().y());
    child->draw(canvas);
  }
  canvas->restore();

  if (mChildPreferredHeight <= mSize.y()) return;
  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);

  std::array<skity::Point, 2> pts{};
  std::array<skity::Color4f, 2> colors{};
  pts[0].x = mSize.x() - 12 + 1;
  pts[0].y = 4 + 1;
  pts[1].x = 8;
  pts[1].y = mSize.y() - 8;

  colors[0] = Color{0, 32}.toColor();
  colors[1] = Color{0, 92}.toColor();

  paint.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  skity::Rect rect = skity::Rect::MakeXYWH(mSize.x() - 12, 4, 8, mSize.y() - 8);

  canvas->drawRoundRect(rect, 3, 3, paint);

  pts[0].x = mSize.x() - 12 - 1;
  pts[0].y = 4 + (mSize.y() - 8 - scrollh) * mScroll - 1;
  pts[1].x = 8;
  pts[1].y = scrollh;

  colors[0] = Color{220, 100}.toColor();
  colors[1] = Color{128, 100}.toColor();

  paint.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  rect = skity::Rect::MakeXYWH(mSize.x() - 12 + 1,
                               4 + 1 + (mSize.y() - 8 - scrollh) * mScroll,
                               8 - 2, scrollh - 2);

  canvas->drawRoundRect(rect, 2, 2, paint);
}

void VScrollPanel::save(Serializer &s) const {
  Widget::save(s);
  s.set("childPreferredHeight", mChildPreferredHeight);
  s.set("scroll", mScroll);
}

bool VScrollPanel::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("childPreferredHeight", mChildPreferredHeight)) return false;
  if (!s.get("scroll", mScroll)) return false;
  return true;
}

NAMESPACE_END(nanogui)
