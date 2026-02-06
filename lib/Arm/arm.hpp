#ifndef ARM_HPP
#define ARM_HPP

#include <Servo.h>

class Arm {
 public:
  /**
   * @brief Construct a new Arm object
   * @param pin PWM pin connected to the servo
   */
  Arm(uint8_t pin) : servoPin(pin) { armServo.attach(servoPin); }

  /**
   * @brief Move the arm to the specified angle
   * @param angle Angle in degrees (0-180)
   */
  void moveToAngle(int angle) { armServo.write(angle); }

  /**
   * @brief Lower the arm to the down position
   */
  void lower() { moveToAngle(downAngle); }

  /**
   * @brief Raise the arm to the up position
   */
  void raise() { moveToAngle(upAngle); }

 protected:
  Servo armServo;
  uint8_t servoPin;

  const int downAngle = 0;
  const int upAngle = 50;
};

#endif  // ARM_HPP
