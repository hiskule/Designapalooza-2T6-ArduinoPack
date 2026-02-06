#include "stations.hpp"

void boxManeuver(bool wasWeavingRight) {
  // Hardcoded box pickup
  chassis.moveTank(0, -255, wasWeavingRight ? 1000 : 1750, false);
  arm.lower();
  delay(1000);
  chassis.moveTank(255, 255, 1500);
  arm.raise();
  delay(1000);
  // Drop
  chassis.moveTank(255, -255, 2000);
  chassis.moveTank(255, 255, 1000);
  arm.lower();
  delay(1000);
  chassis.moveTank(-255, -255, 1500);
  arm.raise();
}

void moveToCenter() {
  bool done = false;
  ColorName color = ColorName::UNKNOWN;
  ColorName lastColor = ColorName::UNKNOWN;
  while (!done) {
    color = chassis.readColor();
    // Check if we hit target
    if (color == ColorName::BLACK) {
      chassis.stop();
      return;
    }
    // Check if we missed the center
    if (static_cast<int>(color) < static_cast<int>(lastColor)) {
      chassis.moveTank(-255, -255, 750);
      return;
    }
    // Otherwise, continue onwards
    chassis.moveTank(255, 255, 0, false);

    lastColor = color;
    delay(50);
  }
}

// Right side box + ramp
void runStationA() {
  Serial.println("Running Station A");
  // Move to blue tape
  while (chassis.readColor() != ColorName::BLUE) {
    chassis.followLine(ColorName::GREEN, false);
    delay(50);
  }

  // Hardcoded box pickup
  // Check which way we were weaving before to determine size of turn
  bool wasWeavingRight = (chassis.getBufferedColor() == ColorName::GREEN);
  boxManeuver(wasWeavingRight);

  // Rejoin line
  chassis.moveTank(255, -255, 500);
  while (chassis.readColor() != ColorName::GREEN) {
    chassis.moveTank(255, 170);
    delay(50);
  }

  // Move to ramp, following right side
  while (chassis.readColor() != ColorName::BLACK) {
    chassis.followLine(ColorName::GREEN, false);
    delay(50);
  }

  // Ascend ramp, curving left
  while (chassis.readColor() != ColorName::BLUE) {
    chassis.followLine(ColorName::BLACK, true);
    delay(50);
  }

  // Aim for center
  moveToCenter();

  chassis.stop();
  Serial.println("Station A complete");
}

void runStationB() { Serial.println("Running Station B"); }
