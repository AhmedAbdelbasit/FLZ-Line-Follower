#include "dc_motor_driver.h"
#include "ultrasonic.h"
#include "line_sensor.h"

//#define RADAR
//#define CALIBRATE

void setup() {
  setupDCMotors();
  setupSerial();

#ifdef RADAR
  setupRadar();
#endif

#ifdef CALIBRATE
  calibrateSensors();
#endif
}

