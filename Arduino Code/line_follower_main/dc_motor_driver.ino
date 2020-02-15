int robotSpeed = 100;

void setupDCMotors() {
  pinMode(LEFT_SPEED, INPUT);
  pinMode(RIGHT_SPEED, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void setSpeed(int leftSpeed, int rightSpeed) {
  analogWrite (LEFT_SPEED, leftSpeed);
  analogWrite (RIGHT_SPEED, rightSpeed);
}

void moveForward () {
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite (LM1, HIGH);
  digitalWrite (LM2, LOW);
}

void moveBackward () {
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
  digitalWrite (LM1, LOW);
  digitalWrite (LM2, HIGH);
}

void stopRobot () {
  setSpeed(0, 0);
}

void moveRight() {
  digitalWrite (LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite (RM1, LOW);
  digitalWrite(RM2, LOW);
}

void moveLeft() {
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
}


void setLeftSpeed(float output) {
  float s = robotSpeed + output;
  if ( s > 0) {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(LEFT_SPEED, s);
  } else {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    analogWrite(LEFT_SPEED, -s);
  }
}

void setRightSpeed(float output) {
  float s = robotSpeed + output;
  if ( s > 0) {
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(RIGHT_SPEED, s);
  } else {
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(RIGHT_SPEED, -s);
  }
}


