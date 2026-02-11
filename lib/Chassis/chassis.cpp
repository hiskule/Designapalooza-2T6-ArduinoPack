#include "chassis.hpp"

/*

moveTank(): Main movement control: Forward/Backward/Turning for time (T)

readColor(): Reads and returns color from TCS230 Color Sensor

maxdistance(): Reads distance of nearest obstacle from HCSR04 UltraSonic Sensor

followLine(): Line-following program (May not be provided to students)

*/

void Chassis::moveTank(int leftSpeed, int rightSpeed, int time,
                       bool stopAfter) {

  // Set movement direction - converting speed to DDBOT commands
  if (leftSpeed >= 0 && rightSpeed >= 0) {
    this->forward(leftSpeed, rightSpeed);
  } else if (leftSpeed < 0 && rightSpeed < 0) {
    this->backward(-leftSpeed, -rightSpeed);
  } else if (leftSpeed >= 0 && rightSpeed < 0) {
    this->right(leftSpeed, -rightSpeed);
  } else {
    this->left(-leftSpeed, rightSpeed);
  }

  // Stop after certain amount of time
  delay(time);
  if (stopAfter && time > 0) {
    this->stop();
  }
}
