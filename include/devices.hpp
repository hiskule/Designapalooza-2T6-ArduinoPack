#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <ColourSensor.h>
#include <DDBot.h>

#include <chassis.hpp>

#include "constants.hpp"

inline DDBot drivetrain(drive::DIRECTION_PINS, drive::SPEED_PINS);
inline ColourSensor colourSensor(color::S2_PIN, color::S3_PIN, color::OUT_PIN);
inline NewPing ultrasonic(sonar::TRIGGER_PIN, sonar::ECHO_PIN, sonar::MAX_DIST_CM);
inline Chassis chassis(drivetrain, colourSensor, ultrasonic);

#endif  // DEVICES_HPP
