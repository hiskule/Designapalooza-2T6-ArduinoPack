#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <Arduino.h>

#include <cstdint>

// Drivetrain motor pins
namespace drive {
inline uint8_t DIRECTION_PINS[4] = {4, 5, 2, 3};
inline uint8_t SPEED_PINS[2] = {10, 9};
}  // namespace drive

// Color sensor pins
namespace color {
inline uint8_t S2_PIN = A5;
inline uint8_t S3_PIN = 7;
inline uint8_t OUT_PIN = 8;
}  // namespace color

// Ultrasonic sensor pins
namespace sonar {
inline uint8_t TRIGGER_PIN = 11;
inline uint8_t ECHO_PIN = 12;
inline int MAX_DIST_CM = 200;
}  // namespace sonar

// Arm servo pins
namespace servo {
inline uint8_t SERVO_PIN = 6;
} // namespace servo

#endif  // CONSTANTS_HPP
