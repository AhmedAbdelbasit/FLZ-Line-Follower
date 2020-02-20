#include "dc_motor_driver.h"
#include "ultrasonic.h"
#include "line_sensor.h"

void setup(){
  setupDCMotors();
  setupRadar();
  setupSerial();
//  calibrateSensors();
}

