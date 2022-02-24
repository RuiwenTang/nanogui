/*
    nanogui/popupbutton.h -- Button which launches a popup widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/** \file */

#pragma once

#include <nanogui/button.h>
#include <nanogui/entypo.h>
#include <nanogui/popup.h>

NAMESPACE_BEGIN(nanogui)

/**
 * \class PopupButton popupbutton.h nanogui/popupbutton.h
 *
 * \brief Button which launches a popup widget.
 *
 * \remark
 *     This class overrides \ref nanogui::Widget::mIconExtraScale to be
 * ``0.8f``, which affects all subclasses of this Widget.  Subclasses must
 * explicitly set a different value if needed (e.g., in their constructor).
 */
class NANOGUI_EXPORT PopupButton : public Button {
 public:
  PopupButton(Widget *parent, const std::string &caption = "Untitled",
              const std::string &buttonIcon = "");
  ~PopupButton() override;

  void setChevronIcon(const std::string &icon);
  std::string chevronIcon() const { return mChevronIcon; }

  void setSide(Popup::Side popupSide);
  Popup::Side side() const { return mPopup->side(); }

  Popup *popup() { return mPopup; }
  const Popup *popup() const { return mPopup; }

  void draw(skity::Canvas *canvas) override;
  Vector2i preferredSize() const override;
  void performLayout() override;

  void save(Serializer &s) const override;
  bool load(Serializer &s) override;

 private:
  void rebuildChevronBlob();

 protected:
  Popup *mPopup;
  std::string mChevronIcon;

 private:
  skity::Paint mStylePaint;
  std::shared_ptr<skity::TextBlob> mChevronBlob;

 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

NAMESPACE_END(nanogui)
