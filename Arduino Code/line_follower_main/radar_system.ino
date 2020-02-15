#include <Servo.h>
#include "ultrasonic.h"

#define SERVO_PIN 12

int distance;
byte resolution = 5 ;

Servo myServo;

void setupRadar() {
  //seting numbers for the ultrasnic and the servo pins
  setupUltrasonic();
  myServo.attach(SERVO_PIN);
}

void seekRadar(int angle){
  myServo.write(angle);
}

void scanFullView() {
  //making the servo rotate from 0 to 90 degree
  for (int i = 0; i <= 90; i+=resolution) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
  }
  
  //making the servo rotate back from 90 to 0
  for (int i = 90; i > 0; i-=resolution) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
  }
}

void setResolution(byte r){
  resolution = r;
}



