extern int mode;

long lastTime = 0;
long timeNow;

void loop() {
  if (Serial.available()) {
    handleCommand(Serial.read());
  }

  timeNow = millis();
  if (timeNow - lastTime >= SAMPLE_TIME ) {
    lastTime = timeNow;
    if (mode == LINE_FOLLOWER) {
      float e = getLineError(readLineSensors());
      float o = calculatePID(e);
      applyOutput(o);
    }
  }
}
/*

  471 565 660
  92  212 333
  280 345 410
  109 227 345
  332 415 499

*/

