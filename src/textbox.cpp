/*
    src/textbox.cpp -- Fancy text box with builtin regular
    expression-based validation

    The text box widget was contributed by Christian Schueller.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/screen.h>
#include <nanogui/serializer/core.h>
#include <nanogui/textbox.h>
#include <nanogui/theme.h>
#include <nanogui/window.h>

#include <iostream>
#include <regex>

NAMESPACE_BEGIN(nanogui)

TextBox::TextBox(Widget *parent, const std::string &value)
    : Widget(parent),
      mEditable(false),
      mSpinnable(false),
      mCommitted(true),
      mValue(value),
      mDefaultValue(""),
      mAlignment(Alignment::Center),
      mUnits(""),
      mFormat(""),
      mUnitsImage(),
      mValidFormat(true),
      mValueTemp(value),
      mCursorPos(-1),
      mSelectionPos(-1),
      mMousePos(Vector2i(-1, -1)),
      mMouseDownPos(Vector2i(-1, -1)),
      mMouseDragPos(Vector2i(-1, -1)),
      mMouseDownModifier(0),
      mTextOffset(0),
      mLastClick(0) {
  if (mTheme) mFontSize = mTheme->mTextBoxFontSize;
  mIconExtraScale = 0.8f;  // widget override
  mStylePaint.setTextSize(mFontSize);
  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTypeface(mTheme->mFontNormal);
}

void TextBox::setEditable(bool editable) {
  mEditable = editable;
  setCursor(editable ? Cursor::IBeam : Cursor::Arrow);
}

void TextBox::setValue(const std::string &value) {
  mValue = value;

  mValueBlob =
      skity::TextBlobBuilder{}.buildTextBlob(mValue.c_str(), mStylePaint);
}

void TextBox::setTheme(Theme *theme) {
  Widget::setTheme(theme);
  if (mTheme) mFontSize = mTheme->mTextBoxFontSize;
}

Vector2i TextBox::preferredSize() const {
  Vector2i size(0, fontSize() * 1.4f);

  float uw = 0;
  if (mUnitsImage > 0) {
    int w, h;
    w = mUnitsImage->Width();
    h = mUnitsImage->Height();
    float uh = size(1) * 0.4f;
    uw = w * uh / h;
  } else if (!mUnits.empty()) {
    if (mUnitsBlob == nullptr) {
      mUnitsBlob =
          skity::TextBlobBuilder().buildTextBlob(mUnits.c_str(), mStylePaint);
    }

    auto us = mUnitsBlob->getBoundSize();
    uw = us.x;
  }
  float sw = 0;
  if (mSpinnable) {
    sw = 14.f;
  }

  if (mValueBlob == nullptr) {
    mValueBlob =
        skity::TextBlobBuilder().buildTextBlob(mValue.c_str(), mStylePaint);
  }

  auto vs = mValueBlob->getBoundSize();
  float ts = vs.x;

  size(0) = size(1) + ts + uw + sw;
  return size;
}

void TextBox::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);

  skity::Paint bg;
  bg.setStyle(skity::Paint::kFill_Style);
  skity::Paint fg1;
  fg1.setStyle(skity::Paint::kFill_Style);
  skity::Paint fg2;
  fg2.setStyle(skity::Paint::kFill_Style);

  std::array<skity::Point, 2> pts{};
  std::array<skity::Color4f, 2> colors{};

  pts[0].x = 1;
  pts[0].y = 1 + 1.f;
  pts[1].x = mSize.x() - 2;
  pts[1].y = mSize.y() - 2;
  colors[0] = Color{255, 32}.toColor();
  colors[1] = Color{32, 32}.toColor();

  bg.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  colors[0] = Color{150, 32}.toColor();
  colors[1] = Color{32, 32}.toColor();

  fg1.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  colors[0] = Color(255, 0, 0, 100).toColor();
  colors[1] = Color(255, 0, 0, 50).toColor();

  fg2.setShader(
      skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

  skity::Rect rect =
      skity::Rect::MakeXYWH(1, 1 + 1.f, mSize.x() - 2, mSize.y() - 2);

  skity::Paint *fill_paint = nullptr;
  if (mEditable && focused()) {
    if (mValidFormat) {
      fill_paint = &fg1;
    } else {
      fill_paint = &fg2;
    }
  } else if (mSpinnable && mMouseDownPos.x() != -1) {
    fill_paint = &fg1;
  } else {
    fill_paint = &bg;
  }

  canvas->drawRoundRect(rect, 3, 3, *fill_paint);

  rect = skity::Rect::MakeXYWH(0.5f, 0.5f, mSize.x() - 1, mSize.y() - 1);

  skity::Paint paint;
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  paint.setStrokeColor(Color{0, 48}.toColor());

  canvas->drawRoundRect(rect, 2.5f, 2.5f, paint);

  Vector2i drawPos(0, mSize.y());

  float xSpacing = mSize.y() * 0.1f;

  float unitWidth = 0;
  if (mUnitsBlob) {
    auto unit_bounds = mUnitsBlob->getBoundSize();
    unitWidth = unit_bounds.x;

    float offset = mSize.y() - unit_bounds.y;

    mStylePaint.setFillColor(Color{255, mEnabled ? 64 : 32}.toColor());
    canvas->drawTextBlob(mUnitsBlob.get(), mSize.x() - xSpacing - unitWidth,
                         drawPos.y() + offset, mStylePaint);
  }

  float spinArrowsWidth = 0.f;

  if (mSpinnable && !focused()) {
    spinArrowsWidth = 14.f;

    mStylePaint.setTypeface(mTheme->mFontIcons);
    mStylePaint.setTextSize(
        ((mFontSize < 0) ? mTheme->mButtonFontSize : mFontSize) * icon_scale());

    bool spinning = mMouseDownPos.x() != -1;

    /* up button */ {
      bool hover = mMouseFocus && spinArea(mMousePos) == SpinArea::Top;
      mStylePaint.setFillColor((mEnabled && (hover || spinning))
                                   ? mTheme->mTextColor.toColor()
                                   : mTheme->mDisabledTextColor.toColor());

      if (mIconUpBlob == nullptr) {
        mIconUpBlob = skity::TextBlobBuilder{}.buildTextBlob(
            mTheme->mTextBoxUpIcon.c_str(), mStylePaint);
      }

      Vector2f iconPos(4.f, mSize.y() / 2.f - xSpacing / 2.f);
      canvas->drawTextBlob(mIconUpBlob.get(), iconPos.x(), iconPos.y(),
                           mStylePaint);
    }

    /* down button */ {
      bool hover = mMouseFocus && spinArea(mMousePos) == SpinArea::Bottom;

      mStylePaint.setFillColor((mEnabled && (hover || spinning))
                                   ? mTheme->mTextColor.toColor()
                                   : mTheme->mDisabledTextColor.toColor());

      if (mIconDownBlob == nullptr) {
        mIconDownBlob = skity::TextBlobBuilder{}.buildTextBlob(
            mTheme->mTextBoxDownIcon.c_str(), mStylePaint);
      }
      Vector2f iconPos(4.f, mSize.y() / 2.f + xSpacing / 2.f + 1.5f);
      canvas->drawTextBlob(mIconDownBlob.get(), iconPos.x(), iconPos.y(),
                           mStylePaint);
    }

    mStylePaint.setTypeface(mTheme->mFontNormal);
    mStylePaint.setTextSize(fontSize());
  }

  mStylePaint.setFillColor(mEnabled && (!mCommitted || !mValue.empty())
                               ? mTheme->mTextColor.toColor()
                               : mTheme->mDisabledTextColor.toColor());

  // clip visible text area
  float clipX = xSpacing + spinArrowsWidth - 1.0f;
  float clipY = 1.0f;
  float clipWidth =
      mSize.x() - unitWidth - spinArrowsWidth - 2 * xSpacing + 2.0f;
  float clipHeight = mSize.y() - 3.0f;

  canvas->save();

  canvas->clipRect(skity::Rect::MakeXYWH(clipX, clipY, clipWidth, clipHeight));

  Vector2i oldDrawPos(drawPos);
  drawPos.x() += mTextOffset;

  if (mCommitted) {
    if (mValueBlob != nullptr) {
      auto value_bounds = mValueBlob->getBoundSize();

      switch (mAlignment) {
        case Alignment::Right:
          drawPos.x() = mSize.x() - value_bounds.x - unitWidth;
          break;
        case Alignment::Center:
          drawPos.x() = (mSize.x() - value_bounds.x - unitWidth) * 0.5f;
          break;
        default:
          break;
      }

      float offset = (mSize.y() - value_bounds.y);
      canvas->drawTextBlob(mValueBlob.get(), drawPos.x(), drawPos.y() + offset,
                           mStylePaint);
    }
  } else {
    std::vector<skity::GlyphInfo> glyphs{};

    float lineh = 0.f;
    if (mValueBlob) {
      for (auto &run : mValueBlob->getTextRun()) {
        glyphs.insert(glyphs.end(), run.getGlyphInfo().begin(),
                      run.getGlyphInfo().end());
      }

      auto bounds = mValueBlob->getBoundSize();
      lineh = bounds.y;
    }
    float lastX = 0.f;
    for (auto &glyphInfo : glyphs) {
      lastX += glyphInfo.advance_x;
    }
    updateCursor(lastX, glyphs);

    // compute text offset
    int prevCPos = mCursorPos > 0 ? mCursorPos - 1 : 0;
    int nextCPos = mCursorPos < glyphs.size() ? mCursorPos + 1 : glyphs.size();
    float prevCX = cursorIndex2Position(prevCPos, lastX, glyphs);
    float nextCX = cursorIndex2Position(nextCPos, lastX, glyphs);

    if (nextCX > clipX + clipWidth)
      mTextOffset -= nextCX - (clipX + clipWidth) + 1;
    if (prevCX < clipX) mTextOffset += clipX - prevCX + 1;

    drawPos.x() = oldDrawPos.x() + mTextOffset;

    if (mCursorPos > -1) {
      if (mSelectionPos > -1) {
        float caretx = cursorIndex2Position(mCursorPos, lastX, glyphs);
        float selx = cursorIndex2Position(mSelectionPos, lastX, glyphs);

        if (caretx > selx) std::swap(caretx, selx);

        // draw selection
        skity::Paint paint;
        paint.setStyle(skity::Paint::kFill_Style);
        paint.setColor(skity::ColorSetARGB(80, 255, 255, 255));

        canvas->drawRect(
            skity::Rect::MakeXYWH(caretx, drawPos.y() - lineh * 0.5f,
                                  selx - caretx, lineh),
            paint);
      }

      float caretx = cursorIndex2Position(mCursorPos, lineh, glyphs);

      // draw cursor
      skity::Path path;
      path.moveTo(caretx, drawPos.y() - lineh * 0.5f);
      path.lineTo(caretx, drawPos.y() + lineh * 0.5f);

      paint.setStyle(skity::Paint::kStroke_Style);
      paint.setColor(skity::ColorSetARGB(255, 255, 192, 0));
      paint.setStrokeWidth(1.f);

      canvas->drawPath(path, paint);
    }
  }
  canvas->restore();
}

