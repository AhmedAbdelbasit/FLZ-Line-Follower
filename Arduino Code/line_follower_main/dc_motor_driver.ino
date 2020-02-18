int robotSpeed = 100;

void setupDCMotors() {
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void setRobotSpeed(int s){
  robotSpeed = s;
}

void setSpeed(int leftSpeed, int rightSpeed) {
  analogWrite (LEFT_SPEED, leftSpeed);
  analogWrite (RIGHT_SPEED, rightSpeed);
}

void setLeftDirection(boolean d){
  digitalWrite (LM1, d);
  digitalWrite (LM2, !d);
}

void setRightDirection(boolean d){
  digitalWrite (RM1, d);
  digitalWrite (RM2, !d);
}

void moveForward () {
  setLeftDirection(1);
  setRightDirection(1);
}

void moveBackward () {
  setLeftDirection(0);
  setRightDirection(0);
}

void stopRobot () {
  setSpeed(0, 0);
}

void moveRight() {
  setLeftDirection(1);
  setRightDirection(0);
}

void moveLeft() {
  setLeftDirection(0);
  setRightDirection(1);
}


void setLeftSpeed(float output) {
  float s = robotSpeed + output;
  if ( s > 0) {
    setLeftDirection(1);
    analogWrite(LEFT_SPEED, s);
  } else {
    setLeftDirection(0);
    analogWrite(LEFT_SPEED, -s);
  }
}

void setRightSpeed(float output) {
  float s = robotSpeed + output;
  if ( s > 0) {
    setRightDirection(1);
    analogWrite(RIGHT_SPEED, s);
  } else {
    setRightDirection(0);
    analogWrite(RIGHT_SPEED, -s);
  }
}


