/*
    src/colorwheel.cpp -- fancy analog widget to select a color value

    This widget was contributed by Dmitriy Morozov.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/colorwheel.h>
#include <nanogui/opengl.h>
#include <nanogui/serializer/core.h>
#include <nanogui/theme.h>

#include <Eigen/Geometry>
#include <Eigen/QR>

NAMESPACE_BEGIN(nanogui)

ColorWheel::ColorWheel(Widget *parent, const Color &rgb)
    : Widget(parent), mDragRegion(None) {
  setColor(rgb);
}

Vector2i ColorWheel::preferredSize() const { return {100, 100.}; }

void ColorWheel::draw(skity::Canvas *canvas) {
  Widget::draw(canvas);

  if (!mVisible) return;

  float x = 0.f, y = 0.f, w = mSize.x(), h = mSize.y();

  int i;
  float r0, r1, ax, ay, bx, by, cx, cy, aeps, r;
  float hue = mHue;

  cx = x + w * 0.5f;
  cy = y + h * 0.5f;
  r1 = (w < h ? w : h) * 0.5f - 5.0f;
  r0 = r1 * .75f;

  aeps = 0.5f / r1;  // half a pixel arc length in radians (2pi cancels out).

  for (i = 0; i < 6; i++) {
    float a0 = (float)i / 6.f * glm::pi<float>() * 2.f - aeps;
    float a1 = (float)(i + 1.f) / 6.f * glm::pi<float>() * 2.f + aeps;

    float p1_x = cx + std::cos(a0) * r0;
    float p1_y = cy + std::sin(a0) * r0;

    float p3_x = cx + std::cos(a1) * r0;
    float p3_y = cy + std::sin(a1) * r0;

    skity::Vec2 p1r = glm::normalize(skity::Vec2{p1_x - cx, p1_y - cy});
    skity::Vec2 p3r = glm::normalize(skity::Vec2{p3_x - cx, p3_y - cy});
    skity::Vec2 p2r = glm::normalize((p1r + p3r) * 0.5f);
    p2r = skity::Vec2{cx, cy} +
          (r0 + r0 * glm::pi<float>() * 0.1f *
                    std::powf((a1 - a0) * 2.f / glm::pi<float>(), 2)) *
              p2r;

    float p4_x = cx + std::cos(a0) * r1;
    float p4_y = cy + std::sin(a0) * r1;

    float p6_x = cx + std::cos(a1) * r1;
    float p6_y = cy + std::sin(a1) * r1;

    skity::Vec2 p4r = glm::normalize(skity::Vec2{p4_x - cx, p4_y - cy});
    skity::Vec2 p6r = glm::normalize(skity::Vec2{p6_x - cx, p6_y - cy});
    skity::Vec2 p5r = glm::normalize((p6r + p4r) * 0.5f);
    p5r = skity::Vec2{cx, cy} +
          (r1 + r1 * glm::pi<float>() * 0.1f *
                    std::powf((a1 - a0) * 2.f / glm::pi<float>(), 2)) *
              p5r;

    skity::Vec2 p1c = skity::Vec2{p1_x - cx, p1_y - cy};

    skity::Path path;
    path.moveTo(p1_x, p1_y);
    path.quadTo(p2r.x, p2r.y, p3_x, p3_y);
    path.lineTo(p6_x, p6_y);
    path.quadTo(p5r.x, p5r.y, p4_x, p4_y);
    path.close();

    ax = cx + std::cosf(a0) * (r0 + r1) * 0.5f;
    ay = cy + std::sinf(a0) * (r0 + r1) * 0.5f;
    bx = cx + std::cosf(a1) * (r0 + r1) * 0.5f;
    by = cy + std::sinf(a1) * (r0 + r1) * 0.5f;

    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kFill_Style);
    std::array<skity::Color4f, 2> colors{
        skity::Color4fFromColor(skity::ColorMakeFromHSLA(
            a0 / (glm::pi<float>() * 2.f), 1.f, 0.55f, 255)),
        skity::Color4fFromColor(skity::ColorMakeFromHSLA(
            a1 / (glm::pi<float>() * 2.f), 1.f, 0.55f, 255)),
    };
    std::array<skity::Point, 2> pts{
        skity::Point{ax, ay, 0.f, 1.f},
        skity::Point{bx, by, 0.f, 1.f},
    };
    paint.setShader(
        skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));
    canvas->drawPath(path, paint);
  }

  {
    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kStroke_Style);
    paint.setStrokeJoin(skity::Paint::kRound_Join);
    paint.setStrokeWidth(1.f);
    paint.setColor(skity::ColorSetARGB(64, 0, 0, 0));
    // FIXME: path add two circle got error path move and lineto command, need
    // fix
    // skity::Path path; path.addCircle(cx, cy, r0 - 0.5f);
    // path.addCircle(cx, cy, r1 + 0.5f);
    // canvas->drawPath(path, paint);
    canvas->drawCircle(cx, cy, r0 - 0.5f, paint);
    canvas->drawCircle(cx, cy, r1 + 0.5f, paint);
  }

  // selector
  canvas->save();
  canvas->translate(cx, cy);
  canvas->rotate(glm::degrees(hue * glm::pi<float>() * 2.f));

  // Marker on
  float u = std::max(r1 / 50, 1.5f);
  u = std::min(u, 4.f);

  // Marker on
  {
    skity::Path path;
    path.addRect(skity::Rect::MakeXYWH(r0 - 1.f, -2.f * u, r1 - r0 + 2.f, 4.f * u));

    skity::Paint paint;
    paint.setStyle(skity::Paint::kStroke_Style);
    paint.setStrokeWidth(u);
    paint.setColor(skity::ColorSetARGB(128, 0, 0, 0));
    paint.setMaskFilter(skity::MaskFilter::MakeBlur(skity::kOuter, 3.f));

    canvas->drawPath(path, paint);

    paint.setMaskFilter(nullptr);
    paint.setColor(skity::ColorSetARGB(192, 255, 255, 255));
    canvas->drawPath(path, paint);

  }

  // Center triangle
  {
    r = r0 - 6.f;
    ax = std::cosf(120.0f / 180.0f * glm::pi<float>()) * r;
    ay = std::sinf(120.0f / 180.0f * glm::pi<float>()) * r;
    bx = std::cosf(-120.0f / 180.0f * glm::pi<float>()) * r;
    by = std::sinf(-120.0f / 180.0f * glm::pi<float>()) * r;
    skity::Path triangle;
    triangle.moveTo(r, 0.f);
    triangle.lineTo(ax, ay);
    triangle.lineTo(bx, by);
    triangle.close();

    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kFill_Style);

    // r, 0, ax,ay, nvgHSLA(hue,1.0f,0.5f,255), nvgRGBA(255,255,255,255)
    std::array<skity::Color4f, 2> colors{
        skity::Color4fFromColor(skity::ColorMakeFromHSLA(hue, 1.0f, 0.5f, 255)),
        skity::Color4fFromColor(skity::ColorSetARGB(255, 255, 255, 255)),
    };
    std::array<skity::Point, 2> pts{
        skity::Point{r, 0.f, 0.f, 1.f},
        skity::Point{ax, ay, 0.f, 1.f},
    };

    paint.setShader(
        skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));
    canvas->drawPath(triangle, paint);

    // (r+ax)*0.5f,(0+ay)*0.5f, bx,by, nvgRGBA(0,0,0,0), nvgRGBA(0,0,0,255)
    colors[0] = skity::Color4fFromColor(skity::ColorSetARGB(0, 0, 0, 0));
    colors[1] = skity::Color4fFromColor(skity::ColorSetARGB(255, 0, 0, 0));
    pts[0].x = (r + ax) * 0.5f;
    pts[0].y = (0 + ay) * 0.5f;
    pts[1].x = bx;
    pts[1].y = by;

    paint.setShader(
        skity::Shader::MakeLinear(pts.data(), colors.data(), nullptr, 2));

    canvas->drawPath(triangle, paint);

    // Select circle on triangle

    float sx = r * (1 - mWhite - mBlack) + ax * mWhite + bx * mBlack;
    float sy = ay * mWhite + by * mBlack;

    paint.setStyle(skity::Paint::kStroke_Style);
    paint.setStrokeWidth(u);
    skity::Path circle;
    circle.addCircle(sx, sy, 2.f * u);
    paint.setShader(nullptr);
    paint.setColor(skity::ColorSetARGB(192, 255, 255, 255));
    canvas->drawPath(circle, paint);
  }

  canvas->restore();
}

bool ColorWheel::mouseButtonEvent(const Vector2i &p, int button, bool down,
                                  int modifiers) {
  Widget::mouseButtonEvent(p, button, down, modifiers);
  if (!mEnabled || button != GLFW_MOUSE_BUTTON_1) return false;

  if (down) {
    mDragRegion = adjustPosition(p);
    return mDragRegion != None;
  } else {
    mDragRegion = None;
    return true;
  }
}

bool ColorWheel::mouseDragEvent(const Vector2i &p, const Vector2i &, int, int) {
  return adjustPosition(p, mDragRegion) != None;
}

ColorWheel::Region ColorWheel::adjustPosition(const Vector2i &p,
                                              Region consideredRegions) {
  float x = p.x() - mPos.x(), y = p.y() - mPos.y(), w = mSize.x(),
        h = mSize.y();

  float cx = w * 0.5f;
  float cy = h * 0.5f;
  float r1 = (w < h ? w : h) * 0.5f - 5.0f;
  float r0 = r1 * .75f;

  x -= cx;
  y -= cy;

  float mr = std::sqrt(x * x + y * y);

  if ((consideredRegions & OuterCircle) &&
      ((mr >= r0 && mr <= r1) || (consideredRegions == OuterCircle))) {
    if (!(consideredRegions & OuterCircle)) return None;
    mHue = std::atan(y / x);
    if (x < 0) mHue += glm::pi<float>();
    mHue /= 2 * glm::pi<float>();

    if (mCallback) mCallback(color());

    return OuterCircle;
  }

  float r = r0 - 6;

  float ax = std::cos(120.0f / 180.0f * glm::pi<float>()) * r;
  float ay = std::sin(120.0f / 180.0f * glm::pi<float>()) * r;
  float bx = std::cos(-120.0f / 180.0f * glm::pi<float>()) * r;
  float by = std::sin(-120.0f / 180.0f * glm::pi<float>()) * r;

  typedef Eigen::Matrix<float, 2, 2> Matrix2f;

  Eigen::Matrix<float, 2, 3> triangle;
  triangle << ax, bx, r, ay, by, 0;
  triangle = Eigen::Rotation2D<float>(mHue * 2 * glm::pi<float>()).matrix() * triangle;

  Matrix2f T;
  T << triangle(0, 0) - triangle(0, 2), triangle(0, 1) - triangle(0, 2),
      triangle(1, 0) - triangle(1, 2), triangle(1, 1) - triangle(1, 2);
  Vector2f pos{x - triangle(0, 2), y - triangle(1, 2)};

  Vector2f bary = T.colPivHouseholderQr().solve(pos);
  float l0 = bary[0], l1 = bary[1], l2 = 1 - l0 - l1;
  bool triangleTest =
      l0 >= 0 && l0 <= 1.f && l1 >= 0.f && l1 <= 1.f && l2 >= 0.f && l2 <= 1.f;

  if ((consideredRegions & InnerTriangle) &&
      (triangleTest || consideredRegions == InnerTriangle)) {
    if (!(consideredRegions & InnerTriangle)) return None;
    l0 = std::min(std::max(0.f, l0), 1.f);
    l1 = std::min(std::max(0.f, l1), 1.f);
    l2 = std::min(std::max(0.f, l2), 1.f);
    float sum = l0 + l1 + l2;
    l0 /= sum;
    l1 /= sum;
    mWhite = l0;
    mBlack = l1;
    if (mCallback) mCallback(color());
    return InnerTriangle;
  }

  return None;
}

Color ColorWheel::hue2rgb(float h) const {
  float s = 1., v = 1.;

  if (h < 0) h += 1;

  int i = int(h * 6);
  float f = h * 6 - i;
  float p = v * (1 - s);
  float q = v * (1 - f * s);
  float t = v * (1 - (1 - f) * s);

  float r = 0, g = 0, b = 0;
  switch (i % 6) {
    case 0:
      r = v, g = t, b = p;
      break;
    case 1:
      r = q, g = v, b = p;
      break;
    case 2:
      r = p, g = v, b = t;
      break;
    case 3:
      r = p, g = q, b = v;
      break;
    case 4:
      r = t, g = p, b = v;
      break;
    case 5:
      r = v, g = p, b = q;
      break;
  }

  return {r, g, b, 1.f};
}

Color ColorWheel::color() const {
  Color rgb = hue2rgb(mHue);
  Color black{0.f, 0.f, 0.f, 1.f};
  Color white{1.f, 1.f, 1.f, 1.f};
  return rgb * (1 - mWhite - mBlack) + black * mBlack + white * mWhite;
}

void ColorWheel::setColor(const Color &rgb) {
  float r = rgb[0], g = rgb[1], b = rgb[2];

  float max = std::max({r, g, b});
  float min = std::min({r, g, b});
  float l = (max + min) / 2;

  if (max == min) {
    mHue = 0.;
    mBlack = 1. - l;
    mWhite = l;
  } else {
    float d = max - min, h;
    /* float s = l > 0.5 ? d / (2 - max - min) : d / (max + min); */
    if (max == r)
      h = (g - b) / d + (g < b ? 6 : 0);
    else if (max == g)
      h = (b - r) / d + 2;
    else
      h = (r - g) / d + 4;
    h /= 6;

    mHue = h;

    Eigen::Matrix<float, 4, 3> M;
    M.topLeftCorner<3, 1>() = hue2rgb(h).head<3>();
    M(3, 0) = 1.;
    M.col(1) = Vector4f{0., 0., 0., 1.};
    M.col(2) = Vector4f{1., 1., 1., 1.};

    Vector4f rgb4{rgb[0], rgb[1], rgb[2], 1.};
    Vector3f bary = M.colPivHouseholderQr().solve(rgb4);

    mBlack = bary[1];
    mWhite = bary[2];
  }
}

void ColorWheel::save(Serializer &s) const {
  Widget::save(s);
  s.set("hue", mHue);
  s.set("white", mWhite);
  s.set("black", mBlack);
}

bool ColorWheel::load(Serializer &s) {
  if (!Widget::load(s)) return false;
  if (!s.get("hue", mHue)) return false;
  if (!s.get("white", mWhite)) return false;
  if (!s.get("black", mBlack)) return false;
  mDragRegion = Region::None;
  return true;
}

NAMESPACE_END(nanogui)
