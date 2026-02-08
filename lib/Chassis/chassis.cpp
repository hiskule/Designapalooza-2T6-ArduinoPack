#include "chassis.hpp"

void Chassis::moveTank(int leftSpeed, int rightSpeed, int time,
                       bool stopAfter) {
  if (leftSpeed >= 0 && rightSpeed >= 0) {
    drivetrain_.forward(leftSpeed, rightSpeed);
  } else if (leftSpeed < 0 && rightSpeed < 0) {
    drivetrain_.backward(-leftSpeed, -rightSpeed);
  } else if (leftSpeed >= 0 && rightSpeed < 0) {
    drivetrain_.right(leftSpeed, -rightSpeed);
  } else {
    drivetrain_.left(-leftSpeed, rightSpeed);
  }

  delay(time);

  if (stopAfter && time > 0) {
    drivetrain_.stop();
  }
}

ColourName Chassis::readColour() {
  // Get readings
  ColourRGB colourReading = colourSensor_.readNormalized();
  ColourName colourName = colourSensor_.classify(colourReading);

  // Push to queue
  bufferedColour = colourName;

  return colourName;
}

int Chassis::readDistance() {
  unsigned long distance =
      ultrasonic_.ping_cm(maxDistCm) * cos(ultrasonicAngle);

  // Return max distance if object out of range
  if (distance == 0) {
    distance = maxDistCm;
  }

  // Push to queue
  distanceReadings_.push(static_cast<int>(distance));
  if (distanceReadings_.size() > 5) {
    distanceReadings_.pop();
  }

  return static_cast<int>(distance);
}

void Chassis::followLine(ColourName lineColour, bool followLeft,
                         std::pair<int, int> speeds, bool reverse) {
  auto [inSpeed, outSpeed] = speeds;
  int dir = reverse ? -1 : 1;

  bool onLine = (readColour() == lineColour);

  // If following left side move left if on the line, right if off the line
  // Vice-versa for following right
  // Reversing uses backward instead and flips motor order
  int leftSpeed = dir * (followLeft == onLine == reverse ? outSpeed : inSpeed);
  int rightSpeed = dir * (followLeft == onLine == reverse ? inSpeed : outSpeed);
  this->moveTank(leftSpeed, rightSpeed);
}
