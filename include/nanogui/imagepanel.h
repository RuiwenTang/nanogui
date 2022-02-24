/*
    nanogui/imagepanel.h -- Image panel widget which shows a number of
    square-shaped icons

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
 * \class ImagePanel imagepanel.h nanogui/imagepanel.h
 *
 * \brief Image panel widget which shows a number of square-shaped icons.
 */
class NANOGUI_EXPORT ImagePanel : public Widget {
 public:
  typedef std::vector<std::pair<std::shared_ptr<skity::Pixmap>, std::string>>
      Images;

 public:
  ImagePanel(Widget *parent);

  void setImages(const Images &data) { mImages = data; }
  const Images &images() const { return mImages; }

  std::function<void(int)> callback() const { return mCallback; }
  void setCallback(const std::function<void(int)> &callback) {
    mCallback = callback;
  }

  bool mouseMotionEvent(const Vector2i &p, const Vector2i &rel, int button,
                        int modifiers) override;
  bool mouseButtonEvent(const Vector2i &p, int button, bool down,
                        int modifiers) override;
  Vector2i preferredSize() const override;
  void draw(skity::Canvas *canvas) override;

 protected:
  Vector2i gridSize() const;
  int indexForPosition(const Vector2i &p) const;

 protected:
  Images mImages;
  std::function<void(int)> mCallback;
  int mThumbSize;
  int mSpacing;
  int mMargin;
  int mMouseIndex;

 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

NAMESPACE_END(nanogui)
