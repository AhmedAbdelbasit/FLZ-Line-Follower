#include "ultrasonic.h"

int timeOut;

void setMaximumDistance(float distance){
  timeOut = 1000000 * distance / 340.0;
}

void setupUltrasonic() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

//function to calculate the distance
int calculateDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, timeOut);

  return (duration * 0.034 / 2);
}

