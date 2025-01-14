/*
    nanogui/label.h -- Text label with an arbitrary font, color, and size

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/** \file */

#pragma once

#include <nanogui/widget.h>

NAMESPACE_BEGIN(nanogui)

/**
 * \class Label label.h nanogui/label.h
 *
 * \brief Text label widget.
 *
 * The font and color can be customized. When \ref Widget::setFixedWidth()
 * is used, the text is wrapped when it surpasses the specified width.
 */
class NANOGUI_EXPORT Label : public Widget {
 public:
  Label(Widget *parent, const std::string &caption,
        const std::string &font = "sans", int fontSize = -1);

  /// Get the label's text caption
  const std::string &caption() const { return mCaption; }
  /// Set the label's text caption
  void setCaption(const std::string &caption);

  /// Set the currently active font (2 are available by default: 'sans' and
  /// 'sans-bold')
  void setFont(const std::string &font) { mFont = font; }
  /// Get the currently active font
  const std::string &font() const { return mFont; }

  /// Get the label color
  Color color() const { return mColor; }
  /// Set the label color
  void setColor(const Color &color) { mColor = color; }

  /// Set the \ref Theme used to draw this widget
  void setTheme(Theme *theme) override;

  /// Compute the size needed to fully display the label
  Vector2i preferredSize() const override;

  /// Draw the label
  void draw(skity::Canvas *canvas) override;

  void save(Serializer &s) const override;
  bool load(Serializer &s) override;

 protected:
  void onSetFontSize() override;

 protected:
  std::string mCaption;
  std::string mFont;
  Color mColor;

 private:
  skity::TextBlobBuilder mBlobBuilder = {};
  skity::Paint mStylePaint = {};
  std::shared_ptr<skity::TextBlob> mCaptionBlob = {};

  void rebuildCaptionBlob();

 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

NAMESPACE_END(nanogui)