bool TextBox::mouseButtonEvent(const Vector2i &p, int button, bool down,
                               int modifiers) {
  if (button == GLFW_MOUSE_BUTTON_1 && down && !mFocused) {
    if (!mSpinnable ||
        spinArea(p) == SpinArea::None) /* not on scrolling arrows */
      requestFocus();
  }

  if (mEditable && focused()) {
    if (down) {
      mMouseDownPos = p;
      mMouseDownModifier = modifiers;

      double time = glfwGetTime();
      if (time - mLastClick < 0.25) {
        /* Double-click: select all text */
        mSelectionPos = 0;
        mCursorPos = (int)mValueTemp.size();
        mMouseDownPos = Vector2i(-1, -1);
      }
      mLastClick = time;
    } else {
      mMouseDownPos = Vector2i(-1, -1);
      mMouseDragPos = Vector2i(-1, -1);
    }
    return true;
  } else if (mSpinnable && !focused()) {
    if (down) {
      if (spinArea(p) == SpinArea::None) {
        mMouseDownPos = p;
        mMouseDownModifier = modifiers;

        double time = glfwGetTime();
        if (time - mLastClick < 0.25) {
          /* Double-click: reset to default value */
          mValue = mDefaultValue;
          if (mCallback) mCallback(mValue);

          mMouseDownPos = Vector2i(-1, -1);
        }
        mLastClick = time;
      } else {
        mMouseDownPos = Vector2i(-1, -1);
        mMouseDragPos = Vector2i(-1, -1);
      }
    } else {
      mMouseDownPos = Vector2i(-1, -1);
      mMouseDragPos = Vector2i(-1, -1);
    }
    return true;
  }

  return false;
}

