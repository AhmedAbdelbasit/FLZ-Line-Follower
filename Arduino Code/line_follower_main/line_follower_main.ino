#include "dc_motor_driver.h"
#include "ultrasonic.h"

void setup(){
  setupDCMotors();
  setupRadar();
  setupSerial();
}

