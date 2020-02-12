#include "dc_motor_driver.h"
#include "ultrasonic.h"

void setup(){
  setup_dc_motors();
  setup_ultrasonic();
  setup_radar();
}

