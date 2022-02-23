/*
    src/button.cpp -- [Normal/Toggle/Radio/Popup] Button widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/button.h>
#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

Button::Button(Widget *parent, const std::string &caption, int icon)
    : Widget(parent),
      mCaption(caption),
      mIcon(icon),
      mIconPosition(IconPosition::LeftCentered),
      mPushed(false),
      mFlags(NormalButton),
      mBackgroundColor(Color(0, 0)),
      mTextColor(Color(0, 0)) {
  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(mFontSize == -1 ? mTheme->mButtonFontSize
                                          : mFontSize);
  mStylePaint.setTypeface(mTheme->mFontBold);
}

void Button::setCaption(const std::string &caption) {
  mCaption = caption;
  mCaptionBlob = nullptr;

  rebuildCaptionBlob();
}

Vector2i Button::preferredSize() const {
  if (mCaptionBlob == nullptr) {
    return Vector2i{0, 0};
  }

  auto bounds = mCaptionBlob->getBoundSize();
  int fontSize = getFontSize();
  float tw = bounds.x;
  float iw = 0.0f, ih = fontSize;

  if (mIcon) {
    // if (nvgIsFontIcon(mIcon)) {
    //   ih *= icon_scale();
    //   nvgFontFace(ctx, "icons");
    //   nvgFontSize(ctx, ih);
    //   iw = nvgTextBounds(ctx, 0, 0, utf8(mIcon).data(), nullptr, nullptr) +
    //        mSize.y() * 0.15f;
    // } else {
    //   int w, h;
    //   ih *= 0.9f;
    //   nvgImageSize(ctx, mIcon, &w, &h);
    //   iw = w * ih / h;
    // }
  }
  return Vector2i((int)(tw + iw) + 20, fontSize + 10);
}

bool Button::mouseButtonEvent(const Vector2i &p, int button, bool down,
                              int modifiers) {
  Widget::mouseButtonEvent(p, button, down, modifiers);
  /* Temporarily increase the reference count of the button in case the
     button causes the parent window to be destructed */
  ref<Button> self = this;

  if (button == GLFW_MOUSE_BUTTON_1 && mEnabled) {
    bool pushedBackup = mPushed;
    if (down) {
      if (mFlags & RadioButton) {
        if (mButtonGroup.empty()) {
          for (auto widget : parent()->children()) {
            Button *b = dynamic_cast<Button *>(widget);
            if (b != this && b && (b->flags() & RadioButton) && b->mPushed) {
              b->mPushed = false;
              if (b->mChangeCallback) b->mChangeCallback(false);
            }
          }
        } else {
          for (auto b : mButtonGroup) {
            if (b != this && (b->flags() & RadioButton) && b->mPushed) {
              b->mPushed = false;
              if (b->mChangeCallback) b->mChangeCallback(false);
            }
          }
        }
      }
      if (mFlags & PopupButton) {
        for (auto widget : parent()->children()) {
          Button *b = dynamic_cast<Button *>(widget);
          if (b != this && b && (b->flags() & PopupButton) && b->mPushed) {
            b->mPushed = false;
            if (b->mChangeCallback) b->mChangeCallback(false);
          }
        }
      }
      if (mFlags & ToggleButton)
        mPushed = !mPushed;
      else
        mPushed = true;
    } else if (mPushed) {
      if (contains(p) && mCallback) mCallback();
      if (mFlags & NormalButton) mPushed = false;
    }
    if (pushedBackup != mPushed && mChangeCallback) mChangeCallback(mPushed);

    return true;
  }
  return false;
}

