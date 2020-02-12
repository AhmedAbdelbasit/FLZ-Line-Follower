#include <Servo.h>
#include "ultrasonic.h"

#define servo 12

int distance;

Servo myServo;

void setup_radar() {
  //seting numbers for the ultrasnic and the servo pins
  setup_ultrasonic();
  myServo.attach(servo);
}


void scan_full_view() {
  //making the servo rotate from 0 to 90 degree
  for (int i = 0; i <= 90; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
  }
  
  //making the servo rotate back from 90 to 0
  for (int i = 90; i > 0; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
  }
}




