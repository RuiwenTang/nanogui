/*
     NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
     The widget drawing code is based on the NanoVG demo application
     by Mikko Mononen.

     All rights reserved. Use of this source code is governed by a
     BSD-style license that can be found in the LICENSE.txt file.
 */

/* Developer note: need to make a change to this file?
 * Please raise an Issue on GitHub describing what needs to change.  This file
 * was generated, so the scripts that generated it needs to update as well.
 */

/**
 * \file nanogui/entypo.h
 *
 * \brief This is a list of icon codes for the ``entypo.ttf`` font by Daniel Bruce.
 *
 * \rst
 *
 * This file defines the full listing of `Entypo <http://www.entypo.com/>`_
 * icons available in NanoGUI.  Please note that if viewing the documentation
 * on the web, your browser may display the icons differently than what they
 * look like in NanoGUI.  Run the one of the :ref:`nanogui_example_icons`
 * executables to see what they all look like in NanoGUI.
 *
 * .. note::
 *
 *    Constants you may have used in the past may no longer exist, e.g.
 *    the name may have changed slightly.  For example, ``ENTYPO_ICON_CIRCLED_HELP``
 *    is renamed to ``ENTYPO_ICON_HELP_WITH_CIRCLE``.
 *
 * .. warning::
 *
 *    Some icons have a "small" variant, e.g. ``ENTYPO_ICON_CHEVRON_SMALL_LEFT``
 *    is smaller than ``ENTYPO_ICON_CHEVRON_LEFT``.  While these "small" icons
 *    can be used, they may not be positioned correctly.  If you experience this
 *    you can, instead of using the "small" variant, use the "regular" icon and
 *    call the :func:`nanogui::Widget::setIconExtraScale` function with a value
 *    of **less than** ``1.0`` to scale the icon size down.
 *
 * .. tip::
 *
 *    In C++, ``#include <nanogui/entypo.h>`` to gain access to the ``#define``
 *    shown in these docs.  In Python, ``from nanogui import entypo``.  So in the
 *    below table, when you see ``ENTYPO_ICON_FLOW_TREE`` that is for C++, and
 *    when you see ``ICON_FLOW_TREE``, that is for Python, and you would access
 *    it using ``entypo.ICON_FLOW_TREE``.
 *
 * The following icons are available:
 *
 * .. raw:: html
 *
 *    <center>
 *      <div class="wy-table-responsive">
 *        <table class="docutils" border=1>
 *          <colgroup>
 *            <col width="55%" align="center"/>
 *            <col width="10%" align="center" />
 *            <col width="35%" align="center"/>
 *          </colgroup>
 *          <thead valign="bottom">
 *            <tr class="row-odd">
 *              <th class="head" align="center">C++ Definition</th>
 *              <th class="head" align="center">Icon</th>
 *              <th class="head" align="center">Python Definition</th>
 *            </tr>
 *          </thead>
 *          <tbody valign="top">
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_500PX</code></td>
 *              <td align="center"><span class="entypo-icon-500px"></span></td>
 *              <td align="left"><code>ICON_500PX</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_500PX_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-500px-with-circle"></span></td>
 *              <td align="left"><code>ICON_500PX_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ADD_TO_LIST</code></td>
 *              <td align="center"><span class="entypo-icon-add-to-list"></span></td>
 *              <td align="left"><code>ICON_ADD_TO_LIST</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ADD_USER</code></td>
 *              <td align="center"><span class="entypo-icon-add-user"></span></td>
 *              <td align="left"><code>ICON_ADD_USER</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ADDRESS</code></td>
 *              <td align="center"><span class="entypo-icon-address"></span></td>
 *              <td align="left"><code>ICON_ADDRESS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ADJUST</code></td>
 *              <td align="center"><span class="entypo-icon-adjust"></span></td>
 *              <td align="left"><code>ICON_ADJUST</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_AIR</code></td>
 *              <td align="center"><span class="entypo-icon-air"></span></td>
 *              <td align="left"><code>ICON_AIR</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_AIRCRAFT</code></td>
 *              <td align="center"><span class="entypo-icon-aircraft"></span></td>
 *              <td align="left"><code>ICON_AIRCRAFT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_AIRCRAFT_LANDING</code></td>
 *              <td align="center"><span class="entypo-icon-aircraft-landing"></span></td>
 *              <td align="left"><code>ICON_AIRCRAFT_LANDING</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_AIRCRAFT_TAKE_OFF</code></td>
 *              <td align="center"><span class="entypo-icon-aircraft-take-off"></span></td>
 *              <td align="left"><code>ICON_AIRCRAFT_TAKE_OFF</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ALIGN_BOTTOM</code></td>
 *              <td align="center"><span class="entypo-icon-align-bottom"></span></td>
 *              <td align="left"><code>ICON_ALIGN_BOTTOM</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ALIGN_HORIZONTAL_MIDDLE</code></td>
 *              <td align="center"><span class="entypo-icon-align-horizontal-middle"></span></td>
 *              <td align="left"><code>ICON_ALIGN_HORIZONTAL_MIDDLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ALIGN_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-align-left"></span></td>
 *              <td align="left"><code>ICON_ALIGN_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ALIGN_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-align-right"></span></td>
 *              <td align="left"><code>ICON_ALIGN_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ALIGN_TOP</code></td>
 *              <td align="center"><span class="entypo-icon-align-top"></span></td>
 *              <td align="left"><code>ICON_ALIGN_TOP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ALIGN_VERTICAL_MIDDLE</code></td>
 *              <td align="center"><span class="entypo-icon-align-vertical-middle"></span></td>
 *              <td align="left"><code>ICON_ALIGN_VERTICAL_MIDDLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_APP_STORE</code></td>
 *              <td align="center"><span class="entypo-icon-app-store"></span></td>
 *              <td align="left"><code>ICON_APP_STORE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARCHIVE</code></td>
 *              <td align="center"><span class="entypo-icon-archive"></span></td>
 *              <td align="left"><code>ICON_ARCHIVE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_AREA_GRAPH</code></td>
 *              <td align="center"><span class="entypo-icon-area-graph"></span></td>
 *              <td align="left"><code>ICON_AREA_GRAPH</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_BOLD_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-bold-down"></span></td>
 *              <td align="left"><code>ICON_ARROW_BOLD_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_BOLD_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-bold-left"></span></td>
 *              <td align="left"><code>ICON_ARROW_BOLD_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_BOLD_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-bold-right"></span></td>
 *              <td align="left"><code>ICON_ARROW_BOLD_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_BOLD_UP</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-bold-up"></span></td>
 *              <td align="left"><code>ICON_ARROW_BOLD_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-down"></span></td>
 *              <td align="left"><code>ICON_ARROW_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-left"></span></td>
 *              <td align="left"><code>ICON_ARROW_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_LONG_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-long-down"></span></td>
 *              <td align="left"><code>ICON_ARROW_LONG_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_LONG_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-long-left"></span></td>
 *              <td align="left"><code>ICON_ARROW_LONG_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_LONG_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-long-right"></span></td>
 *              <td align="left"><code>ICON_ARROW_LONG_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_LONG_UP</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-long-up"></span></td>
 *              <td align="left"><code>ICON_ARROW_LONG_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-right"></span></td>
 *              <td align="left"><code>ICON_ARROW_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_UP</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-up"></span></td>
 *              <td align="left"><code>ICON_ARROW_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_WITH_CIRCLE_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-with-circle-down"></span></td>
 *              <td align="left"><code>ICON_ARROW_WITH_CIRCLE_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_WITH_CIRCLE_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-with-circle-left"></span></td>
 *              <td align="left"><code>ICON_ARROW_WITH_CIRCLE_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_WITH_CIRCLE_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-with-circle-right"></span></td>
 *              <td align="left"><code>ICON_ARROW_WITH_CIRCLE_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ARROW_WITH_CIRCLE_UP</code></td>
 *              <td align="center"><span class="entypo-icon-arrow-with-circle-up"></span></td>
 *              <td align="left"><code>ICON_ARROW_WITH_CIRCLE_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ATTACHMENT</code></td>
 *              <td align="center"><span class="entypo-icon-attachment"></span></td>
 *              <td align="left"><code>ICON_ATTACHMENT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_AWARENESS_RIBBON</code></td>
 *              <td align="center"><span class="entypo-icon-awareness-ribbon"></span></td>
 *              <td align="left"><code>ICON_AWARENESS_RIBBON</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BACK</code></td>
 *              <td align="center"><span class="entypo-icon-back"></span></td>
 *              <td align="left"><code>ICON_BACK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BACK_IN_TIME</code></td>
 *              <td align="center"><span class="entypo-icon-back-in-time"></span></td>
 *              <td align="left"><code>ICON_BACK_IN_TIME</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BAIDU</code></td>
 *              <td align="center"><span class="entypo-icon-baidu"></span></td>
 *              <td align="left"><code>ICON_BAIDU</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BAR_GRAPH</code></td>
 *              <td align="center"><span class="entypo-icon-bar-graph"></span></td>
 *              <td align="left"><code>ICON_BAR_GRAPH</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BASECAMP</code></td>
 *              <td align="center"><span class="entypo-icon-basecamp"></span></td>
 *              <td align="left"><code>ICON_BASECAMP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BATTERY</code></td>
 *              <td align="center"><span class="entypo-icon-battery"></span></td>
 *              <td align="left"><code>ICON_BATTERY</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BEAMED_NOTE</code></td>
 *              <td align="center"><span class="entypo-icon-beamed-note"></span></td>
 *              <td align="left"><code>ICON_BEAMED_NOTE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BEHANCE</code></td>
 *              <td align="center"><span class="entypo-icon-behance"></span></td>
 *              <td align="left"><code>ICON_BEHANCE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BELL</code></td>
 *              <td align="center"><span class="entypo-icon-bell"></span></td>
 *              <td align="left"><code>ICON_BELL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BLACKBOARD</code></td>
 *              <td align="center"><span class="entypo-icon-blackboard"></span></td>
 *              <td align="left"><code>ICON_BLACKBOARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BLOCK</code></td>
 *              <td align="center"><span class="entypo-icon-block"></span></td>
 *              <td align="left"><code>ICON_BLOCK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BOOK</code></td>
 *              <td align="center"><span class="entypo-icon-book"></span></td>
 *              <td align="left"><code>ICON_BOOK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BOOKMARK</code></td>
 *              <td align="center"><span class="entypo-icon-bookmark"></span></td>
 *              <td align="left"><code>ICON_BOOKMARK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BOOKMARKS</code></td>
 *              <td align="center"><span class="entypo-icon-bookmarks"></span></td>
 *              <td align="left"><code>ICON_BOOKMARKS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BOWL</code></td>
 *              <td align="center"><span class="entypo-icon-bowl"></span></td>
 *              <td align="left"><code>ICON_BOWL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BOX</code></td>
 *              <td align="center"><span class="entypo-icon-box"></span></td>
 *              <td align="left"><code>ICON_BOX</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BRIEFCASE</code></td>
 *              <td align="center"><span class="entypo-icon-briefcase"></span></td>
 *              <td align="left"><code>ICON_BRIEFCASE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BROWSER</code></td>
 *              <td align="center"><span class="entypo-icon-browser"></span></td>
 *              <td align="left"><code>ICON_BROWSER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BRUSH</code></td>
 *              <td align="center"><span class="entypo-icon-brush"></span></td>
 *              <td align="left"><code>ICON_BRUSH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_BUCKET</code></td>
 *              <td align="center"><span class="entypo-icon-bucket"></span></td>
 *              <td align="left"><code>ICON_BUCKET</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_BUG</code></td>
 *              <td align="center"><span class="entypo-icon-bug"></span></td>
 *              <td align="left"><code>ICON_BUG</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CAKE</code></td>
 *              <td align="center"><span class="entypo-icon-cake"></span></td>
 *              <td align="left"><code>ICON_CAKE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CALCULATOR</code></td>
 *              <td align="center"><span class="entypo-icon-calculator"></span></td>
 *              <td align="left"><code>ICON_CALCULATOR</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CALENDAR</code></td>
 *              <td align="center"><span class="entypo-icon-calendar"></span></td>
 *              <td align="left"><code>ICON_CALENDAR</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CAMERA</code></td>
 *              <td align="center"><span class="entypo-icon-camera"></span></td>
 *              <td align="left"><code>ICON_CAMERA</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CCW</code></td>
 *              <td align="center"><span class="entypo-icon-ccw"></span></td>
 *              <td align="left"><code>ICON_CCW</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHAT</code></td>
 *              <td align="center"><span class="entypo-icon-chat"></span></td>
 *              <td align="left"><code>ICON_CHAT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHECK</code></td>
 *              <td align="center"><span class="entypo-icon-check"></span></td>
 *              <td align="left"><code>ICON_CHECK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-down"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-left"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-right"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_SMALL_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-small-down"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_SMALL_DOWN</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_SMALL_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-small-left"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_SMALL_LEFT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_SMALL_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-small-right"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_SMALL_RIGHT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_SMALL_UP</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-small-up"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_SMALL_UP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_THIN_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-thin-down"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_THIN_DOWN</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_THIN_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-thin-left"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_THIN_LEFT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_THIN_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-thin-right"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_THIN_RIGHT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_THIN_UP</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-thin-up"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_THIN_UP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_UP</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-up"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_WITH_CIRCLE_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-with-circle-down"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_WITH_CIRCLE_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_WITH_CIRCLE_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-with-circle-left"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_WITH_CIRCLE_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_WITH_CIRCLE_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-with-circle-right"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_WITH_CIRCLE_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CHEVRON_WITH_CIRCLE_UP</code></td>
 *              <td align="center"><span class="entypo-icon-chevron-with-circle-up"></span></td>
 *              <td align="left"><code>ICON_CHEVRON_WITH_CIRCLE_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-circle"></span></td>
 *              <td align="left"><code>ICON_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CIRCLE_WITH_CROSS</code></td>
 *              <td align="center"><span class="entypo-icon-circle-with-cross"></span></td>
 *              <td align="left"><code>ICON_CIRCLE_WITH_CROSS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CIRCLE_WITH_MINUS</code></td>
 *              <td align="center"><span class="entypo-icon-circle-with-minus"></span></td>
 *              <td align="left"><code>ICON_CIRCLE_WITH_MINUS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CIRCLE_WITH_PLUS</code></td>
 *              <td align="center"><span class="entypo-icon-circle-with-plus"></span></td>
 *              <td align="left"><code>ICON_CIRCLE_WITH_PLUS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CIRCULAR_GRAPH</code></td>
 *              <td align="center"><span class="entypo-icon-circular-graph"></span></td>
 *              <td align="left"><code>ICON_CIRCULAR_GRAPH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CLAPPERBOARD</code></td>
 *              <td align="center"><span class="entypo-icon-clapperboard"></span></td>
 *              <td align="left"><code>ICON_CLAPPERBOARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CLASSIC_COMPUTER</code></td>
 *              <td align="center"><span class="entypo-icon-classic-computer"></span></td>
 *              <td align="left"><code>ICON_CLASSIC_COMPUTER</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CLIPBOARD</code></td>
 *              <td align="center"><span class="entypo-icon-clipboard"></span></td>
 *              <td align="left"><code>ICON_CLIPBOARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CLOCK</code></td>
 *              <td align="center"><span class="entypo-icon-clock"></span></td>
 *              <td align="left"><code>ICON_CLOCK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CLOUD</code></td>
 *              <td align="center"><span class="entypo-icon-cloud"></span></td>
 *              <td align="left"><code>ICON_CLOUD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CODE</code></td>
 *              <td align="center"><span class="entypo-icon-code"></span></td>
 *              <td align="left"><code>ICON_CODE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_COG</code></td>
 *              <td align="center"><span class="entypo-icon-cog"></span></td>
 *              <td align="left"><code>ICON_COG</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_COLOURS</code></td>
 *              <td align="center"><span class="entypo-icon-colours"></span></td>
 *              <td align="left"><code>ICON_COLOURS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_COMPASS</code></td>
 *              <td align="center"><span class="entypo-icon-compass"></span></td>
 *              <td align="left"><code>ICON_COMPASS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_FAST_BACKWARD</code></td>
 *              <td align="center"><span class="entypo-icon-controller-fast-backward"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_FAST_BACKWARD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_FAST_FORWARD</code></td>
 *              <td align="center"><span class="entypo-icon-controller-fast-forward"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_FAST_FORWARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_JUMP_TO_START</code></td>
 *              <td align="center"><span class="entypo-icon-controller-jump-to-start"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_JUMP_TO_START</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_NEXT</code></td>
 *              <td align="center"><span class="entypo-icon-controller-next"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_NEXT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_PAUS</code></td>
 *              <td align="center"><span class="entypo-icon-controller-paus"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_PAUS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_PLAY</code></td>
 *              <td align="center"><span class="entypo-icon-controller-play"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_PLAY</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_RECORD</code></td>
 *              <td align="center"><span class="entypo-icon-controller-record"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_RECORD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_STOP</code></td>
 *              <td align="center"><span class="entypo-icon-controller-stop"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_STOP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CONTROLLER_VOLUME</code></td>
 *              <td align="center"><span class="entypo-icon-controller-volume"></span></td>
 *              <td align="left"><code>ICON_CONTROLLER_VOLUME</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_COPY</code></td>
 *              <td align="center"><span class="entypo-icon-copy"></span></td>
 *              <td align="left"><code>ICON_COPY</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_CLOUD</code></td>
 *              <td align="center"><span class="entypo-icon-creative-cloud"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_CLOUD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_ATTRIBUTION</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-attribution"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_ATTRIBUTION</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_NODERIVS</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-noderivs"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_NODERIVS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_NONCOMMERCIAL_EU</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-noncommercial-eu"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_NONCOMMERCIAL_EU</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_NONCOMMERCIAL_US</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-noncommercial-us"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_NONCOMMERCIAL_US</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_PUBLIC_DOMAIN</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-public-domain"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_PUBLIC_DOMAIN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_REMIX</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-remix"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_REMIX</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_SHARE</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-share"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_SHARE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CREATIVE_COMMONS_SHAREALIKE</code></td>
 *              <td align="center"><span class="entypo-icon-creative-commons-sharealike"></span></td>
 *              <td align="left"><code>ICON_CREATIVE_COMMONS_SHAREALIKE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CREDIT</code></td>
 *              <td align="center"><span class="entypo-icon-credit"></span></td>
 *              <td align="left"><code>ICON_CREDIT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CREDIT_CARD</code></td>
 *              <td align="center"><span class="entypo-icon-credit-card"></span></td>
 *              <td align="left"><code>ICON_CREDIT_CARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CROP</code></td>
 *              <td align="center"><span class="entypo-icon-crop"></span></td>
 *              <td align="left"><code>ICON_CROP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CROSS</code></td>
 *              <td align="center"><span class="entypo-icon-cross"></span></td>
 *              <td align="left"><code>ICON_CROSS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CUP</code></td>
 *              <td align="center"><span class="entypo-icon-cup"></span></td>
 *              <td align="left"><code>ICON_CUP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_CW</code></td>
 *              <td align="center"><span class="entypo-icon-cw"></span></td>
 *              <td align="left"><code>ICON_CW</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_CYCLE</code></td>
 *              <td align="center"><span class="entypo-icon-cycle"></span></td>
 *              <td align="left"><code>ICON_CYCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DATABASE</code></td>
 *              <td align="center"><span class="entypo-icon-database"></span></td>
 *              <td align="left"><code>ICON_DATABASE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DIAL_PAD</code></td>
 *              <td align="center"><span class="entypo-icon-dial-pad"></span></td>
 *              <td align="left"><code>ICON_DIAL_PAD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DIRECTION</code></td>
 *              <td align="center"><span class="entypo-icon-direction"></span></td>
 *              <td align="left"><code>ICON_DIRECTION</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DOCUMENT</code></td>
 *              <td align="center"><span class="entypo-icon-document"></span></td>
 *              <td align="left"><code>ICON_DOCUMENT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DOCUMENT_LANDSCAPE</code></td>
 *              <td align="center"><span class="entypo-icon-document-landscape"></span></td>
 *              <td align="left"><code>ICON_DOCUMENT_LANDSCAPE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DOCUMENTS</code></td>
 *              <td align="center"><span class="entypo-icon-documents"></span></td>
 *              <td align="left"><code>ICON_DOCUMENTS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DOT_SINGLE</code></td>
 *              <td align="center"><span class="entypo-icon-dot-single"></span></td>
 *              <td align="left"><code>ICON_DOT_SINGLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DOTS_THREE_HORIZONTAL</code></td>
 *              <td align="center"><span class="entypo-icon-dots-three-horizontal"></span></td>
 *              <td align="left"><code>ICON_DOTS_THREE_HORIZONTAL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DOTS_THREE_VERTICAL</code></td>
 *              <td align="center"><span class="entypo-icon-dots-three-vertical"></span></td>
 *              <td align="left"><code>ICON_DOTS_THREE_VERTICAL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DOTS_TWO_HORIZONTAL</code></td>
 *              <td align="center"><span class="entypo-icon-dots-two-horizontal"></span></td>
 *              <td align="left"><code>ICON_DOTS_TWO_HORIZONTAL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DOTS_TWO_VERTICAL</code></td>
 *              <td align="center"><span class="entypo-icon-dots-two-vertical"></span></td>
 *              <td align="left"><code>ICON_DOTS_TWO_VERTICAL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DOWNLOAD</code></td>
 *              <td align="center"><span class="entypo-icon-download"></span></td>
 *              <td align="left"><code>ICON_DOWNLOAD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DRIBBBLE</code></td>
 *              <td align="center"><span class="entypo-icon-dribbble"></span></td>
 *              <td align="left"><code>ICON_DRIBBBLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DRIBBBLE_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-dribbble-with-circle"></span></td>
 *              <td align="left"><code>ICON_DRIBBBLE_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DRINK</code></td>
 *              <td align="center"><span class="entypo-icon-drink"></span></td>
 *              <td align="left"><code>ICON_DRINK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DRIVE</code></td>
 *              <td align="center"><span class="entypo-icon-drive"></span></td>
 *              <td align="left"><code>ICON_DRIVE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_DROP</code></td>
 *              <td align="center"><span class="entypo-icon-drop"></span></td>
 *              <td align="left"><code>ICON_DROP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_DROPBOX</code></td>
 *              <td align="center"><span class="entypo-icon-dropbox"></span></td>
 *              <td align="left"><code>ICON_DROPBOX</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_EDIT</code></td>
 *              <td align="center"><span class="entypo-icon-edit"></span></td>
 *              <td align="left"><code>ICON_EDIT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_EMAIL</code></td>
 *              <td align="center"><span class="entypo-icon-email"></span></td>
 *              <td align="left"><code>ICON_EMAIL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_EMOJI_FLIRT</code></td>
 *              <td align="center"><span class="entypo-icon-emoji-flirt"></span></td>
 *              <td align="left"><code>ICON_EMOJI_FLIRT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_EMOJI_HAPPY</code></td>
 *              <td align="center"><span class="entypo-icon-emoji-happy"></span></td>
 *              <td align="left"><code>ICON_EMOJI_HAPPY</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_EMOJI_NEUTRAL</code></td>
 *              <td align="center"><span class="entypo-icon-emoji-neutral"></span></td>
 *              <td align="left"><code>ICON_EMOJI_NEUTRAL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_EMOJI_SAD</code></td>
 *              <td align="center"><span class="entypo-icon-emoji-sad"></span></td>
 *              <td align="left"><code>ICON_EMOJI_SAD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ERASE</code></td>
 *              <td align="center"><span class="entypo-icon-erase"></span></td>
 *              <td align="left"><code>ICON_ERASE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ERASER</code></td>
 *              <td align="center"><span class="entypo-icon-eraser"></span></td>
 *              <td align="left"><code>ICON_ERASER</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_EVERNOTE</code></td>
 *              <td align="center"><span class="entypo-icon-evernote"></span></td>
 *              <td align="left"><code>ICON_EVERNOTE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_EXPORT</code></td>
 *              <td align="center"><span class="entypo-icon-export"></span></td>
 *              <td align="left"><code>ICON_EXPORT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_EYE</code></td>
 *              <td align="center"><span class="entypo-icon-eye"></span></td>
 *              <td align="left"><code>ICON_EYE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_EYE_WITH_LINE</code></td>
 *              <td align="center"><span class="entypo-icon-eye-with-line"></span></td>
 *              <td align="left"><code>ICON_EYE_WITH_LINE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FACEBOOK</code></td>
 *              <td align="center"><span class="entypo-icon-facebook"></span></td>
 *              <td align="left"><code>ICON_FACEBOOK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FACEBOOK_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-facebook-with-circle"></span></td>
 *              <td align="left"><code>ICON_FACEBOOK_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FEATHER</code></td>
 *              <td align="center"><span class="entypo-icon-feather"></span></td>
 *              <td align="left"><code>ICON_FEATHER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FINGERPRINT</code></td>
 *              <td align="center"><span class="entypo-icon-fingerprint"></span></td>
 *              <td align="left"><code>ICON_FINGERPRINT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLAG</code></td>
 *              <td align="center"><span class="entypo-icon-flag"></span></td>
 *              <td align="left"><code>ICON_FLAG</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FLASH</code></td>
 *              <td align="center"><span class="entypo-icon-flash"></span></td>
 *              <td align="left"><code>ICON_FLASH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLASHLIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-flashlight"></span></td>
 *              <td align="left"><code>ICON_FLASHLIGHT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FLAT_BRUSH</code></td>
 *              <td align="center"><span class="entypo-icon-flat-brush"></span></td>
 *              <td align="left"><code>ICON_FLAT_BRUSH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLATTR</code></td>
 *              <td align="center"><span class="entypo-icon-flattr"></span></td>
 *              <td align="left"><code>ICON_FLATTR</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FLICKR</code></td>
 *              <td align="center"><span class="entypo-icon-flickr"></span></td>
 *              <td align="left"><code>ICON_FLICKR</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLICKR_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-flickr-with-circle"></span></td>
 *              <td align="left"><code>ICON_FLICKR_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FLOW_BRANCH</code></td>
 *              <td align="center"><span class="entypo-icon-flow-branch"></span></td>
 *              <td align="left"><code>ICON_FLOW_BRANCH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLOW_CASCADE</code></td>
 *              <td align="center"><span class="entypo-icon-flow-cascade"></span></td>
 *              <td align="left"><code>ICON_FLOW_CASCADE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FLOW_LINE</code></td>
 *              <td align="center"><span class="entypo-icon-flow-line"></span></td>
 *              <td align="left"><code>ICON_FLOW_LINE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLOW_PARALLEL</code></td>
 *              <td align="center"><span class="entypo-icon-flow-parallel"></span></td>
 *              <td align="left"><code>ICON_FLOW_PARALLEL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FLOW_TREE</code></td>
 *              <td align="center"><span class="entypo-icon-flow-tree"></span></td>
 *              <td align="left"><code>ICON_FLOW_TREE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FLOWER</code></td>
 *              <td align="center"><span class="entypo-icon-flower"></span></td>
 *              <td align="left"><code>ICON_FLOWER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FOLDER</code></td>
 *              <td align="center"><span class="entypo-icon-folder"></span></td>
 *              <td align="left"><code>ICON_FOLDER</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FOLDER_IMAGES</code></td>
 *              <td align="center"><span class="entypo-icon-folder-images"></span></td>
 *              <td align="left"><code>ICON_FOLDER_IMAGES</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FOLDER_MUSIC</code></td>
 *              <td align="center"><span class="entypo-icon-folder-music"></span></td>
 *              <td align="left"><code>ICON_FOLDER_MUSIC</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FOLDER_VIDEO</code></td>
 *              <td align="center"><span class="entypo-icon-folder-video"></span></td>
 *              <td align="left"><code>ICON_FOLDER_VIDEO</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FORWARD</code></td>
 *              <td align="center"><span class="entypo-icon-forward"></span></td>
 *              <td align="left"><code>ICON_FORWARD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_FOURSQUARE</code></td>
 *              <td align="center"><span class="entypo-icon-foursquare"></span></td>
 *              <td align="left"><code>ICON_FOURSQUARE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_FUNNEL</code></td>
 *              <td align="center"><span class="entypo-icon-funnel"></span></td>
 *              <td align="left"><code>ICON_FUNNEL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GAME_CONTROLLER</code></td>
 *              <td align="center"><span class="entypo-icon-game-controller"></span></td>
 *              <td align="left"><code>ICON_GAME_CONTROLLER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_GAUGE</code></td>
 *              <td align="center"><span class="entypo-icon-gauge"></span></td>
 *              <td align="left"><code>ICON_GAUGE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GITHUB</code></td>
 *              <td align="center"><span class="entypo-icon-github"></span></td>
 *              <td align="left"><code>ICON_GITHUB</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_GITHUB_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-github-with-circle"></span></td>
 *              <td align="left"><code>ICON_GITHUB_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GLOBE</code></td>
 *              <td align="center"><span class="entypo-icon-globe"></span></td>
 *              <td align="left"><code>ICON_GLOBE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_GOOGLE_DRIVE</code></td>
 *              <td align="center"><span class="entypo-icon-google-drive"></span></td>
 *              <td align="left"><code>ICON_GOOGLE_DRIVE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GOOGLE_HANGOUTS</code></td>
 *              <td align="center"><span class="entypo-icon-google-hangouts"></span></td>
 *              <td align="left"><code>ICON_GOOGLE_HANGOUTS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_GOOGLE_PLAY</code></td>
 *              <td align="center"><span class="entypo-icon-google-play"></span></td>
 *              <td align="left"><code>ICON_GOOGLE_PLAY</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GOOGLE_PLUS</code></td>
 *              <td align="center"><span class="entypo-icon-google-plus"></span></td>
 *              <td align="left"><code>ICON_GOOGLE_PLUS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_GOOGLE_PLUS_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-google-plus-with-circle"></span></td>
 *              <td align="left"><code>ICON_GOOGLE_PLUS_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GRADUATION_CAP</code></td>
 *              <td align="center"><span class="entypo-icon-graduation-cap"></span></td>
 *              <td align="left"><code>ICON_GRADUATION_CAP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_GRID</code></td>
 *              <td align="center"><span class="entypo-icon-grid"></span></td>
 *              <td align="left"><code>ICON_GRID</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_GROOVESHARK</code></td>
 *              <td align="center"><span class="entypo-icon-grooveshark"></span></td>
 *              <td align="left"><code>ICON_GROOVESHARK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_HAIR_CROSS</code></td>
 *              <td align="center"><span class="entypo-icon-hair-cross"></span></td>
 *              <td align="left"><code>ICON_HAIR_CROSS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_HAND</code></td>
 *              <td align="center"><span class="entypo-icon-hand"></span></td>
 *              <td align="left"><code>ICON_HAND</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_HEART</code></td>
 *              <td align="center"><span class="entypo-icon-heart"></span></td>
 *              <td align="left"><code>ICON_HEART</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_HEART_OUTLINED</code></td>
 *              <td align="center"><span class="entypo-icon-heart-outlined"></span></td>
 *              <td align="left"><code>ICON_HEART_OUTLINED</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_HELP</code></td>
 *              <td align="center"><span class="entypo-icon-help"></span></td>
 *              <td align="left"><code>ICON_HELP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_HELP_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-help-with-circle"></span></td>
 *              <td align="left"><code>ICON_HELP_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_HOME</code></td>
 *              <td align="center"><span class="entypo-icon-home"></span></td>
 *              <td align="left"><code>ICON_HOME</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_HOUR_GLASS</code></td>
 *              <td align="center"><span class="entypo-icon-hour-glass"></span></td>
 *              <td align="left"><code>ICON_HOUR_GLASS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_HOUZZ</code></td>
 *              <td align="center"><span class="entypo-icon-houzz"></span></td>
 *              <td align="left"><code>ICON_HOUZZ</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ICLOUD</code></td>
 *              <td align="center"><span class="entypo-icon-icloud"></span></td>
 *              <td align="left"><code>ICON_ICLOUD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_IMAGE</code></td>
 *              <td align="center"><span class="entypo-icon-image"></span></td>
 *              <td align="left"><code>ICON_IMAGE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_IMAGE_INVERTED</code></td>
 *              <td align="center"><span class="entypo-icon-image-inverted"></span></td>
 *              <td align="left"><code>ICON_IMAGE_INVERTED</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_IMAGES</code></td>
 *              <td align="center"><span class="entypo-icon-images"></span></td>
 *              <td align="left"><code>ICON_IMAGES</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_INBOX</code></td>
 *              <td align="center"><span class="entypo-icon-inbox"></span></td>
 *              <td align="left"><code>ICON_INBOX</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_INFINITY</code></td>
 *              <td align="center"><span class="entypo-icon-infinity"></span></td>
 *              <td align="left"><code>ICON_INFINITY</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_INFO</code></td>
 *              <td align="center"><span class="entypo-icon-info"></span></td>
 *              <td align="left"><code>ICON_INFO</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_INFO_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-info-with-circle"></span></td>
 *              <td align="left"><code>ICON_INFO_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_INSTAGRAM</code></td>
 *              <td align="center"><span class="entypo-icon-instagram"></span></td>
 *              <td align="left"><code>ICON_INSTAGRAM</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_INSTAGRAM_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-instagram-with-circle"></span></td>
 *              <td align="left"><code>ICON_INSTAGRAM_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_INSTALL</code></td>
 *              <td align="center"><span class="entypo-icon-install"></span></td>
 *              <td align="left"><code>ICON_INSTALL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_KEY</code></td>
 *              <td align="center"><span class="entypo-icon-key"></span></td>
 *              <td align="left"><code>ICON_KEY</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_KEYBOARD</code></td>
 *              <td align="center"><span class="entypo-icon-keyboard"></span></td>
 *              <td align="left"><code>ICON_KEYBOARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LAB_FLASK</code></td>
 *              <td align="center"><span class="entypo-icon-lab-flask"></span></td>
 *              <td align="left"><code>ICON_LAB_FLASK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LANDLINE</code></td>
 *              <td align="center"><span class="entypo-icon-landline"></span></td>
 *              <td align="left"><code>ICON_LANDLINE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LANGUAGE</code></td>
 *              <td align="center"><span class="entypo-icon-language"></span></td>
 *              <td align="left"><code>ICON_LANGUAGE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LAPTOP</code></td>
 *              <td align="center"><span class="entypo-icon-laptop"></span></td>
 *              <td align="left"><code>ICON_LAPTOP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LASTFM</code></td>
 *              <td align="center"><span class="entypo-icon-lastfm"></span></td>
 *              <td align="left"><code>ICON_LASTFM</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LASTFM_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-lastfm-with-circle"></span></td>
 *              <td align="left"><code>ICON_LASTFM_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LAYERS</code></td>
 *              <td align="center"><span class="entypo-icon-layers"></span></td>
 *              <td align="left"><code>ICON_LAYERS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LEAF</code></td>
 *              <td align="center"><span class="entypo-icon-leaf"></span></td>
 *              <td align="left"><code>ICON_LEAF</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LEVEL_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-level-down"></span></td>
 *              <td align="left"><code>ICON_LEVEL_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LEVEL_UP</code></td>
 *              <td align="center"><span class="entypo-icon-level-up"></span></td>
 *              <td align="left"><code>ICON_LEVEL_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LIFEBUOY</code></td>
 *              <td align="center"><span class="entypo-icon-lifebuoy"></span></td>
 *              <td align="left"><code>ICON_LIFEBUOY</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LIGHT_BULB</code></td>
 *              <td align="center"><span class="entypo-icon-light-bulb"></span></td>
 *              <td align="left"><code>ICON_LIGHT_BULB</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LIGHT_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-light-down"></span></td>
 *              <td align="left"><code>ICON_LIGHT_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LIGHT_UP</code></td>
 *              <td align="center"><span class="entypo-icon-light-up"></span></td>
 *              <td align="left"><code>ICON_LIGHT_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LINE_GRAPH</code></td>
 *              <td align="center"><span class="entypo-icon-line-graph"></span></td>
 *              <td align="left"><code>ICON_LINE_GRAPH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LINK</code></td>
 *              <td align="center"><span class="entypo-icon-link"></span></td>
 *              <td align="left"><code>ICON_LINK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LINKEDIN</code></td>
 *              <td align="center"><span class="entypo-icon-linkedin"></span></td>
 *              <td align="left"><code>ICON_LINKEDIN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LINKEDIN_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-linkedin-with-circle"></span></td>
 *              <td align="left"><code>ICON_LINKEDIN_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LIST</code></td>
 *              <td align="center"><span class="entypo-icon-list"></span></td>
 *              <td align="left"><code>ICON_LIST</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LOCATION</code></td>
 *              <td align="center"><span class="entypo-icon-location"></span></td>
 *              <td align="left"><code>ICON_LOCATION</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LOCATION_PIN</code></td>
 *              <td align="center"><span class="entypo-icon-location-pin"></span></td>
 *              <td align="left"><code>ICON_LOCATION_PIN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LOCK</code></td>
 *              <td align="center"><span class="entypo-icon-lock"></span></td>
 *              <td align="left"><code>ICON_LOCK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LOCK_OPEN</code></td>
 *              <td align="center"><span class="entypo-icon-lock-open"></span></td>
 *              <td align="left"><code>ICON_LOCK_OPEN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LOG_OUT</code></td>
 *              <td align="center"><span class="entypo-icon-log-out"></span></td>
 *              <td align="left"><code>ICON_LOG_OUT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_LOGIN</code></td>
 *              <td align="center"><span class="entypo-icon-login"></span></td>
 *              <td align="left"><code>ICON_LOGIN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_LOOP</code></td>
 *              <td align="center"><span class="entypo-icon-loop"></span></td>
 *              <td align="left"><code>ICON_LOOP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MAGNET</code></td>
 *              <td align="center"><span class="entypo-icon-magnet"></span></td>
 *              <td align="left"><code>ICON_MAGNET</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MAGNIFYING_GLASS</code></td>
 *              <td align="center"><span class="entypo-icon-magnifying-glass"></span></td>
 *              <td align="left"><code>ICON_MAGNIFYING_GLASS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MAIL</code></td>
 *              <td align="center"><span class="entypo-icon-mail"></span></td>
 *              <td align="left"><code>ICON_MAIL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MAIL_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-mail-with-circle"></span></td>
 *              <td align="left"><code>ICON_MAIL_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MAN</code></td>
 *              <td align="center"><span class="entypo-icon-man"></span></td>
 *              <td align="left"><code>ICON_MAN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MAP</code></td>
 *              <td align="center"><span class="entypo-icon-map"></span></td>
 *              <td align="left"><code>ICON_MAP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MASK</code></td>
 *              <td align="center"><span class="entypo-icon-mask"></span></td>
 *              <td align="left"><code>ICON_MASK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MEDAL</code></td>
 *              <td align="center"><span class="entypo-icon-medal"></span></td>
 *              <td align="left"><code>ICON_MEDAL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MEDIUM</code></td>
 *              <td align="center"><span class="entypo-icon-medium"></span></td>
 *              <td align="left"><code>ICON_MEDIUM</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MEDIUM_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-medium-with-circle"></span></td>
 *              <td align="left"><code>ICON_MEDIUM_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MEGAPHONE</code></td>
 *              <td align="center"><span class="entypo-icon-megaphone"></span></td>
 *              <td align="left"><code>ICON_MEGAPHONE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MENU</code></td>
 *              <td align="center"><span class="entypo-icon-menu"></span></td>
 *              <td align="left"><code>ICON_MENU</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MERGE</code></td>
 *              <td align="center"><span class="entypo-icon-merge"></span></td>
 *              <td align="left"><code>ICON_MERGE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MESSAGE</code></td>
 *              <td align="center"><span class="entypo-icon-message"></span></td>
 *              <td align="left"><code>ICON_MESSAGE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MIC</code></td>
 *              <td align="center"><span class="entypo-icon-mic"></span></td>
 *              <td align="left"><code>ICON_MIC</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MINUS</code></td>
 *              <td align="center"><span class="entypo-icon-minus"></span></td>
 *              <td align="left"><code>ICON_MINUS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MIXI</code></td>
 *              <td align="center"><span class="entypo-icon-mixi"></span></td>
 *              <td align="left"><code>ICON_MIXI</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MOBILE</code></td>
 *              <td align="center"><span class="entypo-icon-mobile"></span></td>
 *              <td align="left"><code>ICON_MOBILE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MODERN_MIC</code></td>
 *              <td align="center"><span class="entypo-icon-modern-mic"></span></td>
 *              <td align="left"><code>ICON_MODERN_MIC</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MOON</code></td>
 *              <td align="center"><span class="entypo-icon-moon"></span></td>
 *              <td align="left"><code>ICON_MOON</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MOUSE</code></td>
 *              <td align="center"><span class="entypo-icon-mouse"></span></td>
 *              <td align="left"><code>ICON_MOUSE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_MOUSE_POINTER</code></td>
 *              <td align="center"><span class="entypo-icon-mouse-pointer"></span></td>
 *              <td align="left"><code>ICON_MOUSE_POINTER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_MUSIC</code></td>
 *              <td align="center"><span class="entypo-icon-music"></span></td>
 *              <td align="left"><code>ICON_MUSIC</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_NETWORK</code></td>
 *              <td align="center"><span class="entypo-icon-network"></span></td>
 *              <td align="left"><code>ICON_NETWORK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_NEW</code></td>
 *              <td align="center"><span class="entypo-icon-new"></span></td>
 *              <td align="left"><code>ICON_NEW</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_NEW_MESSAGE</code></td>
 *              <td align="center"><span class="entypo-icon-new-message"></span></td>
 *              <td align="left"><code>ICON_NEW_MESSAGE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_NEWS</code></td>
 *              <td align="center"><span class="entypo-icon-news"></span></td>
 *              <td align="left"><code>ICON_NEWS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_NEWSLETTER</code></td>
 *              <td align="center"><span class="entypo-icon-newsletter"></span></td>
 *              <td align="left"><code>ICON_NEWSLETTER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_NOTE</code></td>
 *              <td align="center"><span class="entypo-icon-note"></span></td>
 *              <td align="left"><code>ICON_NOTE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_NOTIFICATION</code></td>
 *              <td align="center"><span class="entypo-icon-notification"></span></td>
 *              <td align="left"><code>ICON_NOTIFICATION</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_NOTIFICATIONS_OFF</code></td>
 *              <td align="center"><span class="entypo-icon-notifications-off"></span></td>
 *              <td align="left"><code>ICON_NOTIFICATIONS_OFF</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_OLD_MOBILE</code></td>
 *              <td align="center"><span class="entypo-icon-old-mobile"></span></td>
 *              <td align="left"><code>ICON_OLD_MOBILE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_OLD_PHONE</code></td>
 *              <td align="center"><span class="entypo-icon-old-phone"></span></td>
 *              <td align="left"><code>ICON_OLD_PHONE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ONEDRIVE</code></td>
 *              <td align="center"><span class="entypo-icon-onedrive"></span></td>
 *              <td align="left"><code>ICON_ONEDRIVE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_OPEN_BOOK</code></td>
 *              <td align="center"><span class="entypo-icon-open-book"></span></td>
 *              <td align="left"><code>ICON_OPEN_BOOK</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PALETTE</code></td>
 *              <td align="center"><span class="entypo-icon-palette"></span></td>
 *              <td align="left"><code>ICON_PALETTE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PAPER_PLANE</code></td>
 *              <td align="center"><span class="entypo-icon-paper-plane"></span></td>
 *              <td align="left"><code>ICON_PAPER_PLANE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PAYPAL</code></td>
 *              <td align="center"><span class="entypo-icon-paypal"></span></td>
 *              <td align="left"><code>ICON_PAYPAL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PENCIL</code></td>
 *              <td align="center"><span class="entypo-icon-pencil"></span></td>
 *              <td align="left"><code>ICON_PENCIL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PHONE</code></td>
 *              <td align="center"><span class="entypo-icon-phone"></span></td>
 *              <td align="left"><code>ICON_PHONE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PICASA</code></td>
 *              <td align="center"><span class="entypo-icon-picasa"></span></td>
 *              <td align="left"><code>ICON_PICASA</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PIE_CHART</code></td>
 *              <td align="center"><span class="entypo-icon-pie-chart"></span></td>
 *              <td align="left"><code>ICON_PIE_CHART</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PIN</code></td>
 *              <td align="center"><span class="entypo-icon-pin"></span></td>
 *              <td align="left"><code>ICON_PIN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PINTEREST</code></td>
 *              <td align="center"><span class="entypo-icon-pinterest"></span></td>
 *              <td align="left"><code>ICON_PINTEREST</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PINTEREST_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-pinterest-with-circle"></span></td>
 *              <td align="left"><code>ICON_PINTEREST_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PLUS</code></td>
 *              <td align="center"><span class="entypo-icon-plus"></span></td>
 *              <td align="left"><code>ICON_PLUS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_POPUP</code></td>
 *              <td align="center"><span class="entypo-icon-popup"></span></td>
 *              <td align="left"><code>ICON_POPUP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_POWER_PLUG</code></td>
 *              <td align="center"><span class="entypo-icon-power-plug"></span></td>
 *              <td align="left"><code>ICON_POWER_PLUG</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PRICE_RIBBON</code></td>
 *              <td align="center"><span class="entypo-icon-price-ribbon"></span></td>
 *              <td align="left"><code>ICON_PRICE_RIBBON</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PRICE_TAG</code></td>
 *              <td align="center"><span class="entypo-icon-price-tag"></span></td>
 *              <td align="left"><code>ICON_PRICE_TAG</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PRINT</code></td>
 *              <td align="center"><span class="entypo-icon-print"></span></td>
 *              <td align="left"><code>ICON_PRINT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PROGRESS_EMPTY</code></td>
 *              <td align="center"><span class="entypo-icon-progress-empty"></span></td>
 *              <td align="left"><code>ICON_PROGRESS_EMPTY</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PROGRESS_FULL</code></td>
 *              <td align="center"><span class="entypo-icon-progress-full"></span></td>
 *              <td align="left"><code>ICON_PROGRESS_FULL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PROGRESS_ONE</code></td>
 *              <td align="center"><span class="entypo-icon-progress-one"></span></td>
 *              <td align="left"><code>ICON_PROGRESS_ONE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_PROGRESS_TWO</code></td>
 *              <td align="center"><span class="entypo-icon-progress-two"></span></td>
 *              <td align="left"><code>ICON_PROGRESS_TWO</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_PUBLISH</code></td>
 *              <td align="center"><span class="entypo-icon-publish"></span></td>
 *              <td align="left"><code>ICON_PUBLISH</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_QQ</code></td>
 *              <td align="center"><span class="entypo-icon-qq"></span></td>
 *              <td align="left"><code>ICON_QQ</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_QQ_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-qq-with-circle"></span></td>
 *              <td align="left"><code>ICON_QQ_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_QUOTE</code></td>
 *              <td align="center"><span class="entypo-icon-quote"></span></td>
 *              <td align="left"><code>ICON_QUOTE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_RADIO</code></td>
 *              <td align="center"><span class="entypo-icon-radio"></span></td>
 *              <td align="left"><code>ICON_RADIO</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_RAFT</code></td>
 *              <td align="center"><span class="entypo-icon-raft"></span></td>
 *              <td align="left"><code>ICON_RAFT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_RAFT_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-raft-with-circle"></span></td>
 *              <td align="left"><code>ICON_RAFT_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_RAINBOW</code></td>
 *              <td align="center"><span class="entypo-icon-rainbow"></span></td>
 *              <td align="left"><code>ICON_RAINBOW</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_RDIO</code></td>
 *              <td align="center"><span class="entypo-icon-rdio"></span></td>
 *              <td align="left"><code>ICON_RDIO</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_RDIO_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-rdio-with-circle"></span></td>
 *              <td align="left"><code>ICON_RDIO_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_REMOVE_USER</code></td>
 *              <td align="center"><span class="entypo-icon-remove-user"></span></td>
 *              <td align="left"><code>ICON_REMOVE_USER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_RENREN</code></td>
 *              <td align="center"><span class="entypo-icon-renren"></span></td>
 *              <td align="left"><code>ICON_RENREN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_REPLY</code></td>
 *              <td align="center"><span class="entypo-icon-reply"></span></td>
 *              <td align="left"><code>ICON_REPLY</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_REPLY_ALL</code></td>
 *              <td align="center"><span class="entypo-icon-reply-all"></span></td>
 *              <td align="left"><code>ICON_REPLY_ALL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_RESIZE_100_PERCENT</code></td>
 *              <td align="center"><span class="entypo-icon-resize-100-percent"></span></td>
 *              <td align="left"><code>ICON_RESIZE_100_PERCENT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_RESIZE_FULL_SCREEN</code></td>
 *              <td align="center"><span class="entypo-icon-resize-full-screen"></span></td>
 *              <td align="left"><code>ICON_RESIZE_FULL_SCREEN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_RETWEET</code></td>
 *              <td align="center"><span class="entypo-icon-retweet"></span></td>
 *              <td align="left"><code>ICON_RETWEET</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_ROCKET</code></td>
 *              <td align="center"><span class="entypo-icon-rocket"></span></td>
 *              <td align="left"><code>ICON_ROCKET</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_ROUND_BRUSH</code></td>
 *              <td align="center"><span class="entypo-icon-round-brush"></span></td>
 *              <td align="left"><code>ICON_ROUND_BRUSH</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_RSS</code></td>
 *              <td align="center"><span class="entypo-icon-rss"></span></td>
 *              <td align="left"><code>ICON_RSS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_RULER</code></td>
 *              <td align="center"><span class="entypo-icon-ruler"></span></td>
 *              <td align="left"><code>ICON_RULER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SAVE</code></td>
 *              <td align="center"><span class="entypo-icon-save"></span></td>
 *              <td align="left"><code>ICON_SAVE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SCISSORS</code></td>
 *              <td align="center"><span class="entypo-icon-scissors"></span></td>
 *              <td align="left"><code>ICON_SCISSORS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SCRIBD</code></td>
 *              <td align="center"><span class="entypo-icon-scribd"></span></td>
 *              <td align="left"><code>ICON_SCRIBD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SELECT_ARROWS</code></td>
 *              <td align="center"><span class="entypo-icon-select-arrows"></span></td>
 *              <td align="left"><code>ICON_SELECT_ARROWS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SHARE</code></td>
 *              <td align="center"><span class="entypo-icon-share"></span></td>
 *              <td align="left"><code>ICON_SHARE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SHARE_ALTERNATIVE</code></td>
 *              <td align="center"><span class="entypo-icon-share-alternative"></span></td>
 *              <td align="left"><code>ICON_SHARE_ALTERNATIVE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SHAREABLE</code></td>
 *              <td align="center"><span class="entypo-icon-shareable"></span></td>
 *              <td align="left"><code>ICON_SHAREABLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SHIELD</code></td>
 *              <td align="center"><span class="entypo-icon-shield"></span></td>
 *              <td align="left"><code>ICON_SHIELD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SHOP</code></td>
 *              <td align="center"><span class="entypo-icon-shop"></span></td>
 *              <td align="left"><code>ICON_SHOP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SHOPPING_BAG</code></td>
 *              <td align="center"><span class="entypo-icon-shopping-bag"></span></td>
 *              <td align="left"><code>ICON_SHOPPING_BAG</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SHOPPING_BASKET</code></td>
 *              <td align="center"><span class="entypo-icon-shopping-basket"></span></td>
 *              <td align="left"><code>ICON_SHOPPING_BASKET</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SHOPPING_CART</code></td>
 *              <td align="center"><span class="entypo-icon-shopping-cart"></span></td>
 *              <td align="left"><code>ICON_SHOPPING_CART</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SHUFFLE</code></td>
 *              <td align="center"><span class="entypo-icon-shuffle"></span></td>
 *              <td align="left"><code>ICON_SHUFFLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SIGNAL</code></td>
 *              <td align="center"><span class="entypo-icon-signal"></span></td>
 *              <td align="left"><code>ICON_SIGNAL</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SINA_WEIBO</code></td>
 *              <td align="center"><span class="entypo-icon-sina-weibo"></span></td>
 *              <td align="left"><code>ICON_SINA_WEIBO</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SKYPE</code></td>
 *              <td align="center"><span class="entypo-icon-skype"></span></td>
 *              <td align="left"><code>ICON_SKYPE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SKYPE_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-skype-with-circle"></span></td>
 *              <td align="left"><code>ICON_SKYPE_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SLIDESHARE</code></td>
 *              <td align="center"><span class="entypo-icon-slideshare"></span></td>
 *              <td align="left"><code>ICON_SLIDESHARE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SMASHING</code></td>
 *              <td align="center"><span class="entypo-icon-smashing"></span></td>
 *              <td align="left"><code>ICON_SMASHING</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SOUND</code></td>
 *              <td align="center"><span class="entypo-icon-sound"></span></td>
 *              <td align="left"><code>ICON_SOUND</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SOUND_MIX</code></td>
 *              <td align="center"><span class="entypo-icon-sound-mix"></span></td>
 *              <td align="left"><code>ICON_SOUND_MIX</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SOUND_MUTE</code></td>
 *              <td align="center"><span class="entypo-icon-sound-mute"></span></td>
 *              <td align="left"><code>ICON_SOUND_MUTE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SOUNDCLOUD</code></td>
 *              <td align="center"><span class="entypo-icon-soundcloud"></span></td>
 *              <td align="left"><code>ICON_SOUNDCLOUD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SPORTS_CLUB</code></td>
 *              <td align="center"><span class="entypo-icon-sports-club"></span></td>
 *              <td align="left"><code>ICON_SPORTS_CLUB</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SPOTIFY</code></td>
 *              <td align="center"><span class="entypo-icon-spotify"></span></td>
 *              <td align="left"><code>ICON_SPOTIFY</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SPOTIFY_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-spotify-with-circle"></span></td>
 *              <td align="left"><code>ICON_SPOTIFY_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SPREADSHEET</code></td>
 *              <td align="center"><span class="entypo-icon-spreadsheet"></span></td>
 *              <td align="left"><code>ICON_SPREADSHEET</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SQUARED_CROSS</code></td>
 *              <td align="center"><span class="entypo-icon-squared-cross"></span></td>
 *              <td align="left"><code>ICON_SQUARED_CROSS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SQUARED_MINUS</code></td>
 *              <td align="center"><span class="entypo-icon-squared-minus"></span></td>
 *              <td align="left"><code>ICON_SQUARED_MINUS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SQUARED_PLUS</code></td>
 *              <td align="center"><span class="entypo-icon-squared-plus"></span></td>
 *              <td align="left"><code>ICON_SQUARED_PLUS</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_STAR</code></td>
 *              <td align="center"><span class="entypo-icon-star"></span></td>
 *              <td align="left"><code>ICON_STAR</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_STAR_OUTLINED</code></td>
 *              <td align="center"><span class="entypo-icon-star-outlined"></span></td>
 *              <td align="left"><code>ICON_STAR_OUTLINED</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_STOPWATCH</code></td>
 *              <td align="center"><span class="entypo-icon-stopwatch"></span></td>
 *              <td align="left"><code>ICON_STOPWATCH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_STUMBLEUPON</code></td>
 *              <td align="center"><span class="entypo-icon-stumbleupon"></span></td>
 *              <td align="left"><code>ICON_STUMBLEUPON</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_STUMBLEUPON_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-stumbleupon-with-circle"></span></td>
 *              <td align="left"><code>ICON_STUMBLEUPON_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SUITCASE</code></td>
 *              <td align="center"><span class="entypo-icon-suitcase"></span></td>
 *              <td align="left"><code>ICON_SUITCASE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SWAP</code></td>
 *              <td align="center"><span class="entypo-icon-swap"></span></td>
 *              <td align="left"><code>ICON_SWAP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SWARM</code></td>
 *              <td align="center"><span class="entypo-icon-swarm"></span></td>
 *              <td align="left"><code>ICON_SWARM</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_SWEDEN</code></td>
 *              <td align="center"><span class="entypo-icon-sweden"></span></td>
 *              <td align="left"><code>ICON_SWEDEN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_SWITCH</code></td>
 *              <td align="center"><span class="entypo-icon-switch"></span></td>
 *              <td align="left"><code>ICON_SWITCH</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TABLET</code></td>
 *              <td align="center"><span class="entypo-icon-tablet"></span></td>
 *              <td align="left"><code>ICON_TABLET</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TABLET_MOBILE_COMBO</code></td>
 *              <td align="center"><span class="entypo-icon-tablet-mobile-combo"></span></td>
 *              <td align="left"><code>ICON_TABLET_MOBILE_COMBO</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TAG</code></td>
 *              <td align="center"><span class="entypo-icon-tag"></span></td>
 *              <td align="left"><code>ICON_TAG</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TEXT</code></td>
 *              <td align="center"><span class="entypo-icon-text"></span></td>
 *              <td align="left"><code>ICON_TEXT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TEXT_DOCUMENT</code></td>
 *              <td align="center"><span class="entypo-icon-text-document"></span></td>
 *              <td align="left"><code>ICON_TEXT_DOCUMENT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TEXT_DOCUMENT_INVERTED</code></td>
 *              <td align="center"><span class="entypo-icon-text-document-inverted"></span></td>
 *              <td align="left"><code>ICON_TEXT_DOCUMENT_INVERTED</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_THERMOMETER</code></td>
 *              <td align="center"><span class="entypo-icon-thermometer"></span></td>
 *              <td align="left"><code>ICON_THERMOMETER</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_THUMBS_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-thumbs-down"></span></td>
 *              <td align="left"><code>ICON_THUMBS_DOWN</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_THUMBS_UP</code></td>
 *              <td align="center"><span class="entypo-icon-thumbs-up"></span></td>
 *              <td align="left"><code>ICON_THUMBS_UP</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_THUNDER_CLOUD</code></td>
 *              <td align="center"><span class="entypo-icon-thunder-cloud"></span></td>
 *              <td align="left"><code>ICON_THUNDER_CLOUD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TICKET</code></td>
 *              <td align="center"><span class="entypo-icon-ticket"></span></td>
 *              <td align="left"><code>ICON_TICKET</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TIME_SLOT</code></td>
 *              <td align="center"><span class="entypo-icon-time-slot"></span></td>
 *              <td align="left"><code>ICON_TIME_SLOT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TOOLS</code></td>
 *              <td align="center"><span class="entypo-icon-tools"></span></td>
 *              <td align="left"><code>ICON_TOOLS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TRAFFIC_CONE</code></td>
 *              <td align="center"><span class="entypo-icon-traffic-cone"></span></td>
 *              <td align="left"><code>ICON_TRAFFIC_CONE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TRASH</code></td>
 *              <td align="center"><span class="entypo-icon-trash"></span></td>
 *              <td align="left"><code>ICON_TRASH</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TREE</code></td>
 *              <td align="center"><span class="entypo-icon-tree"></span></td>
 *              <td align="left"><code>ICON_TREE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TRIANGLE_DOWN</code></td>
 *              <td align="center"><span class="entypo-icon-triangle-down"></span></td>
 *              <td align="left"><code>ICON_TRIANGLE_DOWN</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TRIANGLE_LEFT</code></td>
 *              <td align="center"><span class="entypo-icon-triangle-left"></span></td>
 *              <td align="left"><code>ICON_TRIANGLE_LEFT</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TRIANGLE_RIGHT</code></td>
 *              <td align="center"><span class="entypo-icon-triangle-right"></span></td>
 *              <td align="left"><code>ICON_TRIANGLE_RIGHT</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TRIANGLE_UP</code></td>
 *              <td align="center"><span class="entypo-icon-triangle-up"></span></td>
 *              <td align="left"><code>ICON_TRIANGLE_UP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TRIPADVISOR</code></td>
 *              <td align="center"><span class="entypo-icon-tripadvisor"></span></td>
 *              <td align="left"><code>ICON_TRIPADVISOR</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TROPHY</code></td>
 *              <td align="center"><span class="entypo-icon-trophy"></span></td>
 *              <td align="left"><code>ICON_TROPHY</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TUMBLR</code></td>
 *              <td align="center"><span class="entypo-icon-tumblr"></span></td>
 *              <td align="left"><code>ICON_TUMBLR</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TUMBLR_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-tumblr-with-circle"></span></td>
 *              <td align="left"><code>ICON_TUMBLR_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TV</code></td>
 *              <td align="center"><span class="entypo-icon-tv"></span></td>
 *              <td align="left"><code>ICON_TV</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TWITTER</code></td>
 *              <td align="center"><span class="entypo-icon-twitter"></span></td>
 *              <td align="left"><code>ICON_TWITTER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_TWITTER_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-twitter-with-circle"></span></td>
 *              <td align="left"><code>ICON_TWITTER_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_TYPING</code></td>
 *              <td align="center"><span class="entypo-icon-typing"></span></td>
 *              <td align="left"><code>ICON_TYPING</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_UNINSTALL</code></td>
 *              <td align="center"><span class="entypo-icon-uninstall"></span></td>
 *              <td align="left"><code>ICON_UNINSTALL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_UNREAD</code></td>
 *              <td align="center"><span class="entypo-icon-unread"></span></td>
 *              <td align="left"><code>ICON_UNREAD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_UNTAG</code></td>
 *              <td align="center"><span class="entypo-icon-untag"></span></td>
 *              <td align="left"><code>ICON_UNTAG</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_UPLOAD</code></td>
 *              <td align="center"><span class="entypo-icon-upload"></span></td>
 *              <td align="left"><code>ICON_UPLOAD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_UPLOAD_TO_CLOUD</code></td>
 *              <td align="center"><span class="entypo-icon-upload-to-cloud"></span></td>
 *              <td align="left"><code>ICON_UPLOAD_TO_CLOUD</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_USER</code></td>
 *              <td align="center"><span class="entypo-icon-user"></span></td>
 *              <td align="left"><code>ICON_USER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_USERS</code></td>
 *              <td align="center"><span class="entypo-icon-users"></span></td>
 *              <td align="left"><code>ICON_USERS</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_V_CARD</code></td>
 *              <td align="center"><span class="entypo-icon-v-card"></span></td>
 *              <td align="left"><code>ICON_V_CARD</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_VIDEO</code></td>
 *              <td align="center"><span class="entypo-icon-video"></span></td>
 *              <td align="left"><code>ICON_VIDEO</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_VIDEO_CAMERA</code></td>
 *              <td align="center"><span class="entypo-icon-video-camera"></span></td>
 *              <td align="left"><code>ICON_VIDEO_CAMERA</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_VIMEO</code></td>
 *              <td align="center"><span class="entypo-icon-vimeo"></span></td>
 *              <td align="left"><code>ICON_VIMEO</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_VIMEO_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-vimeo-with-circle"></span></td>
 *              <td align="left"><code>ICON_VIMEO_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_VINE</code></td>
 *              <td align="center"><span class="entypo-icon-vine"></span></td>
 *              <td align="left"><code>ICON_VINE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_VINE_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-vine-with-circle"></span></td>
 *              <td align="left"><code>ICON_VINE_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_VINYL</code></td>
 *              <td align="center"><span class="entypo-icon-vinyl"></span></td>
 *              <td align="left"><code>ICON_VINYL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_VK</code></td>
 *              <td align="center"><span class="entypo-icon-vk"></span></td>
 *              <td align="left"><code>ICON_VK</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_VK_ALTERNITIVE</code></td>
 *              <td align="center"><span class="entypo-icon-vk-alternitive"></span></td>
 *              <td align="left"><code>ICON_VK_ALTERNITIVE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_VK_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-vk-with-circle"></span></td>
 *              <td align="left"><code>ICON_VK_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_VOICEMAIL</code></td>
 *              <td align="center"><span class="entypo-icon-voicemail"></span></td>
 *              <td align="left"><code>ICON_VOICEMAIL</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_WALLET</code></td>
 *              <td align="center"><span class="entypo-icon-wallet"></span></td>
 *              <td align="left"><code>ICON_WALLET</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_WARNING</code></td>
 *              <td align="center"><span class="entypo-icon-warning"></span></td>
 *              <td align="left"><code>ICON_WARNING</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_WATER</code></td>
 *              <td align="center"><span class="entypo-icon-water"></span></td>
 *              <td align="left"><code>ICON_WATER</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_WINDOWS_STORE</code></td>
 *              <td align="center"><span class="entypo-icon-windows-store"></span></td>
 *              <td align="left"><code>ICON_WINDOWS_STORE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_XING</code></td>
 *              <td align="center"><span class="entypo-icon-xing"></span></td>
 *              <td align="left"><code>ICON_XING</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_XING_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-xing-with-circle"></span></td>
 *              <td align="left"><code>ICON_XING_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_YELP</code></td>
 *              <td align="center"><span class="entypo-icon-yelp"></span></td>
 *              <td align="left"><code>ICON_YELP</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_YOUKO</code></td>
 *              <td align="center"><span class="entypo-icon-youko"></span></td>
 *              <td align="left"><code>ICON_YOUKO</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_YOUKO_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-youko-with-circle"></span></td>
 *              <td align="left"><code>ICON_YOUKO_WITH_CIRCLE</code>
 *            </tr>
 *            <tr class="row-odd">
 *              <td align="right"><code>ENTYPO_ICON_YOUTUBE</code></td>
 *              <td align="center"><span class="entypo-icon-youtube"></span></td>
 *              <td align="left"><code>ICON_YOUTUBE</code>
 *            </tr>
 *            <tr class="row-even">
 *              <td align="right"><code>ENTYPO_ICON_YOUTUBE_WITH_CIRCLE</code></td>
 *              <td align="center"><span class="entypo-icon-youtube-with-circle"></span></td>
 *              <td align="left"><code>ICON_YOUTUBE_WITH_CIRCLE</code>
 *            </tr>
 *          </tbody>
 *        </table>
 *      </div><!-- wy-table-responsive -->
 *    </center>
 *
 * \endrst
 */

