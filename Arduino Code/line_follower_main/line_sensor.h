
#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#define MANUAL_CONTROL 1
#define LINE_FOLLOWER 2
#define SAMPLE_TIME 0.050

#define SENSOR_0 A0
#define NUM_OF_SENSORS 5
#define NUM_OF_SAMPLES 200.0

void calibrateSensors() ;
byte readLineSensors();
int getLineError(byte reading);

#endif