bool TextBox::mouseMotionEvent(const Vector2i &p, const Vector2i & /* rel */,
                               int /* button */, int /* modifiers */) {
  mMousePos = p;

  if (!mEditable)
    setCursor(Cursor::Arrow);
  else if (mSpinnable && !focused() &&
           spinArea(mMousePos) != SpinArea::None) /* scrolling arrows */
    setCursor(Cursor::Hand);
  else
    setCursor(Cursor::IBeam);

  if (mEditable && focused()) {
    return true;
  }
  return false;
}

bool TextBox::mouseDragEvent(const Vector2i &p, const Vector2i & /* rel */,
                             int /* button */, int /* modifiers */) {
  mMousePos = p;
  mMouseDragPos = p;

  if (mEditable && focused()) {
    return true;
  }
  return false;
}

bool TextBox::focusEvent(bool focused) {
  Widget::focusEvent(focused);

  std::string backup = mValue;

  if (mEditable) {
    if (focused) {
      mValueTemp = mValue;
      mCommitted = false;
      mCursorPos = 0;
    } else {
      if (mValidFormat) {
        if (mValueTemp == "")
          mValue = mDefaultValue;
        else
          mValue = mValueTemp;
      }

      if (mCallback && !mCallback(mValue)) mValue = backup;

      mValidFormat = true;
      mCommitted = true;
      mCursorPos = -1;
      mSelectionPos = -1;
      mTextOffset = 0;
    }

    mValidFormat = (mValueTemp == "") || checkFormat(mValueTemp, mFormat);
  }

  return true;
}

