const int motorLspeed = 9;
const int motorRspeed = 11;

void setup_dc_motors() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void moveForward (int SPEED , int forwadDistanse, int DEALY) {
  if (LS > forwadDistanse && RS > forwadDistanse ) {
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    digitalWrite (LM1, HIGH);
    digitalWrite (LM2, LOW);
    analogWrite (motorLspeed, SPEED);
    analogWrite (motorRspeed, SPEED);
    delay(DEALY);
  }
}

void STOP ( int stopDistanse) {
  if (RS < stopDistanse && RS < stopDistanse) {
    analogWrite (motorLspeed, 0);
    analogWrite (motorRspeed, 0);
  }
}

void moveRight( int turnSpeed , int turnDistanse , int DELAY) {
  if (RS > turnDistanse && LS < turnDistanse) {
    digitalWrite (LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite (RM1, LOW);
    digitalWrite(RM2, LOW);
    analogWrite (motorLspeed, turnSpeed);
    analogWrite (motorRspeed, turnSpeed);
    delay(DELAY);
  }
}

void moveLeft( int turnSpeed , int turnDistanse , int DELAY) {
  if (RS < turnDistanse && LS > turnDistanse) {
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite (motorLspeed, turnSpeed);
    analogWrite (motorRspeed, turnSpeed);
    delay(DELAY);
  }
}

