/*
    nanogui/tabwidget.cpp -- A wrapper around the widgets TabHeader and
   StackedWidget which hooks the two classes together.

    The tab widget was contributed by Stefan Ivanov.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/opengl.h>
#include <nanogui/screen.h>
#include <nanogui/stackedwidget.h>
#include <nanogui/tabheader.h>
#include <nanogui/tabwidget.h>
#include <nanogui/theme.h>
#include <nanogui/window.h>

#include <algorithm>

NAMESPACE_BEGIN(nanogui)

TabWidget::TabWidget(Widget *parent)
    : Widget(parent),
      mHeader(new TabHeader(this))  // create using nullptr, add children below
      ,
      mContent(new StackedWidget(this)) {
  // since TabWidget::addChild is going to throw an exception to prevent
  // mis-use of this class, add the child directly
  Widget::addChild(childCount(), mHeader);
  Widget::addChild(childCount(), mContent);

  mHeader->setCallback([this](int i) {
    mContent->setSelectedIndex(i);
    if (mCallback) mCallback(i);
  });
}

void TabWidget::addChild(int /*index*/, Widget * /*widget*/) {
  // there may only be two children: mHeader and mContent, created in the
  // constructor
  //  throw std::runtime_error(
  //      "TabWidget: do not add children directly to the TabWidget, create tabs
  //      " "and add children to the tabs.  See TabWidget class documentation
  //      for " "example usage.");
}

void TabWidget::setActiveTab(int tabIndex) {
  mHeader->setActiveTab(tabIndex);
  mContent->setSelectedIndex(tabIndex);
}

int TabWidget::activeTab() const {
  assert(mHeader->activeTab() == mContent->selectedIndex());
  return mContent->selectedIndex();
}

int TabWidget::tabCount() const {
  assert(mContent->childCount() == mHeader->tabCount());
  return mHeader->tabCount();
}

Widget *TabWidget::createTab(int index, const std::string &label) {
  Widget *tab = new Widget(nullptr);
  addTab(index, label, tab);
  return tab;
}

Widget *TabWidget::createTab(const std::string &label) {
  return createTab(tabCount(), label);
}

void TabWidget::addTab(const std::string &name, Widget *tab) {
  addTab(tabCount(), name, tab);
}

void TabWidget::addTab(int index, const std::string &label, Widget *tab) {
  assert(index <= tabCount());
  // It is important to add the content first since the callback
  // of the header will automatically fire when a new tab is added.
  mContent->addChild(index, tab);
  mHeader->addTab(index, label);
  assert(mHeader->tabCount() == mContent->childCount());
}

int TabWidget::tabLabelIndex(const std::string &label) {
  return mHeader->tabIndex(label);
}

int TabWidget::tabIndex(Widget *tab) { return mContent->childIndex(tab); }

void TabWidget::ensureTabVisible(int index) {
  if (!mHeader->isTabVisible(index)) mHeader->ensureTabVisible(index);
}

const Widget *TabWidget::tab(const std::string &tabName) const {
  int index = mHeader->tabIndex(tabName);
  if (index == -1 || index == mContent->childCount()) return nullptr;
  return mContent->children()[index];
}

Widget *TabWidget::tab(const std::string &tabName) {
  int index = mHeader->tabIndex(tabName);
  if (index == -1 || index == mContent->childCount()) return nullptr;
  return mContent->children()[index];
}

const Widget *TabWidget::tab(int index) const {
  if (index < 0 || index >= mContent->childCount()) return nullptr;
  return mContent->children()[index];
}

Widget *TabWidget::tab(int index) {
  if (index < 0 || index >= mContent->childCount()) return nullptr;
  return mContent->children()[index];
}

bool TabWidget::removeTab(const std::string &tabName) {
  int index = mHeader->removeTab(tabName);
  if (index == -1) return false;
  mContent->removeChild(index);
  return true;
}

void TabWidget::removeTab(int index) {
  assert(mContent->childCount() < index);
  mHeader->removeTab(index);
  mContent->removeChild(index);
  if (activeTab() == index) setActiveTab(index == (index - 1) ? index - 1 : 0);
}

const std::string &TabWidget::tabLabelAt(int index) const {
  return mHeader->tabLabelAt(index);
}

void TabWidget::performLayout() {
  int headerHeight = mHeader->preferredSize().y();
  int margin = mTheme->mTabInnerMargin;
  mHeader->setPosition({0, 0});
  mHeader->setSize({mSize.x(), headerHeight});
  mHeader->performLayout();
  mContent->setPosition({margin, headerHeight + margin});
  mContent->setSize(
      {mSize.x() - 2 * margin, mSize.y() - 2 * margin - headerHeight});
  mContent->performLayout();
}

Vector2i TabWidget::preferredSize() const {
  auto contentSize = mContent->preferredSize();
  auto headerSize = mHeader->preferredSize();
  int margin = mTheme->mTabInnerMargin;
  auto borderSize = Vector2i(2 * margin, 2 * margin);
  Vector2i tabPreferredSize =
      contentSize + borderSize + Vector2i(0, headerSize.y());
  return tabPreferredSize;
}

void TabWidget::draw(skity::Canvas *canvas) {
  int tabHeight = mHeader->preferredSize().y();
  auto activeArea = mHeader->activeButtonArea();

  for (int i = 0; i < 3; i++) {
    canvas->save();

    skity::Rect clip_rect;
    if (i == 0) {
      clip_rect.setXYWH(0, 0, activeArea.first.x() + 1, mSize.y() - 1);
    } else if (i == 1) {
      clip_rect.setXYWH(activeArea.second.x(), 0,
                        mSize.x() - activeArea.second.x(), mSize.y() - 1);
    } else {
      clip_rect.setXYWH(0, tabHeight + 2, mSize.x(), mSize.y() - 1);
    }

    canvas->clipRect(clip_rect);

    skity::Paint paint;
    paint.setStyle(skity::Paint::kStroke_Style);
    paint.setStrokeColor(mTheme->mBorderLight.toColor());
    paint.setStrokeWidth(1.f);

    skity::Rect rect = skity::Rect::MakeXYWH(
        0.5f, tabHeight + 1.5f, mSize.x() - 1, mSize.y() - tabHeight - 2);
    canvas->drawRoundRect(rect, mTheme->mButtonCornerRadius,
                          mTheme->mButtonCornerRadius, paint);

    paint.setStrokeColor(mTheme->mBorderDark.toColor());

    rect.setXYWH(0.5f, tabHeight + 0.5f, mSize.x() - 1.f,
                 mSize.y() - tabHeight - 2.f);

    canvas->drawRoundRect(rect, mTheme->mButtonCornerRadius,
                          mTheme->mButtonCornerRadius, paint);

    canvas->restore();
  }
  Widget::draw(canvas);
}

NAMESPACE_END(nanogui)
