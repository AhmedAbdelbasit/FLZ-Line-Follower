#include "line_sensor.h"

#ifdef CALIBRATE
  int threshold[NUM_OF_SENSORS];
#else
  int threshold[NUM_OF_SENSORS] = {565, 212, 345, 227, 415};
#endif

int currentError, lastLineError;

/*
   471 565 660
  92  212 333
  280 345 410
  109 227 345
  332 415 499
*/
void calibrateSensors() {
  int minimum[NUM_OF_SENSORS];
  int maximum[NUM_OF_SENSORS];

  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    minimum[i] = 1023;
    threshold[i] = 0;
    maximum[i] = 0;
  }
  int x ;
  for (int i = 0 ; i < NUM_OF_SAMPLES ; i++) {
    for (int j = 0 ; j < NUM_OF_SENSORS ; j++) {
      x = analogRead(SENSOR_0 + j);
      if (x < minimum[j])
        minimum[j] = x;
      else if (x > maximum[j])
        maximum[j] = x;
      delay(20);

    }
    Serial.println(i / NUM_OF_SAMPLES);
  }

  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    threshold[i] = (minimum[i] + maximum[i]) / 2;
  }

  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    Serial.print(minimum[i]);
    Serial.print("\t");
    Serial.print(threshold[i]);
    Serial.print("\t");
    Serial.print(maximum[i]);
    Serial.println();
  }
}


byte readLineSensors() {
  byte lineReading = 0;
  for (int i = 0 ; i < NUM_OF_SENSORS ; i++) {
    lineReading = lineReading << 1;
    int v = (analogRead(SENSOR_0 + i) > threshold[i]);
    Serial.print(v);
    lineReading |= v;
  }
  Serial.println();
  return lineReading;
}


int getLineError(byte reading) {
  switch (reading) {
    case (0b10000):
      currentError = -4;
      break;
    case (0b11000):
      currentError = -3;
      break;
    case (0b01000):
      currentError = -2;
      break;
    case (0b01100):
      currentError =  -1;
      break;
    case (0b00100):
      currentError = 0;
      break;
    case (0b00110):
      currentError = 1;
      break;
    case (0b00010):
      currentError = 2;
      break;
    case (0b00011):
      currentError = 3;
      break;
    case (0b00001):
      currentError = 4;
      break;
    default:
      currentError = lastLineError;
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
  lastLineError = currentError;
  return currentError;
}