bool TextBox::keyboardEvent(int key, int /* scancode */, int action,
                            int modifiers) {
  if (mEditable && focused()) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
      if (key == GLFW_KEY_LEFT) {
        if (modifiers == GLFW_MOD_SHIFT) {
          if (mSelectionPos == -1) mSelectionPos = mCursorPos;
        } else {
          mSelectionPos = -1;
        }

        if (mCursorPos > 0) mCursorPos--;
      } else if (key == GLFW_KEY_RIGHT) {
        if (modifiers == GLFW_MOD_SHIFT) {
          if (mSelectionPos == -1) mSelectionPos = mCursorPos;
        } else {
          mSelectionPos = -1;
        }

        if (mCursorPos < (int)mValueTemp.length()) mCursorPos++;
      } else if (key == GLFW_KEY_HOME) {
        if (modifiers == GLFW_MOD_SHIFT) {
          if (mSelectionPos == -1) mSelectionPos = mCursorPos;
        } else {
          mSelectionPos = -1;
        }

        mCursorPos = 0;
      } else if (key == GLFW_KEY_END) {
        if (modifiers == GLFW_MOD_SHIFT) {
          if (mSelectionPos == -1) mSelectionPos = mCursorPos;
        } else {
          mSelectionPos = -1;
        }

        mCursorPos = (int)mValueTemp.size();
      } else if (key == GLFW_KEY_BACKSPACE) {
        if (!deleteSelection()) {
          if (mCursorPos > 0) {
            mValueTemp.erase(mValueTemp.begin() + mCursorPos - 1);
            mCursorPos--;
          }
        }
      } else if (key == GLFW_KEY_DELETE) {
        if (!deleteSelection()) {
          if (mCursorPos < (int)mValueTemp.length())
            mValueTemp.erase(mValueTemp.begin() + mCursorPos);
        }
      } else if (key == GLFW_KEY_ENTER) {
        if (!mCommitted) focusEvent(false);
      } else if (key == GLFW_KEY_A && modifiers == SYSTEM_COMMAND_MOD) {
        mCursorPos = (int)mValueTemp.length();
        mSelectionPos = 0;
      } else if (key == GLFW_KEY_X && modifiers == SYSTEM_COMMAND_MOD) {
        copySelection();
        deleteSelection();
      } else if (key == GLFW_KEY_C && modifiers == SYSTEM_COMMAND_MOD) {
        copySelection();
      } else if (key == GLFW_KEY_V && modifiers == SYSTEM_COMMAND_MOD) {
        deleteSelection();
        pasteFromClipboard();
      }

      mValidFormat = (mValueTemp == "") || checkFormat(mValueTemp, mFormat);
    }

    return true;
  }

  return false;
}

