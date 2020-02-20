int mode = MANUAL_CONTROL;


void setupSerial() {
  Serial.begin(9600);
}

void handleCommand(char val) {
  Serial.println(val);
  if (val == 'X') {
    errorSum =0;
    mode = LINE_FOLLOWER;
  } else if (val == 'x') {
    mode = MANUAL_CONTROL;
  } else  if (mode == MANUAL_CONTROL) {
    if (val == 'F') {
      moveForward();
    } else  if (val == 'B') {
      moveBackward();
    } else   if (val == 'R') {
      moveRight();
    }  else if (val == 'L') {
      moveLeft();
    } else  if (val == 'S') {
      stopRobot();
      //    robotSpeed = 0;
    }  else if (val >= '0' && val <= '9') {
      int v = val - '0';
      v *= 20;
      Serial.println(v);
      robotSpeed = v;
    }
    setSpeed(robotSpeed, robotSpeed);
  } else if (mode == LINE_FOLLOWER) {
    if (val == 'F') {
      Kp++;
    } else  if (val == 'B') {
      Kp--;
    } else   if (val == 'R') {
      Ki++;
    }  else if (val == 'L') {
      Ki--;
    }
  }
}

