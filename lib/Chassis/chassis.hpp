#ifndef CHASSIS_HPP
#define CHASSIS_HPP
#include <ColourSensor.h>
#include <DDBot.h>
#include <NewPing.h>

#include <cmath>
#include <queue>

class Chassis {
 public:
  /**
   * @brief Construct a new Chassis object
   * @param drivetrain Reference to the DDBot drivetrain instance
   * @param sensor Reference to the ColourSensor instance
   * @param ultrasonic Reference to the NewPing ultrasonic sensor instance
   */
  Chassis(DDBot& drivetrain, ColourSensor& sensor, NewPing& ultrasonic)
      : drivetrain_(drivetrain),
        colourSensor_(sensor),
        ultrasonic_(ultrasonic) {}

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

  /**
   * @brief Stop all movement of the robot
   */
  void stop() { drivetrain_.stop(); }

  /**
   * @brief Read the current colour detected by the colour sensor
   * @return Detected ColourName enum
   */
  ColourName readColour();

  /**
   * @brief Read the current distance measured by the ultrasonic sensor
   * @return Distance in centimeters
   */
  int readDistance();

  /**
   * @brief Follow a line of the specified colour using a single colour sensor by
   * weaving along an edge.
   * @param lineColour Colour of the line to follow
   * @param followLeft If true, follow the line's left side (in the direction of
   * travel); if false, follow the right side
   * @param speeds Pair of speeds (inSpeed, outSpeed) in range [0, 255]
   * @param reverse If true, move backwards while following the line
   * @note This method must be called repeatedly with a delay in between
   */
  void followLine(ColourName lineColour, bool followLeft,
                  std::pair<int, int> speeds = {170, 255},
                  bool reverse = false);

  std::queue<int> getDistanceReadings() const { return distanceReadings_; }
  ColourName getBufferedColour() const { return bufferedColour; }

 protected:
  DDBot& drivetrain_;
  ColourSensor& colourSensor_;
  NewPing& ultrasonic_;

  std::queue<int> distanceReadings_;

  ColourName bufferedColour = ColourName::UNKNOWN;

  const int maxDistCm = 30;
  const double ultrasonicAngle = 20.0 * (M_PI / 180.0);  // deg converted to rad
};

#endif  // CHASSIS_HPP
