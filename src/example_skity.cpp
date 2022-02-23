
#include <nanogui/nanogui.h>

#include <iostream>

using namespace nanogui;

int main(int argc, const char** argv) {
  nanogui::init();

  Screen* screen =
      new Screen(Vector2i(800, 600), "NanoGUI Skity [GL 4.1]",
                 /*resizable*/ false, /*fullscreen*/ false, /*colorBits*/ 8,
                 /*alphaBits*/ 8, /*depthBits*/ 24, /*stencilBits*/ 8,
                 /*nSamples*/ 0, /*glMajor*/ 4, /*glMinor*/ 1);

  screen->setVisible(true);

  nanogui::mainloop();

  nanogui::shutdown();
  return 0;
}