/*
    src/popupbutton.cpp -- Button which launches a popup widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/popupbutton.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

PopupButton::PopupButton(Widget *parent, const std::string &caption,
                         const std::string &buttonIcon)
    : Button(parent, caption, buttonIcon) {
  mChevronIcon = mTheme->mPopupChevronRightIcon;

  setFlags(Flags::ToggleButton | Flags::PopupButton);

  Window *parentWindow = window();
  mPopup = new Popup(parentWindow->parent(), window());
  mPopup->setSize(Vector2i(320, 250));
  mPopup->setVisible(false);

  mIconExtraScale = 0.8f;  // widget override

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(getFontSize());
  mStylePaint.setTypeface(mTheme->mFontIcons);

  rebuildChevronBlob();
}

void PopupButton::setChevronIcon(const std::string &icon) {
  mChevronIcon = icon;

  mChevronBlob = nullptr;

  rebuildChevronBlob();
}

PopupButton::~PopupButton() { mPopup->setVisible(false); }

Vector2i PopupButton::preferredSize() const {
  return Button::preferredSize() + Vector2i(15, 0);
}

void PopupButton::draw(skity::Canvas *canvas) {
  if (!mEnabled && mPushed) mPushed = false;

  mPopup->setVisible(mPushed);
  Button::draw(canvas);

  if (mChevronBlob) {
    auto color = mTextColor.w() == 0 ? mTheme->mTextColor : mTextColor;

    mStylePaint.setFillColor(mEnabled ? color.toColor()
                                      : mTheme->mDisabledTextColor.toColor());

    float descent = mChevronBlob->getBlobDescent();
    auto chevron_bounds = mChevronBlob->getBoundSize();
    float iw = chevron_bounds.x;
    Vector2f iconPos(0,  mSize.y() + descent * 0.5f);

    if (mPopup->side() == Popup::Right)
      iconPos[0] = mSize.x() - iw;
    else
      iconPos[0] = 8;

    canvas->drawTextBlob(mChevronBlob.get(), iconPos.x(), iconPos.y(), mStylePaint);
  }
}

void PopupButton::performLayout() {
  Widget::performLayout();

  const Window *parentWindow = window();

  int posY =
      absolutePosition().y() - parentWindow->position().y() + mSize.y() / 2;
  if (mPopup->side() == Popup::Right)
    mPopup->setAnchorPos(Vector2i(parentWindow->width() + 15, posY));
  else
    mPopup->setAnchorPos(Vector2i(0 - 15, posY));
}

void PopupButton::setSide(Popup::Side side) {
  if (mPopup->side() == Popup::Right &&
      mChevronIcon == mTheme->mPopupChevronRightIcon)
    setChevronIcon(mTheme->mPopupChevronLeftIcon);
  else if (mPopup->side() == Popup::Left &&
           mChevronIcon == mTheme->mPopupChevronLeftIcon)
    setChevronIcon(mTheme->mPopupChevronRightIcon);
  mPopup->setSide(side);
}

void PopupButton::save(Serializer &s) const {
  Button::save(s);
  s.set("chevronIcon", mChevronIcon);
}

bool PopupButton::load(Serializer &s) {
  if (!Button::load(s)) return false;
  if (!s.get("chevronIcon", mChevronIcon)) return false;
  return true;
}

void PopupButton::rebuildChevronBlob() {
  if (mChevronIcon.empty()) {
    return;
  }

  if (mChevronBlob) {
    return;
  }

  mChevronBlob =
      skity::TextBlobBuilder{}.buildTextBlob(mChevronIcon.c_str(), mStylePaint);
}

NAMESPACE_END(nanogui)