bool TextBox::keyboardCharacterEvent(unsigned int codepoint) {
  if (mEditable && focused()) {
    std::ostringstream convert;
    convert << (char)codepoint;

    deleteSelection();
    mValueTemp.insert(mCursorPos, convert.str());
    mCursorPos++;

    mValidFormat = (mValueTemp == "") || checkFormat(mValueTemp, mFormat);

    return true;
  }

  return false;
}

bool TextBox::checkFormat(const std::string &input, const std::string &format) {
  if (format.empty()) return true;
  try {
    std::regex regex(format);
    return regex_match(input, regex);
  } catch (const std::regex_error &) {
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9)
    std::cerr << "Warning: cannot validate text field due to lacking regular "
                 "expression support. please compile with GCC >= 4.9"
              << std::endl;
    return true;
#else
    throw;
#endif
  }
}

bool TextBox::copySelection() {
  if (mSelectionPos > -1) {
    Screen *sc = dynamic_cast<Screen *>(this->window()->parent());
    if (!sc) return false;

    int begin = mCursorPos;
    int end = mSelectionPos;

    if (begin > end) std::swap(begin, end);

    glfwSetClipboardString(sc->glfwWindow(),
                           mValueTemp.substr(begin, end).c_str());
    return true;
  }

  return false;
}

void TextBox::pasteFromClipboard() {
  Screen *sc = dynamic_cast<Screen *>(this->window()->parent());
  if (!sc) return;
  const char *cbstr = glfwGetClipboardString(sc->glfwWindow());
  if (cbstr) mValueTemp.insert(mCursorPos, std::string(cbstr));
}

bool TextBox::deleteSelection() {
  if (mSelectionPos > -1) {
    int begin = mCursorPos;
    int end = mSelectionPos;

    if (begin > end) std::swap(begin, end);

    if (begin == end - 1)
      mValueTemp.erase(mValueTemp.begin() + begin);
    else
      mValueTemp.erase(mValueTemp.begin() + begin, mValueTemp.begin() + end);

    mCursorPos = begin;
    mSelectionPos = -1;
    return true;
  }

  return false;
}

