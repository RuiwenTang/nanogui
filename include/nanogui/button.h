/*
    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/**
 * \file nanogui/button.h
 *
 * \brief Defines the [Normal/Toggle/Radio/Popup] \ref nanogui::Button widget.
 */

#pragma once

#include <nanogui/widget.h>

NAMESPACE_BEGIN(nanogui)
/**
 * \class Button button.h nanogui/button.h
 *
 * \brief [Normal/Toggle/Radio/Popup] Button widget.
 */
class NANOGUI_EXPORT Button : public Widget {
 public:
  /// Flags to specify the button behavior (can be combined with binary OR)
  enum Flags {
    NormalButton = (1 << 0),  ///< A normal Button.
    RadioButton = (1 << 1),   ///< A radio Button.
    ToggleButton = (1 << 2),  ///< A toggle Button.
    PopupButton = (1 << 3)    ///< A popup Button.
  };

  /// The available icon positions.
  enum class IconPosition {
    Left,           ///< Button icon on the far left.
    LeftCentered,   ///< Button icon on the left, centered (depends on caption
                    ///< text length).
    RightCentered,  ///< Button icon on the right, centered (depends on caption
                    ///< text length).
    Right           ///< Button icon on the far right.
  };

  /**
   * \brief Creates a button attached to the specified parent.
   *
   * \param parent
   *     The \ref nanogui::Widget this Button will be attached to.
   *
   * \param caption
   *     The name of the button (default ``"Untitled"``).
   *
   * \param icon
   *     The icon to display with this Button.  See \ref nanogui::Button::mIcon.
   */
  Button(Widget *parent, std::string caption = "Untitled",
         std::string icon = "");
  Button(Widget *parent, const std::string &caption = "Untitled",
         const std::shared_ptr<skity::Pixmap> &icon = nullptr);

  /// Returns the caption of this Button.
  const std::string &caption() const { return mCaption; }

  /// Sets the caption of this Button.
  void setCaption(const std::string &caption);

  /// Returns the background color of this Button.
  const Color &backgroundColor() const { return mBackgroundColor; }

  /// Sets the background color of this Button.
  void setBackgroundColor(const Color &backgroundColor) {
    mBackgroundColor = backgroundColor;
  }

  /// Returns the text color of the caption of this Button.
  const Color &textColor() const { return mTextColor; }

  /// Sets the text color of the caption of this Button.
  void setTextColor(const Color &textColor) { mTextColor = textColor; }

  /// Returns the icon of this Button.  See \ref nanogui::Button::mIcon.
  std::string iconStr() const { return mIconStr; }

  /// Sets the icon of this Button.  See \ref nanogui::Button::mIcon.
  void setIconStr(std::string const& icon);

  /// The current flags of this Button (see \ref nanogui::Button::Flags for
  /// options).
  int flags() const { return mFlags; }

  /// Sets the flags of this Button (see \ref nanogui::Button::Flags for
  /// options).
  void setFlags(int buttonFlags) { mFlags = buttonFlags; }

  /// The position of the icon for this Button.
  IconPosition iconPosition() const { return mIconPosition; }

  /// Sets the position of the icon for this Button.
  void setIconPosition(IconPosition iconPosition) {
    mIconPosition = iconPosition;
  }

  /// Whether or not this Button is currently pushed.
  bool pushed() const { return mPushed; }

  /// Sets whether or not this Button is currently pushed.
  void setPushed(bool pushed) { mPushed = pushed; }

  /// The current callback to execute (for any type of button).
  std::function<void()> callback() const { return mCallback; }

  /// Set the push callback (for any type of button).
  void setCallback(const std::function<void()> &callback) {
    mCallback = callback;
  }

  /// The current callback to execute (for toggle buttons).
  std::function<void(bool)> changeCallback() const { return mChangeCallback; }

  /// Set the change callback (for toggle buttons).
  void setChangeCallback(const std::function<void(bool)> &callback) {
    mChangeCallback = callback;
  }

  /// Set the button group (for radio buttons).
  void setButtonGroup(const std::vector<Button *> &buttonGroup) {
    mButtonGroup = buttonGroup;
  }

  /// The current button group (for radio buttons).
  const std::vector<Button *> &buttonGroup() const { return mButtonGroup; }

  /// The preferred size of this Button.
  virtual Vector2i preferredSize() const override;

  /// The callback that is called when any type of mouse button event is issued
  /// to this Button.
  virtual bool mouseButtonEvent(const Vector2i &p, int button, bool down,
                                int modifiers) override;

  /// Responsible for drawing the Button.
  virtual void draw(skity::Canvas *canvas) override;

  /// Saves the state of this Button provided the given Serializer.
  virtual void save(Serializer &s) const override;

  /// Sets the state of this Button provided the given Serializer.
  virtual bool load(Serializer &s) override;

 protected:
  /// The caption of this Button.
  std::string mCaption;

  /// The position to draw the icon at.
  IconPosition mIconPosition;

  /// Whether or not this Button is currently pushed.
  bool mPushed;

  /// The current flags of this button (see \ref nanogui::Button::Flags for
  /// options).
  int mFlags;

  /// The background color of this Button.
  Color mBackgroundColor;

  /// The color of the caption text of this Button.
  Color mTextColor;

  /// The callback issued for all types of buttons.
  std::function<void()> mCallback;

  /// The callback issued for toggle buttons.
  std::function<void(bool)> mChangeCallback;

  /// The button group for radio buttons.
  std::vector<Button *> mButtonGroup;

  int getFontSize() const;

 private:
  std::string mIconStr;
  skity::TextBlobBuilder mTextBlobBuilder = {};
  skity::Paint mStylePaint = {};
  std::shared_ptr<skity::TextBlob> mCaptionBlob = {};
  std::shared_ptr<skity::TextBlob> mIconBlob = {};
  std::shared_ptr<skity::Pixmap> mIconPixmap = {};

  void rebuildCaptionBlob();
  void rebuildIconBlob();

 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

NAMESPACE_END(nanogui)
