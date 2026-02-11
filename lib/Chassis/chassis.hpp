#ifndef CHASSIS_HPP
#define CHASSIS_HPP
#include <DDBot.h>

#include <cmath>
#include <queue>

class Chassis : public DDBot {
 public:
  Chassis(uint8_t directionPins[NUMBER_OF_DIRECTION_PINS], uint8_t PWMPins[NUMBER_OF_PWM_PINS])
      : DDBot(directionPins, PWMPins) {
    setPinModes();
  }

  /**
   * @brief Move the robot using tank controls without direction flipping
   * @param leftSpeed Speed for the left motor (-255 to 255)
   * @param rightSpeed Speed for the right motor (-255 to 255)
   * @param time Duration to move in milliseconds
   * @param stopAfter If true, stop the robot after moving for the specified
   * time
   */
  void moveTank(int leftSpeed, int rightSpeed, int time = 0,
                bool stopAfter = true);
};

#endif  // CHASSIS_HPP