void Button::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);

  skity::Color4f gradTop = mTheme->mButtonGradientTopUnfocused.toColor();
  skity::Color4f gradBot = mTheme->mButtonGradientBotUnfocused.toColor();

  if (mPushed) {
    gradTop = mTheme->mButtonGradientTopPushed.toColor();
    gradBot = mTheme->mButtonGradientBotPushed.toColor();
  } else if (mMouseFocus && mEnabled) {
    gradTop = mTheme->mButtonGradientTopFocused.toColor();
    gradBot = mTheme->mButtonGradientBotFocused.toColor();
  }

  skity::Rect rect = skity::Rect::MakeXYWH(mPos.x() + 1, mPos.y() + 1,
                                           mSize.x() - 2, mSize.y() - 2);

  skity::Path fill_path;
  fill_path.addRoundRect(rect, mTheme->mButtonCornerRadius - 1,
                         mTheme->mButtonCornerRadius - 1);

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  if (mBackgroundColor.w() != 0) {
    // nvgFillColor(ctx, Color(mBackgroundColor.head<3>(), 1.f));
    mStylePaint.SetFillColor(mBackgroundColor.r(), mBackgroundColor.g(),
                             mBackgroundColor.b(), mBackgroundColor.w());

    canvas->drawPath(fill_path, mStylePaint);

    if (mPushed) {
      gradTop.a = gradBot.a = 0.8f;
    } else {
      double v = 1 - mBackgroundColor.w();
      gradTop.a = gradBot.a = mEnabled ? v : v * .5f + .5f;
    }
  }

  {
    std::array<skity::Point, 2> pos{};
    pos[0].x = mPos.x();
    pos[0].y = mPos.y();
    pos[1].x = mPos.x();
    pos[1].y = mPos.x() + mSize.y();

    std::array<skity::Color4f, 2> colors{};
    colors[0] = gradTop;
    colors[1] = gradBot;

    mStylePaint.setShader(
        skity::Shader::MakeLinear(pos.data(), colors.data(), nullptr, 2));
  }

  canvas->drawPath(fill_path, mStylePaint);

  mStylePaint.setStrokeWidth(1.f);
  mStylePaint.SetStrokeColor(mTheme->mBorderLight.r(), mTheme->mBorderLight.g(),
                             mTheme->mBorderLight.b(), 1.f);
  mStylePaint.setStyle(skity::Paint::kStroke_Style);
  skity::Path stroke_path;
  stroke_path.addRoundRect(
      skity::Rect::MakeXYWH(mPos.x() + 0.5f,
                            mPos.y() + +(mPushed ? 0.5f : 1.5f), mSize.x() - 1,
                            mSize.y() - 1.f - (mPushed ? 0.0f : 1.0f)),
      mTheme->mButtonCornerRadius, mTheme->mButtonCornerRadius);
  canvas->drawPath(stroke_path, mStylePaint);

  int fontSize = mFontSize == -1 ? mTheme->mButtonFontSize : mFontSize;

  auto bounds = mCaptionBlob->getBoundSize();
  float tw = bounds.x;

  Vector2f center = mPos.cast<float>() + mSize.cast<float>() * 0.5f;
  Vector2f textPos(center.x() - tw * 0.5f, center.y() - 1);
  Color textColor = mTextColor.w() == 0 ? mTheme->mTextColor : mTextColor;
  if (!mEnabled) textColor = mTheme->mDisabledTextColor;

  // if (mIcon) {
  //   auto icon = utf8(mIcon);

  //   float iw, ih = fontSize;
  //   if (nvgIsFontIcon(mIcon)) {
  //     ih *= icon_scale();
  //     nvgFontSize(ctx, ih);
  //     nvgFontFace(ctx, "icons");
  //     iw = nvgTextBounds(ctx, 0, 0, icon.data(), nullptr, nullptr);
  //   } else {
  //     int w, h;
  //     ih *= 0.9f;
  //     nvgImageSize(ctx, mIcon, &w, &h);
  //     iw = w * ih / h;
  //   }
  //   if (mCaption != "") iw += mSize.y() * 0.15f;
  //   nvgFillColor(ctx, textColor);
  //   nvgTextAlign(ctx, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
  //   Vector2f iconPos = center;
  //   iconPos.y() -= 1;

  //   if (mIconPosition == IconPosition::LeftCentered) {
  //     iconPos.x() -= (tw + iw) * 0.5f;
  //     textPos.x() += iw * 0.5f;
  //   } else if (mIconPosition == IconPosition::RightCentered) {
  //     textPos.x() -= iw * 0.5f;
  //     iconPos.x() += tw * 0.5f;
  //   } else if (mIconPosition == IconPosition::Left) {
  //     iconPos.x() = mPos.x() + 8;
  //   } else if (mIconPosition == IconPosition::Right) {
  //     iconPos.x() = mPos.x() + mSize.x() - iw - 8;
  //   }

  //   if (nvgIsFontIcon(mIcon)) {
  //     nvgText(ctx, iconPos.x(), iconPos.y() + 1, icon.data(), nullptr);
  //   } else {
  //     NVGpaint imgPaint =
  //         nvgImagePattern(ctx, iconPos.x(), iconPos.y() - ih / 2, iw, ih, 0,
  //                         mIcon, mEnabled ? 0.5f : 0.25f);

  //     nvgFillPaint(ctx, imgPaint);
  //     nvgFill(ctx);
  //   }
  // }

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(getFontSize());
  mStylePaint.SetFillColor(mTheme->mTextColorShadow.r(),
                           mTheme->mTextColorShadow.g(),
                           mTheme->mTextColorShadow.b(), 1.f);
  canvas->drawTextBlob(mCaptionBlob.get(), textPos.x(), textPos.y(),
                       mStylePaint);
  mStylePaint.SetFillColor(textColor.r(), textColor.g(), textColor.b(), 1.f);
  canvas->drawTextBlob(mCaptionBlob.get(), textPos.x(), textPos.y() + 1.f,
                       mStylePaint);
}

int Button::getFontSize() const {
  return mFontSize == -1 ? mTheme->mButtonFontSize : mFontSize;
}

void Button::rebuildCaptionBlob() {
  if (mCaptionBlob != nullptr) {
    return;
  }

  if (!mCaption.empty()) {
    mStylePaint.setTextSize(getFontSize());
    mStylePaint.setTypeface(mTheme->mFontBold);
    mCaptionBlob =
        mTextBlobBuilder.buildTextBlob(mCaption.c_str(), mStylePaint);
  }
}

void Button::save(Serializer &s) const {
  Widget::save(s);
  s.set("caption", mCaption);
  s.set("icon", mIcon);
  s.set("iconPosition", (int)mIconPosition);
  s.set("pushed", mPushed);
  s.set("flags", mFlags);
  s.set("backgroundColor", mBackgroundColor);
  s.set("textColor", mTextColor);
}

bool Button::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("caption", mCaption)) return false;
  if (!s.get("icon", mIcon)) return false;
  if (!s.get("iconPosition", mIconPosition)) return false;
  if (!s.get("pushed", mPushed)) return false;
  if (!s.get("flags", mFlags)) return false;
  if (!s.get("backgroundColor", mBackgroundColor)) return false;
  if (!s.get("textColor", mTextColor)) return false;
  return true;
}

NAMESPACE_END(nanogui)
