/*
    nanogui/graph.h -- Simple graph widget for showing a function plot

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
 * \class Graph graph.h nanogui/graph.h
 *
 * \brief Simple graph widget for showing a function plot.
 */
class NANOGUI_EXPORT Graph : public Widget {
 public:
  Graph(Widget *parent, const std::string &caption = "Untitled");

  const std::string &caption() const { return mCaption; }
  void setCaption(const std::string &caption);

  const std::string &header() const { return mHeader; }
  void setHeader(const std::string &header);

  const std::string &footer() const { return mFooter; }
  void setFooter(const std::string &footer);

  const Color &backgroundColor() const { return mBackgroundColor; }
  void setBackgroundColor(const Color &backgroundColor) {
    mBackgroundColor = backgroundColor;
  }

  const Color &foregroundColor() const { return mForegroundColor; }
  void setForegroundColor(const Color &foregroundColor) {
    mForegroundColor = foregroundColor;
  }

  const Color &textColor() const { return mTextColor; }
  void setTextColor(const Color &textColor) { mTextColor = textColor; }

  const VectorXf &values() const { return mValues; }
  VectorXf &values() { return mValues; }
  void setValues(const VectorXf &values) { mValues = values; }

  Vector2i preferredSize() const override;
  void draw(skity::Canvas *canvas) override;

  virtual void save(Serializer &s) const override;
  virtual bool load(Serializer &s) override;

 protected:
  std::string mCaption, mHeader, mFooter;
  Color mBackgroundColor, mForegroundColor, mTextColor;
  VectorXf mValues;

 private:
  void rebuildCaptionBlob();
  void rebuildHeaderBlob();
  void rebuildFooterBlob();

 private:
  skity::Paint mStylePaint;
  skity::Paint mHeaderPaint;
  skity::Paint mFooterPaint;
  std::shared_ptr<skity::TextBlob> mCaptionBlob;
  std::shared_ptr<skity::TextBlob> mHeaderBlob;
  std::shared_ptr<skity::TextBlob> mFooterBlob;

 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

NAMESPACE_END(nanogui)
