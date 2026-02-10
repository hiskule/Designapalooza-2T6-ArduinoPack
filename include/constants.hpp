#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <Arduino.h>
#include <cstdint>

// Define your pins here, if they are different from defaulted pins.

// Drivetrain motor pins
namespace drive {
inline uint8_t DIRECTION_PINS[4] = {2, 3, 4, 7};
inline uint8_t SPEED_PINS[2] = {9, 10};
}  // namespace drive

// Color sensor pins
namespace color {
inline uint8_t S2_PIN = A5;
inline uint8_t S3_PIN = 5;
inline uint8_t OUT_PIN = 8;
}  // namespace color

// Ultrasonic sensor pins
namespace sonar {
inline uint8_t TRIGGER_PIN = 11;
inline uint8_t ECHO_PIN = 12;
inline int MAX_DIST_CM = 200;
}  // namespace sonar

#endif  // CONSTANTS_HPP
