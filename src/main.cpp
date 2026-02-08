#include <Arduino.h>

#include "devices.hpp"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial && millis() < 2000) {
  }

  Serial.println("Initializing…");
  drivetrain.setPinModes();
  chassis.stop();
  Serial.println("Initialization complete");

  //drivetrain.forward(255);
  delay(1000);
  chassis.stop();
  chassis.moveTank(255, 255, 5000);
  Serial.println("Done");

}

void loop() {

}
