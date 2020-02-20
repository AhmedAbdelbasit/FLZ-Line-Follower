

float errorSum;
float errorDerivative;
float previousError;

float Kp = 12;
float Ki = 0.1;
float Kd = 0;

void setupPID(float p, float i, float d) {
  Kp = p;
  Ki = i;
  Kd = d;
}

float calculatePID(float error) {
  errorSum += error * SAMPLE_TIME;
  errorDerivative = (error - previousError) / SAMPLE_TIME;
  previousError = error;
  float o = (Kp * error) + (Ki * errorSum) + (Kd * errorDerivative);
  Serial.println(o);
  return o;
}

void applyOutput(float output) {
  setLeftSpeed(-output);
  setRightSpeed(output);
}
