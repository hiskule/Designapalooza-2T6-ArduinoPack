/**
 * @file ColourSensor.h
 * @brief TCS3200 colour sensor driver interface
 */

#ifndef COLORSENSOR_H
#define COLORSENSOR_H
#include <Arduino.h>

/**
 * @brief Normalized RGB colour values
 */
struct ColourRGB {
  float r;
  float g;
  float b;
};

/**
 * @brief Colour classification categories
 */
enum class ColourName {
  BLUE,
  RED,
  GREEN,
  BLACK,
  WHITE,
  UNKNOWN
};

/**
 * @brief Convert ColourName to string representation
 * @param c Colour name to convert
 * @return String representation
 */
const char* toString(ColourName c);

/**
 * @brief TCS3200 colour sensor driver class
 */
class ColourSensor {
public:
  /**
   * @brief Construct a new Colour Sensor object
   * @param s2 S2 frequency selection pin
   * @param s3 S3 frequency selection pin
   * @param outPin Output frequency pin
   */
  ColourSensor(uint8_t s2, uint8_t s3, uint8_t outPin);

  /**
   * @brief Initialize sensor pins and interrupts
   */
  void begin();

  /**
   * @brief Perform interactive calibration via Serial
   */
  void calibrateSerial();
  
  /**
   * @brief Check calibration status
   * @return true if calibrated
   */
  bool isCalibrated() const;

  /**
   * @brief Read raw RGB frequency values
   * @param rgb Output array for R, G, B frequencies
   */
  void readRaw(unsigned long rgb[3]);
  
  /**
   * @brief Read normalized RGB values (0.0 to 1.0)
   * @return ColourRGB struct with normalized values
   */
  ColourRGB readNormalized();

  /**
   * @brief Classify RGB reading into a colour name
   * @param rgb Normalized RGB values to classify
   * @return ColourName enum
   */
  ColourName classify(const ColourRGB& rgb) const;

private:
  uint8_t _s2, _s3, _out;
  volatile unsigned long _pulseCount;

  unsigned long _black[3];
  unsigned long _white[3];
  bool _calibrated;

  static ColourSensor* _instance;
  static void pulseISR();

  unsigned long readFrequency(uint8_t s2, uint8_t s3);
  float normalize(unsigned long v, unsigned long b, unsigned long w) const;
};

#endif // COLORSENSOR_H