void TextBox::updateCursor(float lastx,
                           const std::vector<skity::GlyphInfo> &glyphs) {
  // handle mouse cursor events
  if (mMouseDownPos.x() != -1) {
    if (mMouseDownModifier == GLFW_MOD_SHIFT) {
      if (mSelectionPos == -1) mSelectionPos = mCursorPos;
    } else
      mSelectionPos = -1;

    mCursorPos = position2CursorIndex(mMouseDownPos.x(), lastx, glyphs);

    mMouseDownPos = Vector2i(-1, -1);
  } else if (mMouseDragPos.x() != -1) {
    if (mSelectionPos == -1) mSelectionPos = mCursorPos;

    mCursorPos = position2CursorIndex(mMouseDragPos.x(), lastx, glyphs);
  } else {
    // set cursor to last character
    if (mCursorPos == -2) mCursorPos = glyphs.size() - 1;
  }

  if (mCursorPos == mSelectionPos) mSelectionPos = -1;
}

float TextBox::cursorIndex2Position(
    int index, float lastx, const std::vector<skity::GlyphInfo> &glyphs) {
  float pos = 0;
  if (index == glyphs.size() - 1)
    pos = lastx;  // last character
  else {
    for (int i = 0; i <= index; i++) {
      pos += glyphs[index].advance_x;
    }
  }

  return pos;
}

int TextBox::position2CursorIndex(float posx, float lastx,
                                  const std::vector<skity::GlyphInfo> &glyphs) {
  int mCursorId = 0;

  float caretx = glyphs[mCursorId].advance_x;
  for (int j = 1; j < glyphs.size(); j++) {
    if (std::abs(caretx - posx) >
        std::abs(caretx + glyphs[j].advance_x - posx)) {
      mCursorId = j;
      caretx += glyphs[mCursorId].advance_x;
    }
  }
  if (std::abs(caretx - posx) > std::abs(lastx - posx))
    mCursorId = glyphs.size() - 1;

  return mCursorId;
}

TextBox::SpinArea TextBox::spinArea(const Vector2i &pos) {
  if (0 <= pos.x() - mPos.x() &&
      pos.x() - mPos.x() < 14.f) { /* on scrolling arrows */
    if (mSize.y() >= pos.y() - mPos.y() &&
        pos.y() - mPos.y() <= mSize.y() / 2.f) { /* top part */
      return SpinArea::Top;
    } else if (0.f <= pos.y() - mPos.y() &&
               pos.y() - mPos.y() > mSize.y() / 2.f) { /* bottom part */
      return SpinArea::Bottom;
    }
  }
  return SpinArea::None;
}

void TextBox::save(Serializer &s) const {
  Widget::save(s);
  s.set("editable", mEditable);
  s.set("spinnable", mSpinnable);
  s.set("committed", mCommitted);
  s.set("value", mValue);
  s.set("defaultValue", mDefaultValue);
  s.set("alignment", (int)mAlignment);
  s.set("units", mUnits);
  s.set("format", mFormat);
  //  s.set("unitsImage", mUnitsImage);
  s.set("validFormat", mValidFormat);
  s.set("valueTemp", mValueTemp);
  s.set("cursorPos", mCursorPos);
  s.set("selectionPos", mSelectionPos);
}

bool TextBox::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("editable", mEditable)) return false;
  if (!s.get("spinnable", mSpinnable)) return false;
  if (!s.get("committed", mCommitted)) return false;
  if (!s.get("value", mValue)) return false;
  if (!s.get("defaultValue", mDefaultValue)) return false;
  if (!s.get("alignment", mAlignment)) return false;
  if (!s.get("units", mUnits)) return false;
  if (!s.get("format", mFormat)) return false;
  //  if (!s.get("unitsImage", mUnitsImage)) return false;
  if (!s.get("validFormat", mValidFormat)) return false;
  if (!s.get("valueTemp", mValueTemp)) return false;
  if (!s.get("cursorPos", mCursorPos)) return false;
  if (!s.get("selectionPos", mSelectionPos)) return false;
  mMousePos = mMouseDownPos = mMouseDragPos = Vector2i::Constant(-1);
  mMouseDownModifier = mTextOffset = 0;
  return true;
}

NAMESPACE_END(nanogui)
