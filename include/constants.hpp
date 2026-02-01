#include <TCS3200.h>

// Drivetrain motor pins
namespace drive {
uint8_t directionPins[4] = {4, 5, 2, 3};
uint8_t speedPins[2] = {10, 9};
}  // namespace drive

// Colour sensor pins
namespace colour {
const uint8_t S2 = A5;
const uint8_t S3 = 7;
const uint8_t OUT = 8;

const HSVColor white_min = {0, 0, 70};
const HSVColor white_max = {360, 100, 100};

const HSVColor black_min = {0, 0, 0};
const HSVColor black_max = {360, 100, 30};

const HSVColor red_min = {330, 0, 30};
const HSVColor red_max = {30, 100, 70};

const HSVColor green_min = {120, 0, 30};
const HSVColor green_max = {180, 100, 70};

const HSVColor blue_min = {210, 0, 30};
const HSVColor blue_max = {270, 100, 70};

bool isColorInRange(const HSVColor& color, const HSVColor& min,
                    const HSVColor& max) {
  bool hueInRange;
  if (min.hue > max.hue) {
    hueInRange = (min.hue <= color.hue && color.hue <= 360) ||
                 (0 <= color.hue && color.hue <= max.hue);
  } else {
    hueInRange = (min.hue <= color.hue && color.hue <= max.hue);
  }
  return hueInRange &&
         (min.saturation <= color.saturation &&
          color.saturation <= max.saturation) &&
         (min.value <= color.value && color.value <= max.value);
}
}  // namespace colour
