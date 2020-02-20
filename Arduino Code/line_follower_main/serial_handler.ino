void setupSerial() {
  Serial.begin(9600);
}

void handleCommand(char val) {
  Serial.println(val);
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

  else if (val>='0' && val <= '9'){
    int v = val - '0';
    v *=20;
    Serial.println(v);
    setSpeed(v, v);
  }
}

