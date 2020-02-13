void setupSerial() {
  Serial.begin(9600);
}

void handleCommand(char val) {
  if (val == 'F') {
    moveForward();
  }
  if (val == 'B') {
    moveBackward();
  }
  if (val == 'R') {
    moveRight();
  }
  if (val == 'L') {
    moveLeft();
  }
  if (val == 'S') {
    stopRobot();
  }

}

