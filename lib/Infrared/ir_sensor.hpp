#ifndef IR_SENSOR_HPP
#define IR_SENSOR_HPP
#include <Arduino.h>

class InfraredSensor {
 public:
  InfraredSensor(uint8_t pin) : _pin(pin) { pinMode(_pin, INPUT); }

  bool detectsObject() { return digitalRead(_pin) == HIGH; }

  bool onDarkLine() { return digitalRead(_pin) == LOW; }

 protected:
  uint8_t _pin;
};
#endif // IR_SENSOR_HPP
