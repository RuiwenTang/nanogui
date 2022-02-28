
#include <nanogui/nanogui.h>

#include <iostream>

using namespace nanogui;

bool bvar = true;
int ivar = 12345678;
std::string strval = "A string";

int main(int argc, const char** argv) {
  nanogui::init();

  Screen* screen =
      new Screen(Vector2i(1200, 800), "Skity GUI [OpenGL]",
                 /*resizable*/ false, /*fullscreen*/ false, /*colorBits*/ 8,
                 /*alphaBits*/ 8, /*depthBits*/ 24, /*stencilBits*/ 8,
                 /*nSamples*/ 8, /*glMajor*/ 4, /*glMinor*/ 1);

  bool enabled = true;
  FormHelper* gui = new FormHelper(screen);

  ref<Window> window =
      gui->addWindow(Eigen::Vector2i(10, 50), "Form helper example");
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
  window->setPosition(Vector2i(250, 50));
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
  VScrollPanel* vscroll = new VScrollPanel(popup);

  std::vector<std::pair<std::shared_ptr<skity::Pixmap>, std::string>> icons =
      loadImageDirectory("icons");
#if defined(_WIN32)
  std::string resourcesFolderPath("../resources/");
#else
  std::string resourcesFolderPath("./");
#endif
  ImagePanel* imgPanel = new ImagePanel(vscroll);
  imgPanel->setImages(icons);
  popup->setFixedSize(Vector2i(245, 150));

  auto imageWindow = new Window(screen, "Selected image");
  imageWindow->setPosition(Vector2i(710, 15));
  imageWindow->setLayout(new GroupLayout());

  auto imageView = new ImageView(imageWindow, icons[0].first);
  int mCurrentImage;
  mCurrentImage = 0;
  // Change the active textures.
  imgPanel->setCallback([&mCurrentImage, imageView, icons](int i) {
    imageView->bindImage(icons[i].first);
    mCurrentImage = i;
    std::cout << "Selected item " << i << '\n';
  });

  imageView->setPixelInfoCallback(
      [screen, mCurrentImage, icons,
       imageView](const Vector2i& index) -> std::pair<std::string, Color> {
        auto& pixmap = icons[mCurrentImage].first;
        auto& textureSize = imageView->imageSize();
        const char* imageData = (const char*)pixmap->Addr();
        std::string stringData;
        uint16_t channelSum = 0;
        for (int i = 0; i != 4; ++i) {
          uint8_t channelData =
              imageData[4 * index.y() * textureSize.x() + 4 * index.x() + i];
          channelSum += channelData;
          stringData += (std::to_string(static_cast<int>(channelData)) + "\n");
        }
        float intensity = static_cast<float>(255 - (channelSum / 4)) / 255.0f;
        float colorScale =
            intensity > 0.5f ? (intensity + 1) / 2 : intensity / 2;
        Color textColor = Color(colorScale, 1.0f);
        return {stringData, textColor};
      });

  imageView->setGridThreshold(20);
  imageView->setPixelInfoThreshold(20);

  new Label(window, "File dialog", "sans-bold");
  tools = new Widget(window);
  tools->setLayout(
      new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));

  b = new Button(tools, "Open", "");
  b->setCallback([&] {
    std::cout << "File dialog result: "
              << file_dialog({{"png", "Portable Network Graphics"},
                              {"txt", "Text file"}},
                             false)
              << std::endl;
  });

  b = new Button(tools, "Save", "");
  b->setCallback([&] {
    std::cout << "File dialog result: "
              << file_dialog({{"png", "Portable Network Graphics"},
                              {"txt", "Text file"}},
                             true)
              << std::endl;
  });

  new Label(window, "Combo box", "sans-bold");
  new ComboBox(window,
               {"Combo box item 1", "Combo box item 2", "Combo box item 3"});

  new Label(window, "Check box", "sans-bold");
  CheckBox* cb = new CheckBox(window, "Flag 1", [](bool state) {
    std::cout << "Check box 1 state: " << state << std::endl;
  });
  cb->setChecked(true);
  cb = new CheckBox(window, "Flag 2", [](bool state) {
    std::cout << "Check box 2 state: " << state << std::endl;
  });

  new Label(window, "Progress bar", "sans-bold");

  auto mProgress = new ProgressBar(window);
  mProgress->setValue(0.3f);

  new Label(window, "Slider and text box", "sans-bold");

  Widget* panel = new Widget(window);
  panel->setLayout(
      new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 20));

  Slider* slider = new Slider(panel);
  slider->setValue(0.5f);
  slider->setFixedWidth(80);

  TextBox* textBox = new TextBox(panel);
  textBox->setFixedSize(Vector2i(60, 25));
  textBox->setValue("50");
  textBox->setUnits("%");
  slider->setCallback([textBox](float value) {
    textBox->setValue(std::to_string((int)(value * 100)));
  });
  slider->setFinalCallback([&](float value) {
    std::cout << "Final slider value: " << (int)(value * 100) << std::endl;
  });

  textBox->setFixedSize(Vector2i(60, 25));
  textBox->setFontSize(20);
  textBox->setAlignment(TextBox::Alignment::Right);

  window = new Window(screen, "Misc. widgets");
  window->setPosition(Vector2i(510, 55));
  window->setLayout(new GroupLayout());

  TabWidget* tabWidget = window->add<TabWidget>();
  Widget* layer = tabWidget->createTab("Color Wheel");
  layer->setLayout(new GroupLayout());

  // Use overloaded variadic add to fill the tab widget with Different tabs.
  layer->add<Label>("Color wheel widget", "sans-bold");
  layer->add<ColorWheel>();

  layer = tabWidget->createTab("Function Graph");
  layer->setLayout(new GroupLayout());

  Graph *graph = layer->add<Graph>("Some Function");

  graph->setHeader("E = 2.35e-3");
  graph->setFooter("Iteration 89");
  VectorXf &func = graph->values();
  func.resize(100);
  for (int i = 0; i < 100; ++i)
    func[i] = 0.5f * (0.5f * std::sin(i / 10.f) +
                      0.5f * std::cos(i / 23.f) + 1);

  screen->setVisible(true);
  screen->performLayout();

  nanogui::mainloop();

  nanogui::shutdown();
  return 0;
}