#pragma once

// prevent individual pages from being generated for all of these
#if !defined(DOXYGEN_SHOULD_SKIP_THIS)

#define ENTYPO_ICON_500PX                             "\uF100"
#define ENTYPO_ICON_500PX_WITH_CIRCLE                 "\uF101"
#define ENTYPO_ICON_ADD_TO_LIST                       "\uF102"
#define ENTYPO_ICON_ADD_USER                          "\uF103"
#define ENTYPO_ICON_ADDRESS                           "\uF104"
#define ENTYPO_ICON_ADJUST                            "\uF105"
#define ENTYPO_ICON_AIR                               "\uF106"
#define ENTYPO_ICON_AIRCRAFT                          "\uF107"
#define ENTYPO_ICON_AIRCRAFT_LANDING                  "\uF108"
#define ENTYPO_ICON_AIRCRAFT_TAKE_OFF                 "\uF109"
#define ENTYPO_ICON_ALIGN_BOTTOM                      "\uF10A"
#define ENTYPO_ICON_ALIGN_HORIZONTAL_MIDDLE           "\uF10B"
#define ENTYPO_ICON_ALIGN_LEFT                        "\uF10C"
#define ENTYPO_ICON_ALIGN_RIGHT                       "\uF10D"
#define ENTYPO_ICON_ALIGN_TOP                         "\uF10E"
#define ENTYPO_ICON_ALIGN_VERTICAL_MIDDLE             "\uF10F"
#define ENTYPO_ICON_APP_STORE                         "\uF110"
#define ENTYPO_ICON_ARCHIVE                           "\uF111"
#define ENTYPO_ICON_AREA_GRAPH                        "\uF112"
#define ENTYPO_ICON_ARROW_BOLD_DOWN                   "\uF113"
#define ENTYPO_ICON_ARROW_BOLD_LEFT                   "\uF114"
#define ENTYPO_ICON_ARROW_BOLD_RIGHT                  "\uF115"
#define ENTYPO_ICON_ARROW_BOLD_UP                     "\uF116"
#define ENTYPO_ICON_ARROW_DOWN                        "\uF117"
#define ENTYPO_ICON_ARROW_LEFT                        "\uF118"
#define ENTYPO_ICON_ARROW_LONG_DOWN                   "\uF119"
#define ENTYPO_ICON_ARROW_LONG_LEFT                   "\uF11A"
#define ENTYPO_ICON_ARROW_LONG_RIGHT                  "\uF11B"
#define ENTYPO_ICON_ARROW_LONG_UP                     "\uF11C"
#define ENTYPO_ICON_ARROW_RIGHT                       "\uF11D"
#define ENTYPO_ICON_ARROW_UP                          "\uF11E"
#define ENTYPO_ICON_ARROW_WITH_CIRCLE_DOWN            "\uF11F"
#define ENTYPO_ICON_ARROW_WITH_CIRCLE_LEFT            "\uF120"
#define ENTYPO_ICON_ARROW_WITH_CIRCLE_RIGHT           "\uF121"
#define ENTYPO_ICON_ARROW_WITH_CIRCLE_UP              "\uF122"
#define ENTYPO_ICON_ATTACHMENT                        "\uF123"
#define ENTYPO_ICON_AWARENESS_RIBBON                  "\uF124"
#define ENTYPO_ICON_BACK                              "\uF125"
#define ENTYPO_ICON_BACK_IN_TIME                      "\uF126"
#define ENTYPO_ICON_BAIDU                             "\uF127"
#define ENTYPO_ICON_BAR_GRAPH                         "\uF128"
#define ENTYPO_ICON_BASECAMP                          "\uF129"
#define ENTYPO_ICON_BATTERY                           "\uF12A"
#define ENTYPO_ICON_BEAMED_NOTE                       "\uF12B"
#define ENTYPO_ICON_BEHANCE                           "\uF12C"
#define ENTYPO_ICON_BELL                              "\uF12D"
#define ENTYPO_ICON_BLACKBOARD                        "\uF12E"
#define ENTYPO_ICON_BLOCK                             "\uF12F"
#define ENTYPO_ICON_BOOK                              "\uF130"
#define ENTYPO_ICON_BOOKMARK                          "\uF131"
#define ENTYPO_ICON_BOOKMARKS                         "\uF132"
#define ENTYPO_ICON_BOWL                              "\uF133"
#define ENTYPO_ICON_BOX                               "\uF134"
#define ENTYPO_ICON_BRIEFCASE                         "\uF135"
#define ENTYPO_ICON_BROWSER                           "\uF136"
#define ENTYPO_ICON_BRUSH                             "\uF137"
#define ENTYPO_ICON_BUCKET                            "\uF138"
#define ENTYPO_ICON_BUG                               "\uF139"
#define ENTYPO_ICON_CAKE                              "\uF13A"
#define ENTYPO_ICON_CALCULATOR                        "\uF13B"
#define ENTYPO_ICON_CALENDAR                          "\uF13C"
#define ENTYPO_ICON_CAMERA                            "\uF13D"
#define ENTYPO_ICON_CCW                               "\uF13E"
#define ENTYPO_ICON_CHAT                              "\uF13F"
#define ENTYPO_ICON_CHECK                             "\uF140"
#define ENTYPO_ICON_CHEVRON_DOWN                      "\uF141"
#define ENTYPO_ICON_CHEVRON_LEFT                      "\uF142"
#define ENTYPO_ICON_CHEVRON_RIGHT                     "\uF143"
#define ENTYPO_ICON_CHEVRON_SMALL_DOWN                "\uF144"
#define ENTYPO_ICON_CHEVRON_SMALL_LEFT                "\uF145"
#define ENTYPO_ICON_CHEVRON_SMALL_RIGHT               "\uF146"
#define ENTYPO_ICON_CHEVRON_SMALL_UP                  "\uF147"
#define ENTYPO_ICON_CHEVRON_THIN_DOWN                 "\uF148"
#define ENTYPO_ICON_CHEVRON_THIN_LEFT                 "\uF149"
#define ENTYPO_ICON_CHEVRON_THIN_RIGHT                "\uF14A"
#define ENTYPO_ICON_CHEVRON_THIN_UP                   "\uF14B"
#define ENTYPO_ICON_CHEVRON_UP                        "\uF14C"
#define ENTYPO_ICON_CHEVRON_WITH_CIRCLE_DOWN          "\uF14D"
#define ENTYPO_ICON_CHEVRON_WITH_CIRCLE_LEFT          "\uF14E"
#define ENTYPO_ICON_CHEVRON_WITH_CIRCLE_RIGHT         "\uF14F"
#define ENTYPO_ICON_CHEVRON_WITH_CIRCLE_UP            "\uF150"
#define ENTYPO_ICON_CIRCLE                            "\uF151"
#define ENTYPO_ICON_CIRCLE_WITH_CROSS                 "\uF152"
#define ENTYPO_ICON_CIRCLE_WITH_MINUS                 "\uF153"
#define ENTYPO_ICON_CIRCLE_WITH_PLUS                  "\uF154"
#define ENTYPO_ICON_CIRCULAR_GRAPH                    "\uF155"
#define ENTYPO_ICON_CLAPPERBOARD                      "\uF156"
#define ENTYPO_ICON_CLASSIC_COMPUTER                  "\uF157"
#define ENTYPO_ICON_CLIPBOARD                         "\uF158"
#define ENTYPO_ICON_CLOCK                             "\uF159"
#define ENTYPO_ICON_CLOUD                             "\uF15A"
#define ENTYPO_ICON_CODE                              "\uF15B"
#define ENTYPO_ICON_COG                               "\uF15C"
#define ENTYPO_ICON_COLOURS                           "\uF15D"
#define ENTYPO_ICON_COMPASS                           "\uF15E"
#define ENTYPO_ICON_CONTROLLER_FAST_BACKWARD          "\uF15F"
#define ENTYPO_ICON_CONTROLLER_FAST_FORWARD           "\uF160"
#define ENTYPO_ICON_CONTROLLER_JUMP_TO_START          "\uF161"
#define ENTYPO_ICON_CONTROLLER_NEXT                   "\uF162"
#define ENTYPO_ICON_CONTROLLER_PAUS                   "\uF163"
#define ENTYPO_ICON_CONTROLLER_PLAY                   "\uF164"
#define ENTYPO_ICON_CONTROLLER_RECORD                 "\uF165"
#define ENTYPO_ICON_CONTROLLER_STOP                   "\uF166"
#define ENTYPO_ICON_CONTROLLER_VOLUME                 "\uF167"
#define ENTYPO_ICON_COPY                              "\uF168"
#define ENTYPO_ICON_CREATIVE_CLOUD                    "\uF169"
#define ENTYPO_ICON_CREATIVE_COMMONS                  "\uF16A"
#define ENTYPO_ICON_CREATIVE_COMMONS_ATTRIBUTION      "\uF16B"
#define ENTYPO_ICON_CREATIVE_COMMONS_NODERIVS         "\uF16C"
#define ENTYPO_ICON_CREATIVE_COMMONS_NONCOMMERCIAL_EU "\uF16D"
#define ENTYPO_ICON_CREATIVE_COMMONS_NONCOMMERCIAL_US "\uF16E"
#define ENTYPO_ICON_CREATIVE_COMMONS_PUBLIC_DOMAIN    "\uF16F"
#define ENTYPO_ICON_CREATIVE_COMMONS_REMIX            "\uF170"
#define ENTYPO_ICON_CREATIVE_COMMONS_SHARE            "\uF171"
#define ENTYPO_ICON_CREATIVE_COMMONS_SHAREALIKE       "\uF172"
#define ENTYPO_ICON_CREDIT                            "\uF173"
#define ENTYPO_ICON_CREDIT_CARD                       "\uF174"
#define ENTYPO_ICON_CROP                              "\uF175"
#define ENTYPO_ICON_CROSS                             "\uF176"
#define ENTYPO_ICON_CUP                               "\uF177"
#define ENTYPO_ICON_CW                                "\uF178"
#define ENTYPO_ICON_CYCLE                             "\uF179"
#define ENTYPO_ICON_DATABASE                          "\uF17A"
#define ENTYPO_ICON_DIAL_PAD                          "\uF17B"
#define ENTYPO_ICON_DIRECTION                         "\uF17C"
#define ENTYPO_ICON_DOCUMENT                          "\uF17D"
#define ENTYPO_ICON_DOCUMENT_LANDSCAPE                "\uF17E"
#define ENTYPO_ICON_DOCUMENTS                         "\uF17F"
#define ENTYPO_ICON_DOT_SINGLE                        "\uF180"
#define ENTYPO_ICON_DOTS_THREE_HORIZONTAL             "\uF181"
#define ENTYPO_ICON_DOTS_THREE_VERTICAL               "\uF182"
#define ENTYPO_ICON_DOTS_TWO_HORIZONTAL               "\uF183"
#define ENTYPO_ICON_DOTS_TWO_VERTICAL                 "\uF184"
#define ENTYPO_ICON_DOWNLOAD                          "\uF185"
#define ENTYPO_ICON_DRIBBBLE                          "\uF186"
#define ENTYPO_ICON_DRIBBBLE_WITH_CIRCLE              "\uF187"
#define ENTYPO_ICON_DRINK                             "\uF188"
#define ENTYPO_ICON_DRIVE                             "\uF189"
#define ENTYPO_ICON_DROP                              "\uF18A"
#define ENTYPO_ICON_DROPBOX                           "\uF18B"
#define ENTYPO_ICON_EDIT                              "\uF18C"
#define ENTYPO_ICON_EMAIL                             "\uF18D"
#define ENTYPO_ICON_EMOJI_FLIRT                       "\uF18E"
#define ENTYPO_ICON_EMOJI_HAPPY                       "\uF18F"
#define ENTYPO_ICON_EMOJI_NEUTRAL                     "\uF190"
#define ENTYPO_ICON_EMOJI_SAD                         "\uF191"
#define ENTYPO_ICON_ERASE                             "\uF192"
#define ENTYPO_ICON_ERASER                            "\uF193"
#define ENTYPO_ICON_EVERNOTE                          "\uF194"
#define ENTYPO_ICON_EXPORT                            "\uF195"
#define ENTYPO_ICON_EYE                               "\uF196"
#define ENTYPO_ICON_EYE_WITH_LINE                     "\uF197"
#define ENTYPO_ICON_FACEBOOK                          "\uF198"
#define ENTYPO_ICON_FACEBOOK_WITH_CIRCLE              "\uF199"
#define ENTYPO_ICON_FEATHER                           "\uF19A"
#define ENTYPO_ICON_FINGERPRINT                       "\uF19B"
#define ENTYPO_ICON_FLAG                              "\uF19C"
#define ENTYPO_ICON_FLASH                             "\uF19D"
#define ENTYPO_ICON_FLASHLIGHT                        "\uF19E"
#define ENTYPO_ICON_FLAT_BRUSH                        "\uF19F"
#define ENTYPO_ICON_FLATTR                            "\uF1A0"
#define ENTYPO_ICON_FLICKR                            "\uF1A1"
#define ENTYPO_ICON_FLICKR_WITH_CIRCLE                "\uF1A2"
#define ENTYPO_ICON_FLOW_BRANCH                       "\uF1A3"
#define ENTYPO_ICON_FLOW_CASCADE                      "\uF1A4"
#define ENTYPO_ICON_FLOW_LINE                         "\uF1A5"
#define ENTYPO_ICON_FLOW_PARALLEL                     "\uF1A6"
#define ENTYPO_ICON_FLOW_TREE                         "\uF1A7"
#define ENTYPO_ICON_FLOWER                            "\uF1A8"
#define ENTYPO_ICON_FOLDER                            "\uF1A9"
#define ENTYPO_ICON_FOLDER_IMAGES                     "\uF1AA"
#define ENTYPO_ICON_FOLDER_MUSIC                      "\uF1AB"
#define ENTYPO_ICON_FOLDER_VIDEO                      "\uF1AC"
#define ENTYPO_ICON_FORWARD                           "\uF1AD"
#define ENTYPO_ICON_FOURSQUARE                        "\uF1AE"
#define ENTYPO_ICON_FUNNEL                            "\uF1AF"
#define ENTYPO_ICON_GAME_CONTROLLER                   "\uF1B0"
#define ENTYPO_ICON_GAUGE                             "\uF1B1"
#define ENTYPO_ICON_GITHUB                            "\uF1B2"
#define ENTYPO_ICON_GITHUB_WITH_CIRCLE                "\uF1B3"
#define ENTYPO_ICON_GLOBE                             "\uF1B4"
#define ENTYPO_ICON_GOOGLE_DRIVE                      "\uF1B5"
#define ENTYPO_ICON_GOOGLE_HANGOUTS                   "\uF1B6"
#define ENTYPO_ICON_GOOGLE_PLAY                       "\uF1B7"
#define ENTYPO_ICON_GOOGLE_PLUS                       "\uF1B8"
#define ENTYPO_ICON_GOOGLE_PLUS_WITH_CIRCLE           "\uF1B9"
#define ENTYPO_ICON_GRADUATION_CAP                    "\uF1BA"
#define ENTYPO_ICON_GRID                              "\uF1BB"
#define ENTYPO_ICON_GROOVESHARK                       "\uF1BC"
#define ENTYPO_ICON_HAIR_CROSS                        "\uF1BD"
#define ENTYPO_ICON_HAND                              "\uF1BE"
#define ENTYPO_ICON_HEART                             "\uF1BF"
#define ENTYPO_ICON_HEART_OUTLINED                    "\uF1C0"
#define ENTYPO_ICON_HELP                              "\uF1C1"
#define ENTYPO_ICON_HELP_WITH_CIRCLE                  "\uF1C2"
#define ENTYPO_ICON_HOME                              "\uF1C3"
#define ENTYPO_ICON_HOUR_GLASS                        "\uF1C4"
#define ENTYPO_ICON_HOUZZ                             "\uF1C5"
#define ENTYPO_ICON_ICLOUD                            "\uF1C6"
#define ENTYPO_ICON_IMAGE                             "\uF1C7"
#define ENTYPO_ICON_IMAGE_INVERTED                    "\uF1C8"
#define ENTYPO_ICON_IMAGES                            "\uF1C9"
#define ENTYPO_ICON_INBOX                             "\uF1CA"
#define ENTYPO_ICON_INFINITY                          "\uF1CB"
#define ENTYPO_ICON_INFO                              "\uF1CC"
#define ENTYPO_ICON_INFO_WITH_CIRCLE                  "\uF1CD"
#define ENTYPO_ICON_INSTAGRAM                         "\uF1CE"
#define ENTYPO_ICON_INSTAGRAM_WITH_CIRCLE             "\uF1CF"
#define ENTYPO_ICON_INSTALL                           "\uF1D0"
#define ENTYPO_ICON_KEY                               "\uF1D1"
#define ENTYPO_ICON_KEYBOARD                          "\uF1D2"
#define ENTYPO_ICON_LAB_FLASK                         "\uF1D3"
#define ENTYPO_ICON_LANDLINE                          "\uF1D4"
#define ENTYPO_ICON_LANGUAGE                          "\uF1D5"
#define ENTYPO_ICON_LAPTOP                            "\uF1D6"
#define ENTYPO_ICON_LASTFM                            "\uF1D7"
#define ENTYPO_ICON_LASTFM_WITH_CIRCLE                "\uF1D8"
#define ENTYPO_ICON_LAYERS                            "\uF1D9"
#define ENTYPO_ICON_LEAF                              "\uF1DA"
#define ENTYPO_ICON_LEVEL_DOWN                        "\uF1DB"
#define ENTYPO_ICON_LEVEL_UP                          "\uF1DC"
#define ENTYPO_ICON_LIFEBUOY                          "\uF1DD"
#define ENTYPO_ICON_LIGHT_BULB                        "\uF1DE"
#define ENTYPO_ICON_LIGHT_DOWN                        "\uF1DF"
#define ENTYPO_ICON_LIGHT_UP                          "\uF1E0"
#define ENTYPO_ICON_LINE_GRAPH                        "\uF1E1"
#define ENTYPO_ICON_LINK                              "\uF1E2"
#define ENTYPO_ICON_LINKEDIN                          "\uF1E3"
#define ENTYPO_ICON_LINKEDIN_WITH_CIRCLE              "\uF1E4"
#define ENTYPO_ICON_LIST                              "\uF1E5"
#define ENTYPO_ICON_LOCATION                          "\uF1E6"
#define ENTYPO_ICON_LOCATION_PIN                      "\uF1E7"
#define ENTYPO_ICON_LOCK                              "\uF1E8"
#define ENTYPO_ICON_LOCK_OPEN                         "\uF1E9"
#define ENTYPO_ICON_LOG_OUT                           "\uF1EA"
#define ENTYPO_ICON_LOGIN                             "\uF1EB"
#define ENTYPO_ICON_LOOP                              "\uF1EC"
#define ENTYPO_ICON_MAGNET                            "\uF1ED"
#define ENTYPO_ICON_MAGNIFYING_GLASS                  "\uF1EE"
#define ENTYPO_ICON_MAIL                              "\uF1EF"
#define ENTYPO_ICON_MAIL_WITH_CIRCLE                  "\uF1F0"
#define ENTYPO_ICON_MAN                               "\uF1F1"
#define ENTYPO_ICON_MAP                               "\uF1F2"
#define ENTYPO_ICON_MASK                              "\uF1F3"
#define ENTYPO_ICON_MEDAL                             "\uF1F4"
#define ENTYPO_ICON_MEDIUM                            "\uF1F5"
#define ENTYPO_ICON_MEDIUM_WITH_CIRCLE                "\uF1F6"
#define ENTYPO_ICON_MEGAPHONE                         "\uF1F7"
#define ENTYPO_ICON_MENU                              "\uF1F8"
#define ENTYPO_ICON_MERGE                             "\uF1F9"
#define ENTYPO_ICON_MESSAGE                           "\uF1FA"
#define ENTYPO_ICON_MIC                               "\uF1FB"
#define ENTYPO_ICON_MINUS                             "\uF1FC"
#define ENTYPO_ICON_MIXI                              "\uF1FD"
#define ENTYPO_ICON_MOBILE                            "\uF1FE"
#define ENTYPO_ICON_MODERN_MIC                        "\uF1FF"
#define ENTYPO_ICON_MOON                              "\uF200"
#define ENTYPO_ICON_MOUSE                             "\uF201"
#define ENTYPO_ICON_MOUSE_POINTER                     "\uF202"
#define ENTYPO_ICON_MUSIC                             "\uF203"
#define ENTYPO_ICON_NETWORK                           "\uF204"
#define ENTYPO_ICON_NEW                               "\uF205"
#define ENTYPO_ICON_NEW_MESSAGE                       "\uF206"
#define ENTYPO_ICON_NEWS                              "\uF207"
#define ENTYPO_ICON_NEWSLETTER                        "\uF208"
#define ENTYPO_ICON_NOTE                              "\uF209"
#define ENTYPO_ICON_NOTIFICATION                      "\uF20A"
#define ENTYPO_ICON_NOTIFICATIONS_OFF                 "\uF20B"
#define ENTYPO_ICON_OLD_MOBILE                        "\uF20C"
#define ENTYPO_ICON_OLD_PHONE                         "\uF20D"
#define ENTYPO_ICON_ONEDRIVE                          "\uF20E"
#define ENTYPO_ICON_OPEN_BOOK                         "\uF20F"
#define ENTYPO_ICON_PALETTE                           "\uF210"
#define ENTYPO_ICON_PAPER_PLANE                       "\uF211"
#define ENTYPO_ICON_PAYPAL                            "\uF212"
#define ENTYPO_ICON_PENCIL                            "\uF213"
#define ENTYPO_ICON_PHONE                             "\uF214"
#define ENTYPO_ICON_PICASA                            "\uF215"
#define ENTYPO_ICON_PIE_CHART                         "\uF216"
#define ENTYPO_ICON_PIN                               "\uF217"
#define ENTYPO_ICON_PINTEREST                         "\uF218"
#define ENTYPO_ICON_PINTEREST_WITH_CIRCLE             "\uF219"
#define ENTYPO_ICON_PLUS                              "\uF21A"
#define ENTYPO_ICON_POPUP                             "\uF21B"
#define ENTYPO_ICON_POWER_PLUG                        "\uF21C"
#define ENTYPO_ICON_PRICE_RIBBON                      "\uF21D"
#define ENTYPO_ICON_PRICE_TAG                         "\uF21E"
#define ENTYPO_ICON_PRINT                             "\uF21F"
#define ENTYPO_ICON_PROGRESS_EMPTY                    "\uF220"
#define ENTYPO_ICON_PROGRESS_FULL                     "\uF221"
#define ENTYPO_ICON_PROGRESS_ONE                      "\uF222"
#define ENTYPO_ICON_PROGRESS_TWO                      "\uF223"
#define ENTYPO_ICON_PUBLISH                           "\uF224"
#define ENTYPO_ICON_QQ                                "\uF225"
#define ENTYPO_ICON_QQ_WITH_CIRCLE                    "\uF226"
#define ENTYPO_ICON_QUOTE                             "\uF227"
#define ENTYPO_ICON_RADIO                             "\uF228"
#define ENTYPO_ICON_RAFT                              "\uF229"
#define ENTYPO_ICON_RAFT_WITH_CIRCLE                  "\uF22A"
#define ENTYPO_ICON_RAINBOW                           "\uF22B"
#define ENTYPO_ICON_RDIO                              "\uF22C"
#define ENTYPO_ICON_RDIO_WITH_CIRCLE                  "\uF22D"
#define ENTYPO_ICON_REMOVE_USER                       "\uF22E"
#define ENTYPO_ICON_RENREN                            "\uF22F"
#define ENTYPO_ICON_REPLY                             "\uF230"
#define ENTYPO_ICON_REPLY_ALL                         "\uF231"
#define ENTYPO_ICON_RESIZE_100_PERCENT                "\uF232"
#define ENTYPO_ICON_RESIZE_FULL_SCREEN                "\uF233"
#define ENTYPO_ICON_RETWEET                           "\uF234"
#define ENTYPO_ICON_ROCKET                            "\uF235"
#define ENTYPO_ICON_ROUND_BRUSH                       "\uF236"
#define ENTYPO_ICON_RSS                               "\uF237"
#define ENTYPO_ICON_RULER                             "\uF238"
#define ENTYPO_ICON_SAVE                              "\uF239"
#define ENTYPO_ICON_SCISSORS                          "\uF23A"
#define ENTYPO_ICON_SCRIBD                            "\uF23B"
#define ENTYPO_ICON_SELECT_ARROWS                     "\uF23C"
#define ENTYPO_ICON_SHARE                             "\uF23D"
#define ENTYPO_ICON_SHARE_ALTERNATIVE                 "\uF23E"
#define ENTYPO_ICON_SHAREABLE                         "\uF23F"
#define ENTYPO_ICON_SHIELD                            "\uF240"
#define ENTYPO_ICON_SHOP                              "\uF241"
#define ENTYPO_ICON_SHOPPING_BAG                      "\uF242"
#define ENTYPO_ICON_SHOPPING_BASKET                   "\uF243"
#define ENTYPO_ICON_SHOPPING_CART                     "\uF244"
#define ENTYPO_ICON_SHUFFLE                           "\uF245"
#define ENTYPO_ICON_SIGNAL                            "\uF246"
#define ENTYPO_ICON_SINA_WEIBO                        "\uF247"
#define ENTYPO_ICON_SKYPE                             "\uF248"
#define ENTYPO_ICON_SKYPE_WITH_CIRCLE                 "\uF249"
#define ENTYPO_ICON_SLIDESHARE                        "\uF24A"
#define ENTYPO_ICON_SMASHING                          "\uF24B"
#define ENTYPO_ICON_SOUND                             "\uF24C"
#define ENTYPO_ICON_SOUND_MIX                         "\uF24D"
#define ENTYPO_ICON_SOUND_MUTE                        "\uF24E"
#define ENTYPO_ICON_SOUNDCLOUD                        "\uF24F"
#define ENTYPO_ICON_SPORTS_CLUB                       "\uF250"
#define ENTYPO_ICON_SPOTIFY                           "\uF251"
#define ENTYPO_ICON_SPOTIFY_WITH_CIRCLE               "\uF252"
#define ENTYPO_ICON_SPREADSHEET                       "\uF253"
#define ENTYPO_ICON_SQUARED_CROSS                     "\uF254"
#define ENTYPO_ICON_SQUARED_MINUS                     "\uF255"
#define ENTYPO_ICON_SQUARED_PLUS                      "\uF256"
#define ENTYPO_ICON_STAR                              "\uF257"
#define ENTYPO_ICON_STAR_OUTLINED                     "\uF258"
#define ENTYPO_ICON_STOPWATCH                         "\uF259"
#define ENTYPO_ICON_STUMBLEUPON                       "\uF25A"
#define ENTYPO_ICON_STUMBLEUPON_WITH_CIRCLE           "\uF25B"
#define ENTYPO_ICON_SUITCASE                          "\uF25C"
#define ENTYPO_ICON_SWAP                              "\uF25D"
#define ENTYPO_ICON_SWARM                             "\uF25E"
#define ENTYPO_ICON_SWEDEN                            "\uF25F"
#define ENTYPO_ICON_SWITCH                            "\uF260"
#define ENTYPO_ICON_TABLET                            "\uF261"
#define ENTYPO_ICON_TABLET_MOBILE_COMBO               "\uF262"
#define ENTYPO_ICON_TAG                               "\uF263"
#define ENTYPO_ICON_TEXT                              "\uF264"
#define ENTYPO_ICON_TEXT_DOCUMENT                     "\uF265"
#define ENTYPO_ICON_TEXT_DOCUMENT_INVERTED            "\uF266"
#define ENTYPO_ICON_THERMOMETER                       "\uF267"
#define ENTYPO_ICON_THUMBS_DOWN                       "\uF268"
#define ENTYPO_ICON_THUMBS_UP                         "\uF269"
#define ENTYPO_ICON_THUNDER_CLOUD                     "\uF26A"
#define ENTYPO_ICON_TICKET                            "\uF26B"
#define ENTYPO_ICON_TIME_SLOT                         "\uF26C"
#define ENTYPO_ICON_TOOLS                             "\uF26D"
#define ENTYPO_ICON_TRAFFIC_CONE                      "\uF26E"
#define ENTYPO_ICON_TRASH                             "\uF26F"
#define ENTYPO_ICON_TREE                              "\uF270"
#define ENTYPO_ICON_TRIANGLE_DOWN                     "\uF271"
#define ENTYPO_ICON_TRIANGLE_LEFT                     "\uF272"
#define ENTYPO_ICON_TRIANGLE_RIGHT                    "\uF273"
#define ENTYPO_ICON_TRIANGLE_UP                       "\uF274"
#define ENTYPO_ICON_TRIPADVISOR                       "\uF275"
#define ENTYPO_ICON_TROPHY                            "\uF276"
#define ENTYPO_ICON_TUMBLR                            "\uF277"
#define ENTYPO_ICON_TUMBLR_WITH_CIRCLE                "\uF278"
#define ENTYPO_ICON_TV                                "\uF279"
#define ENTYPO_ICON_TWITTER                           "\uF27A"
#define ENTYPO_ICON_TWITTER_WITH_CIRCLE               "\uF27B"
#define ENTYPO_ICON_TYPING                            "\uF27C"
#define ENTYPO_ICON_UNINSTALL                         "\uF27D"
#define ENTYPO_ICON_UNREAD                            "\uF27E"
#define ENTYPO_ICON_UNTAG                             "\uF27F"
#define ENTYPO_ICON_UPLOAD                            "\uF280"
#define ENTYPO_ICON_UPLOAD_TO_CLOUD                   "\uF281"
#define ENTYPO_ICON_USER                              "\uF282"
#define ENTYPO_ICON_USERS                             "\uF283"
#define ENTYPO_ICON_V_CARD                            "\uF284"
#define ENTYPO_ICON_VIDEO                             "\uF285"
#define ENTYPO_ICON_VIDEO_CAMERA                      "\uF286"
#define ENTYPO_ICON_VIMEO                             "\uF287"
#define ENTYPO_ICON_VIMEO_WITH_CIRCLE                 "\uF288"
#define ENTYPO_ICON_VINE                              "\uF289"
#define ENTYPO_ICON_VINE_WITH_CIRCLE                  "\uF28A"
#define ENTYPO_ICON_VINYL                             "\uF28B"
#define ENTYPO_ICON_VK                                "\uF28C"
#define ENTYPO_ICON_VK_ALTERNITIVE                    "\uF28D"
#define ENTYPO_ICON_VK_WITH_CIRCLE                    "\uF28E"
#define ENTYPO_ICON_VOICEMAIL                         "\uF28F"
#define ENTYPO_ICON_WALLET                            "\uF290"
#define ENTYPO_ICON_WARNING                           "\uF291"
#define ENTYPO_ICON_WATER                             "\uF292"
#define ENTYPO_ICON_WINDOWS_STORE                     "\uF293"
#define ENTYPO_ICON_XING                              "\uF294"
#define ENTYPO_ICON_XING_WITH_CIRCLE                  "\uF295"
#define ENTYPO_ICON_YELP                              "\uF296"
#define ENTYPO_ICON_YOUKO                             "\uF297"
#define ENTYPO_ICON_YOUKO_WITH_CIRCLE                 "\uF298"
#define ENTYPO_ICON_YOUTUBE                           "\uF299"
#define ENTYPO_ICON_YOUTUBE_WITH_CIRCLE               "\uF29A"

#endif // DOXYGEN_SHOULD_SKIP_THIS
