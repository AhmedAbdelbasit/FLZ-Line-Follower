int robotSpeed = 90;

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
  setLeftDirection(HIGH);
  setRightDirection(HIGH);
}

void moveBackward () {
  setLeftDirection(LOW);
  setRightDirection(LOW);
}

void stopRobot () {
  digitalWrite (LM1, LOW);
  digitalWrite (LM2, LOW);
  digitalWrite (RM1, LOW);
  digitalWrite (RM2, LOW);
}

void moveRight() {
  setLeftDirection(HIGH);
  setRightDirection(LOW);
}

void moveLeft() {
  setLeftDirection(LOW);
  setRightDirection(HIGH);
}


void setLeftSpeed(float output) {
  float s = robotSpeed + output;
  if ( s > 0) {
    setLeftDirection(HIGH);
    analogWrite(LEFT_SPEED, s);
  } else {
    setLeftDirection(LOW);
    analogWrite(LEFT_SPEED, -s);
  }
}

void setRightSpeed(float output) {
  float s = robotSpeed + output;
  if ( s > 0) {
    setRightDirection(HIGH);
    analogWrite(RIGHT_SPEED, s);
  } else {
    setRightDirection(LOW);
    analogWrite(RIGHT_SPEED, -s);
  }
}


