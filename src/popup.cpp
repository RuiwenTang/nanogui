/*
    src/popup.cpp -- Simple popup widget which is attached to another given
    window (can be nested)

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/popup.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

Popup::Popup(Widget *parent, Window *parentWindow)
    : Window(parent, ""),
      mParentWindow(parentWindow),
      mAnchorPos(Vector2i::Zero()),
      mAnchorHeight(30),
      mSide(Side::Right) {}

void Popup::performLayout() {
  if (mLayout || mChildren.size() != 1) {
    Widget::performLayout();
  } else {
    mChildren[0]->setPosition(Vector2i::Zero());
    mChildren[0]->setSize(mSize);
    mChildren[0]->performLayout();
  }
  if (mSide == Side::Left) mAnchorPos[0] -= size()[0];
}

void Popup::refreshRelativePlacement() {
  mParentWindow->refreshRelativePlacement();
  mVisible &= mParentWindow->visibleRecursive();
  mPos = mParentWindow->position() + mAnchorPos - Vector2i(0, mAnchorHeight);
}

void Popup::draw(skity::Canvas *canvas) {
  refreshRelativePlacement();

  if (!mVisible) return;

  int ds = mTheme->mWindowDropShadowSize, cr = mTheme->mWindowCornerRadius;

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);

  skity::RRect bounds_rrect = skity::RRect::MakeRectXY(
      skity::Rect::MakeXYWH(0, 0, mSize.x(), mSize.y()), cr, cr);

  /* Draw a drop shadow */
  paint.setMaskFilter(skity::MaskFilter::MakeBlur(skity::kOuter, ds));
  paint.setFillColor(mTheme->mDropShadow.toColor());
  canvas->drawRRect(bounds_rrect, paint);

  paint.setMaskFilter(nullptr);
  paint.setFillColor(mTheme->mWindowPopup.toColor());

  /* Draw window */
  canvas->drawRRect(bounds_rrect, paint);

  skity::Path path;
  Vector2i base = Vector2i(0, mAnchorHeight);
  int sign = -1;
  if (mSide == Side::Left) {
    base.x() += mSize.x();
    sign = 1;
  }

  path.moveTo(base.x() + 15 * sign, base.y());
  path.lineTo(base.x() - 1 * sign, base.y() - 15);
  path.lineTo(base.x() - 1 * sign, base.y() + 15);
  path.close();

  canvas->drawPath(path, paint);

  //
  //  nvgMoveTo(ctx, base.x() + 15 * sign, base.y());
  //  nvgLineTo(ctx, base.x() - 1 * sign, base.y() - 15);
  //  nvgLineTo(ctx, base.x() - 1 * sign, base.y() + 15);
  //
  //  nvgFillColor(ctx, mTheme->mWindowPopup);
  //  nvgFill(ctx);
  //  nvgRestore(ctx);
  Widget::draw(canvas);
}

void Popup::save(Serializer &s) const {
  Window::save(s);
  s.set("anchorPos", mAnchorPos);
  s.set("anchorHeight", mAnchorHeight);
  s.set("side", mSide);
}

bool Popup::load(Serializer &s) {
  if (!Window::load(s)) return false;
  if (!s.get("anchorPos", mAnchorPos)) return false;
  if (!s.get("anchorHeight", mAnchorHeight)) return false;
  if (!s.get("side", mSide)) return false;
  return true;
}

NAMESPACE_END(nanogui)
