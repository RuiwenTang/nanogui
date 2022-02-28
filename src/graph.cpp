/*
    src/graph.cpp -- Simple graph widget for showing a function plot

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/graph.h>
#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

NAMESPACE_BEGIN(nanogui)

Graph::Graph(Widget *parent, const std::string &caption)
    : Widget(parent), mCaption(caption) {
  mBackgroundColor = Color(20, 128);
  mForegroundColor = Color(255, 192, 0, 128);
  mTextColor = Color(240, 192);

  mStylePaint.setStyle(skity::Paint::kFill_Style);
  mStylePaint.setTypeface(mTheme->mFontNormal);
  mStylePaint.setTextSize(14.f);
  mStylePaint.setFillColor(mTextColor.toColor());

  mHeaderPaint.setStyle(skity::Paint::kFill_Style);
  mHeaderPaint.setTypeface(mTheme->mFontNormal);
  mHeaderPaint.setTextSize(18.f);
  mHeaderPaint.setFillColor(mTextColor.toColor());

  mFooterPaint.setStyle(skity::Paint::kFill_Style);
  mFooterPaint.setTypeface(mTheme->mFontNormal);
  mFooterPaint.setTextSize(15.f);
  mFooterPaint.setFillColor(mTextColor.toColor());

  rebuildCaptionBlob();
}

void Graph::setCaption(const std::string &caption) {
  mCaption = caption;
  mCaptionBlob = nullptr;
  rebuildCaptionBlob();
}

void Graph::setHeader(const std::string &header) {
  mHeader = header;
  mHeaderBlob = nullptr;
  rebuildHeaderBlob();
}

void Graph::setFooter(const std::string &footer) {
  mFooter = footer;
  mFooterBlob = nullptr;
  rebuildFooterBlob();
}

void Graph::rebuildCaptionBlob() {
  if (mCaption.empty()) {
    return;
  }

  if (mCaptionBlob) {
    return;
  }

  mCaptionBlob =
      skity::TextBlobBuilder{}.buildTextBlob(mCaption.c_str(), mStylePaint);
}

void Graph::rebuildHeaderBlob() {
  if (mHeader.empty()) {
    return;
  }

  if (mHeaderBlob) {
    return;
  }

  mHeaderBlob =
      skity::TextBlobBuilder{}.buildTextBlob(mHeader.c_str(), mHeaderPaint);
}

void Graph::rebuildFooterBlob() {
  if (mFooter.empty()) {
    return;
  }

  if (mFooterBlob) {
    return;
  }

  mFooterBlob =
      skity::TextBlobBuilder{}.buildTextBlob(mFooter.c_str(), mFooterPaint);
}

Vector2i Graph::preferredSize() const { return Vector2i(180, 45); }

void Graph::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);

  skity::Paint paint;
  paint.setStrokeWidth(1.f);
  paint.setStyle(skity::Paint::kFill_Style);
  paint.setFillColor(mBackgroundColor.toColor());
  canvas->drawRect(skity::Rect::MakeXYWH(0, 0, mSize.x(), mSize.y()), paint);

  if (mValues.size() < 2) return;

  skity::Path path;
  path.moveTo(0, mSize.y());
  for (size_t i = 0; i < (size_t)mValues.size(); i++) {
    float value = mValues[i];
    float vx = i * mSize.x() / (float)(mValues.size() - 1);
    float vy = (1 - value) * mSize.y();
    path.lineTo(vx, vy);
  }

  path.lineTo(mSize.x(), mSize.y());
  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeWidth(1.f);
  paint.setStrokeColor(Color{100, 255}.toColor());

  canvas->drawPath(path, paint);

  paint.setStyle(skity::Paint::kFill_Style);
  paint.setFillColor(mForegroundColor.toColor());

  canvas->drawPath(path, paint);

  if (mCaptionBlob) {
    float descent = mCaptionBlob->getBlobDescent();
    canvas->drawTextBlob(mCaptionBlob.get(), 3,
                         mSize.y() + 1.f + descent * 0.5f, mStylePaint);
  }

  if (mHeaderBlob) {
    auto bounds = mHeaderBlob->getBoundSize();
    float ascent = mHeaderBlob->getBlobAscent();

    canvas->drawTextBlob(mHeaderBlob.get(), mSize.x() - bounds.x - 3, ascent,
                         mHeaderPaint);
  }

  if (mFooterBlob) {
    auto bounds = mFooterBlob->getBoundSize();

    canvas->drawTextBlob(mFooterBlob.get(), mSize.x() - bounds.x - 3.f,
                         mSize.y(), mFooterPaint);
  }

  paint.setStyle(skity::Paint::kStroke_Style);
  paint.setStrokeColor(Color{100, 255}.toColor());

  canvas->drawRect(skity::Rect::MakeXYWH(0, 0, mSize.x(), mSize.y()), paint);
}

void Graph::save(Serializer &s) const {
  Widget::save(s);
  s.set("caption", mCaption);
  s.set("header", mHeader);
  s.set("footer", mFooter);
  s.set("backgroundColor", mBackgroundColor);
  s.set("foregroundColor", mForegroundColor);
  s.set("textColor", mTextColor);
  s.set("values", mValues);
}

bool Graph::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("caption", mCaption)) return false;
  if (!s.get("header", mHeader)) return false;
  if (!s.get("footer", mFooter)) return false;
  if (!s.get("backgroundColor", mBackgroundColor)) return false;
  if (!s.get("foregroundColor", mForegroundColor)) return false;
  if (!s.get("textColor", mTextColor)) return false;
  if (!s.get("values", mValues)) return false;
  return true;
}

NAMESPACE_END(nanogui)
