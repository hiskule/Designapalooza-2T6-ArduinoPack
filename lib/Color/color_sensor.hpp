#ifndef COLOR_SENSOR_HPP
#define COLOR_SENSOR_HPP
#include <TCS3200.h>

class ColorSensor : public TCS3200 {
 public:
  ColorSensor(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t outPin) : TCS3200(s0, s1, s2, s3, outPin) {}
  ColorSensor(uint8_t s2, uint8_t s3, uint8_t outPin) : TCS3200(-1, -1, s2, s3, outPin) {}

 private:
};

#endif // COLOR_SENSOR_HPP
