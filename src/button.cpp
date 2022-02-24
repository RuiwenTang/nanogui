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

#include <utility>

NAMESPACE_BEGIN(nanogui)

Button::Button(Widget *parent, std::string caption, std::string icon)
    : Widget(parent),
      mCaption(std::move(caption)),
      mIconPosition(IconPosition::LeftCentered),
      mPushed(false),
      mFlags(NormalButton),
      mBackgroundColor(Color(0, 0)),
      mTextColor(Color(0, 0)),
      mIconStr(std::move(icon)) {
  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(mFontSize == -1 ? mTheme->mButtonFontSize
                                          : mFontSize);
  mStylePaint.setTypeface(mTheme->mFontBold);

  rebuildCaptionBlob();
  rebuildIconBlob();
}

void Button::setIconStr(const std::string &icon) {
  mIconStr = icon;
  mIconBlob = nullptr;

  rebuildIconBlob();
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

  if (mIconBlob) {
    auto icon_bounds = mIconBlob->getBoundSize();
    ih *= icon_scale();
    iw = icon_bounds.x + mSize.y() * 0.15f;
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

  skity::Rect rect = skity::Rect::MakeXYWH(1, 1, mSize.x() - 2, mSize.y() - 2);

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
    pos[0].x = 0;
    pos[0].y = 0;
    pos[1].x = 0;
    pos[1].y = mSize.y();

    std::array<skity::Color4f, 2> colors{};
    colors[0] = gradTop;
    colors[1] = gradBot;

    mStylePaint.setShader(
        skity::Shader::MakeLinear(pos.data(), colors.data(), nullptr, 2));
  }

  canvas->drawPath(fill_path, mStylePaint);
  mStylePaint.setShader(nullptr);

  mStylePaint.setStrokeWidth(1.f);
  mStylePaint.SetStrokeColor(mTheme->mBorderLight.r(), mTheme->mBorderLight.g(),
                             mTheme->mBorderLight.b(), 1.f);
  mStylePaint.setStyle(skity::Paint::kStroke_Style);
  skity::Path stroke_path;
  stroke_path.addRoundRect(
      skity::Rect::MakeXYWH(0.5f, (mPushed ? 0.5f : 1.5f), mSize.x() - 1,
                            mSize.y() - 1.f - (mPushed ? 0.0f : 1.0f)),
      mTheme->mButtonCornerRadius, mTheme->mButtonCornerRadius);
  canvas->drawPath(stroke_path, mStylePaint);

  float tw = 0.f;
  float descent = 0.f;
  if (mCaptionBlob) {
    auto bounds = mCaptionBlob->getBoundSize();
    tw = bounds.x;
    descent = mCaptionBlob->getBlobDescent();
  }

  Vector2f center = mSize.cast<float>() * 0.5f;

  Vector2f textPos(center.x() - tw * 0.5f, mSize.y() + descent * 0.5f);
  Color textColor = mTextColor.w() == 0 ? mTheme->mTextColor : mTextColor;
  if (!mEnabled) textColor = mTheme->mDisabledTextColor;

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  if (mIconBlob) {
    mStylePaint.setTextSize(getFontSize() * icon_scale());
    auto icon_bounds = mIconBlob->getBoundSize();
    float descent = mIconBlob->getBlobDescent();

    float iw = icon_bounds.x;
    float ih = getFontSize();

    if (!mCaption.empty()) {
      iw += mSize.y() * 0.15f;
    }

    auto iconPos = center;
    iconPos.y() -= 1.f;

    if (mIconPosition == IconPosition::LeftCentered) {
      if (tw != 0.f) {
        iconPos.x() -= (tw * 0.5f + iw);
      } else {
        iconPos.x() -= iw * 0.5f;
      }
      //      textPos.x() += tw * 0.5f;
    } else if (mIconPosition == IconPosition::RightCentered) {
      iconPos.x() -= iw * 0.5f;
      textPos.x() += tw * 0.5f;
    } else if (mIconPosition == IconPosition::Left) {
      iconPos.x() = 8.f;
    } else if (mIconPosition == IconPosition::Right) {
      iconPos.x() = mSize.x() - iw - 8.f;
    }

    mStylePaint.SetFillColor(textColor.toColor());
    mStylePaint.setTypeface(mTheme->mFontIcons);
    canvas->drawTextBlob(mIconBlob.get(), iconPos.x(),
                         iconPos.y() - descent * 0.5f, mStylePaint);
  }

  if (!mCaptionBlob) {
    return;
  }

  mStylePaint.setTextSize(getFontSize());
  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.SetFillColor(mTheme->mTextColorShadow.toColor());

  canvas->drawTextBlob(mCaptionBlob.get(), textPos.x(), textPos.y(),
                       mStylePaint);
  mStylePaint.SetFillColor(textColor.toColor());
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

void Button::rebuildIconBlob() {
  if (mIconBlob != nullptr) {
    return;
  }

  if (!mIconStr.empty()) {
    mStylePaint.setTextSize(getFontSize() * icon_scale());
    mStylePaint.setTypeface(mTheme->mFontIcons);
    mIconBlob = mTextBlobBuilder.buildTextBlob(mIconStr.c_str(), mStylePaint);
  }
}

void Button::save(Serializer &s) const {
  Widget::save(s);
  s.set("caption", mCaption);
  s.set("iconStr", mIconStr);
  s.set("iconPosition", (int)mIconPosition);
  s.set("pushed", mPushed);
  s.set("flags", mFlags);
  s.set("backgroundColor", mBackgroundColor);
  s.set("textColor", mTextColor);
}

bool Button::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("caption", mCaption)) return false;
  if (!s.get("iconStr", mIconStr)) return false;
  if (!s.get("iconPosition", mIconPosition)) return false;
  if (!s.get("pushed", mPushed)) return false;
  if (!s.get("flags", mFlags)) return false;
  if (!s.get("backgroundColor", mBackgroundColor)) return false;
  if (!s.get("textColor", mTextColor)) return false;
  return true;
}

NAMESPACE_END(nanogui)
