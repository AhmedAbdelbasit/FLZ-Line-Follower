// 0 : white
// 1 : line
#include "line_sensor.h"

int threshold[NUM_OF_SENSORS];

void calibrateSensors() {
  int minimum[NUM_OF_SENSORS];
  int maximum[NUM_OF_SENSORS];

  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    minimum[i] = 1023;
    threshold[i] = 0;
    maximum[i] = 0;
  }
  int x;
  for (int i = 0 ; i < NUM_OF_SAMPLES ; i++) {
    for (int j = 0 ; j < NUM_OF_SENSORS ; j++) {
      x = analogRead(SENSOR_0 + j);
      if (x < minimum[j])
        minimum[j] = x;
      else if (x > maximum[j])
        maximum[j] = x;
    }
  }

  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    threshold[i] = (minimum[i] + maximum[i]) / 2;
  }
}


byte readLineSensors() {
  byte lineReading = 0;
  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    lineReading = lineReading << 1;
    lineReading |= (analogRead(SENSOR_0 + i) < threshold[i]);
  }
  return lineReading;
}


int getLineError(byte reading) {
  switch (reading) {
    case (0b10000):
      return -4;
    case (0b11000):
      return -3;
    case (0b01000):
      return -2;
    case (0b01100):
      return -1;
    case (0b00100):
      return 0;
    case (0b00110):
      return 1;
    case (0b00010):
      return 2;
    case (0b00011):
      return 3;
    case (0b00001):
      return 4;
      /*
        case (0b00000):
        return ;
        case (0b11100):
        return ;
        case (0b01110):
        return ;
        case (0b00111):
        return ;
        case (0b11110):
        return ;
        case (0b01111):
        return ;
        case (0b11111):
        return ;
      */
  }
}

