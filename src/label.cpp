/*
    src/label.cpp -- Text label with an arbitrary font, color, and size

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/label.h>
#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

Label::Label(Widget *parent, const std::string &caption,
             const std::string &font, int fontSize)
    : Widget(parent), mCaption(caption), mFont(font) {
  if (mTheme) {
    mFontSize = mTheme->mStandardFontSize;
    mColor = mTheme->mTextColor;
  }
  if (fontSize >= 0) mFontSize = fontSize;

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(mFontSize);
  mStylePaint.setFillColor(mColor.toColor());
  if (mFont == "sans-bold") {
    mStylePaint.setTypeface(mTheme->mFontBold);
  } else if (mFont == "icons") {
    mStylePaint.setTypeface(mTheme->mFontIcons);
  } else {
    mStylePaint.setTypeface(mTheme->mFontNormal);
  }

  rebuildCaptionBlob();
}

void Label::setCaption(const std::string &caption) {
  mCaption = caption;
  mCaptionBlob = nullptr;

  rebuildCaptionBlob();
}

void Label::setTheme(Theme *theme) {
  Widget::setTheme(theme);
  if (mTheme) {
    mFontSize = mTheme->mStandardFontSize;
    mColor = mTheme->mTextColor;
  }

  mStylePaint.setTextSize(mFontSize);
  mStylePaint.setFillColor(mColor.toColor());

  mCaptionBlob = nullptr;
  rebuildCaptionBlob();
}

Vector2i Label::preferredSize() const {
  if (mCaption == "") return Vector2i::Zero();

  auto bounds = mCaptionBlob->getBoundSize();

  if (mFixedSize.x() > 0) {
    return Vector2i(mFixedSize.x(), bounds.y);
  } else {
    return Vector2i(bounds.x + 2, fontSize());
  }
}

void Label::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);
  if (mCaptionBlob == nullptr) {
    return;
  }
  float ascent = mCaptionBlob->getBlobAscent();
  // TODO handle line break
  canvas->drawTextBlob(mCaptionBlob.get(), 0, ascent, mStylePaint);
}

void Label::rebuildCaptionBlob() {
  if (mCaption.empty()) {
    return;
  }

  mCaptionBlob = mBlobBuilder.buildTextBlob(mCaption.c_str(), mStylePaint);
}

void Label::save(Serializer &s) const {
  Widget::save(s);
  s.set("caption", mCaption);
  s.set("font", mFont);
  s.set("color", mColor);
}

bool Label::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("caption", mCaption)) return false;
  if (!s.get("font", mFont)) return false;
  if (!s.get("color", mColor)) return false;
  return true;
}

void Label::onSetFontSize() {
  if (mCaption.empty()) {
    return;
  }

  if (mFontSize == mStylePaint.getTextSize()) {
    return;
  }

  mStylePaint.setTextSize(mFontSize);
  mCaptionBlob = nullptr;

  rebuildCaptionBlob();
}

NAMESPACE_END(nanogui)
