#define SAMPLE_TIME 0.020

float errorSum;
float errorDerivative;
float previousError;
float output;

float Kp = 1;
float Ki = 1;
float Kd = 1;

void setupPID(float p, float i, float d) {
  Kp = p;
  Ki = i;
  Kd = d;
}

float calculatePID(float error){
  errorSum += error * SAMPLE_TIME;
  errorDerivative = (error - previousError)/SAMPLE_TIME;
  previousError = error;
  return (Kp * error) + (Ki * errorSum) + (Kd * errorDerivative);
}

void applyOutput(float Output){
   setLeftSpeed(output);
   setRightSpeed(-output);
}
