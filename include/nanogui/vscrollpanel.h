/*
    nanogui/vscrollpanel.h -- Adds a vertical scrollbar around a widget
    that is too big to fit into a certain area

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
 * \class VScrollPanel vscrollpanel.h nanogui/vscrollpanel.h
 *
 * \brief Adds a vertical scrollbar around a widget that is too big to fit into
 *        a certain area.
 */
class NANOGUI_EXPORT VScrollPanel : public Widget {
public:
    VScrollPanel(Widget *parent);

    /// Return the current scroll amount as a value between 0 and 1. 0 means scrolled to the top and 1 to the bottom.
    float scroll() const { return mScroll; }
    /// Set the scroll amount to a value between 0 and 1. 0 means scrolled to the top and 1 to the bottom.
    void setScroll(float scroll) { mScroll = scroll; }

    void performLayout() override;
    Vector2i preferredSize() const override;
    bool mouseDragEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers) override;
    bool scrollEvent(const Vector2i &p, const Vector2f &rel) override;
    void draw(skity::Canvas *canvas) override;
    void save(Serializer &s) const override;
    bool load(Serializer &s) override;
protected:
    int mChildPreferredHeight;
    float mScroll;
    bool mUpdateLayout;
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

NAMESPACE_END(nanogui)
