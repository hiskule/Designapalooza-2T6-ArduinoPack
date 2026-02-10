#include "color_utils.hpp"

bool HSVColorRange::contains(const HSVColor& color) const {
  // Check if hue is within range, accounting for wraparound at 360 degrees
  bool hueInRange;
  if (min.hue <= max.hue) {
    hueInRange = (min.hue <= color.hue && color.hue <= max.hue);
  } else {
    hueInRange = (max.hue <= color.hue || color.hue <= min.hue);
  }

  // Check saturation and value are within range
  bool saturationInRange = (min.saturation <= color.saturation && color.saturation <= max.saturation);
  bool valueInRange = (min.value <= color.value && color.value <= max.value);

  return hueInRange && saturationInRange && valueInRange;
}
