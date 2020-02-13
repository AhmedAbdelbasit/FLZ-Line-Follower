
void loop(){
  if (Serial.available()) {
    handleCommand(Serial.read());
  }
}

