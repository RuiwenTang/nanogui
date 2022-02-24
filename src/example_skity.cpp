
#include <nanogui/nanogui.h>

#include <iostream>

using namespace nanogui;

bool bvar = true;
int ivar = 12345678;
std::string strval = "A string";

int main(int argc, const char** argv) {
  nanogui::init();

  Screen* screen =
      new Screen(Vector2i(1200, 800), "NanoGUI Skity [GL 4.1]",
                 /*resizable*/ false, /*fullscreen*/ false, /*colorBits*/ 8,
                 /*alphaBits*/ 8, /*depthBits*/ 24, /*stencilBits*/ 8,
                 /*nSamples*/ 0, /*glMajor*/ 4, /*glMinor*/ 1);

  bool enabled = true;
  FormHelper* gui = new FormHelper(screen);

  ref<Window> window =
      gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
  window->setLayout(new GroupLayout());

  new Label(window, "Toggle buttons", "sans-bold");
  new Button(window, "Plain button", "");
  auto* b = new Button(window, "Styled", ENTYPO_ICON_ROCKET);
  b->setBackgroundColor(Color(0, 0, 255, 25));

  new Label(window, "Toggle buttons", "sans-bold");

  b = new Button(window, "Toggle me", "");
  b->setFlags(Button::ToggleButton);
  b->setChangeCallback([](bool state) {
    std::cout << "Toggle button state: " << state << std::endl;
  });

  new Label(window, "Radio buttons", "sans-bold");
  b = new Button(window, "Radio button 1", "");
  b->setFlags(Button::RadioButton);
  b = new Button(window, "Radio button 2", "");
  b->setFlags(Button::RadioButton);

  new Label(window, "A tool palette", "sans-bold");

  Widget* tools = new Widget(window);
  tools->setLayout(
      new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));

  b = new ToolButton(tools, ENTYPO_ICON_CLOUD);
  b = new ToolButton(tools, ENTYPO_ICON_CONTROLLER_FAST_FORWARD);
  b = new ToolButton(tools, ENTYPO_ICON_COMPASS);
  b = new ToolButton(tools, ENTYPO_ICON_INSTALL);

  new Label(window, "Popup buttons", "sans-bold");
  PopupButton* popupBtn = new PopupButton(window, "Popup", ENTYPO_ICON_EXPORT);

  Popup* popup = popupBtn->popup();
  popup->setLayout(new GroupLayout());
  new Label(popup, "Arbitrary widgets can be placed here");
  new CheckBox(popup, "A check box");

  // popup right
  popupBtn = new PopupButton(popup, "Recursive popup", ENTYPO_ICON_FLASH);
  Popup* popupRight = popupBtn->popup();
  popupRight->setLayout(new GroupLayout());
  new CheckBox(popupRight, "Another check box");

  // popup left
  popupBtn = new PopupButton(popup, "Recursive popup", ENTYPO_ICON_FLASH);
  popupBtn->setSide(Popup::Side::Left);
  Popup* popupLeft = popupBtn->popup();
  popupLeft->setLayout(new GroupLayout());
  new CheckBox(popupLeft, "Another check box");

  window = new Window(screen, "Basic widgets");
  window->setPosition(Vector2i(300, 15));
  window->setLayout(new GroupLayout());

  new Label(window, "Message dialog", "sans-bold");
  tools = new Widget(window);
  tools->setLayout(
      new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));

  b = new Button(tools, "Info", "");
  b->setCallback([&] {
    auto dlg = new MessageDialog(screen, MessageDialog::Type::Information,
                                 "Title", "This is an information message");
    dlg->setCallback([](int result) {
      std::cout << "Dialog result: " << result << std::endl;
    });
  });
  b = new Button(tools, "Warn", "");
  b->setCallback([&] {
    auto dlg = new MessageDialog(screen, MessageDialog::Type::Warning, "Title",
                                 "This is a warning message");
    dlg->setCallback([](int result) {
      std::cout << "Dialog result: " << result << std::endl;
    });
  });

  b = new Button(tools, "Ask", "");
  b->setCallback([&] {
    auto dlg =
        new MessageDialog(screen, MessageDialog::Type::Warning, "Title",
                          "This is a question message", "Yes", "No", true);
    dlg->setCallback([](int result) {
      std::cout << "Dialog result: " << result << std::endl;
    });
  });

  new Label(window, "Image panel & scroll panel", "sans-bold");
  PopupButton* imagePanelBtn = new PopupButton(window, "Image Panel");
  imagePanelBtn->setIconStr(ENTYPO_ICON_FOLDER);
  popup = imagePanelBtn->popup();
  VScrollPanel *vscroll = new VScrollPanel(popup);

  std::vector<std::pair<std::shared_ptr<skity::Pixmap>, std::string>> icons =
      loadImageDirectory("icons");
#if defined(_WIN32)
  string resourcesFolderPath("../resources/");
#else
  std::string resourcesFolderPath("./");
#endif
  ImagePanel *imgPanel = new ImagePanel(vscroll);
  imgPanel->setImages(icons);
  popup->setFixedSize(Vector2i(245, 150));

  screen->setVisible(true);
  screen->performLayout();

  nanogui::mainloop();

  nanogui::shutdown();
  return 0;
}