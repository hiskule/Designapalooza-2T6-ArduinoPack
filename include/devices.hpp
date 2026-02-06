#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <ColorSensor.h>
#include <DDBot.h>

#include <arm.hpp>
#include <chassis.hpp>

#include "constants.hpp"

inline DDBot drivetrain(drive::DIRECTION_PINS, drive::SPEED_PINS);
inline ColorSensor colorSensor(color::S2_PIN, color::S3_PIN, color::OUT_PIN);
inline Chassis chassis(drivetrain, colorSensor);

inline Arm arm(servo::SERVO_PIN);

#endif  // DEVICES_HPP
