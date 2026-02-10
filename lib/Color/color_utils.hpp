#ifndef COLOR_UTILS_HPP
#define COLOR_UTILS_HPP

#include <TCS3200.h>

struct HSVColorRange {
  HSVColor min, max;

  bool contains(const HSVColor& color) const;
};


#endif // COLOR_UTILS_HPP
