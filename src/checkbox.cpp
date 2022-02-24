/*
    src/checkbox.cpp -- Two-state check box widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/checkbox.h>
#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

CheckBox::CheckBox(Widget *parent, const std::string &caption,
                   const std::function<void(bool)> &callback)
    : Widget(parent),
      mCaption(caption),
      mPushed(false),
      mChecked(false),
      mCallback(callback) {
  mIconExtraScale = 1.2f;  // widget override

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTextSize(fontSize());
  mStylePaint.setTypeface(mTheme->mFontNormal);

  mIconPaint.setStyle(skity::Paint::kFill_Style);
  mIconPaint.setTextSize(fontSize() * icon_scale());
  mIconPaint.setTypeface(mTheme->mFontIcons);

  rebuildCaptionBlob();

  mIconBlob =
      blobBuilder.buildTextBlob(mTheme->mCheckBoxIcon.c_str(), mIconPaint);
}

bool CheckBox::mouseButtonEvent(const Vector2i &p, int button, bool down,
                                int modifiers) {
  Widget::mouseButtonEvent(p, button, down, modifiers);
  if (!mEnabled) return false;

  if (button == GLFW_MOUSE_BUTTON_1) {
    if (down) {
      mPushed = true;
    } else if (mPushed) {
      if (contains(p)) {
        mChecked = !mChecked;
        if (mCallback) mCallback(mChecked);
      }
      mPushed = false;
    }
    return true;
  }
  return false;
}

Vector2i CheckBox::preferredSize() const {
  if (mFixedSize != Vector2i::Zero()) return mFixedSize;

  Vector2i bound_size{};
  if (mCaptionBlob) {
    auto blob_size = mCaptionBlob->getBoundSize();
    bound_size.x() = blob_size.x;
    bound_size.y() = blob_size.y;
  }

  return {bound_size.x() + 1.8f * fontSize(), fontSize() * 1.3f};
}

void CheckBox::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);

  if (mCaptionBlob == nullptr) {
    return;
  }

  float descent = mCaptionBlob->getBlobDescent();
  mStylePaint.setFillColor(mEnabled ? mTheme->mTextColor.toColor()
                                    : mTheme->mDisabledTextColor.toColor());

  canvas->drawTextBlob(mCaptionBlob.get(), 1.6f * fontSize(),
                       mSize.y() + descent * 0.5f * 0.8f, mStylePaint);

  skity::Paint paint;
  paint.setStyle(skity::Paint::kFill_Style);
  {
    std::array<skity::Point, 2> pts{};
    std::array<skity::Color4f, 2> colors{};

    pts[0].x = 1.5f;
    pts[0].y = 1.5f;
    pts[1].x = mSize.y() - 2.0f;
    pts[1].y = mSize.y() - 2.0f;

    colors[0] = mPushed ? Color{0, 100}.toColor() : Color{0, 32}.toColor();
    colors[1] = Color{0, 0, 0, 180}.toColor();

    paint.setShader(
        skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));
  }
  skity::Rect rect =
      skity::Rect::MakeXYWH(1.f, 1.f, mSize.y() - 2.f, mSize.y() - 2.f);

  canvas->drawRoundRect(rect, 3, 3, paint);

  if (mChecked && mIconBlob) {
    mIconPaint.setFillColor(mEnabled ? mTheme->mIconColor.toColor()
                                     : mTheme->mDisabledTextColor.toColor());

    float icon_descent = mIconBlob->getBlobDescent();
    canvas->drawTextBlob(mIconBlob.get(), 2, mSize.y() + icon_descent * 0.5f,
                         mIconPaint);
    //    nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
    //    nvgText(ctx, mPos.x() + mSize.y() * 0.5f + 1, mPos.y() + mSize.y() *
    //    0.5f,
    //            utf8(mTheme->mCheckBoxIcon).data(), nullptr);
  }
}

void CheckBox::save(Serializer &s) const {
  Widget::save(s);
  s.set("caption", mCaption);
  s.set("pushed", mPushed);
  s.set("checked", mChecked);
}

bool CheckBox::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("caption", mCaption)) return false;
  if (!s.get("pushed", mPushed)) return false;
  if (!s.get("checked", mChecked)) return false;
  return true;
}

void CheckBox::rebuildCaptionBlob() {
  if (mCaption.empty()) {
    return;
  }

  if (mCaptionBlob) {
    return;
  }

  mCaptionBlob = blobBuilder.buildTextBlob(mCaption.c_str(), mStylePaint);
}

NAMESPACE_END(nanogui)
