
void loop(){
  if (Serial.available()) {
    Serial.begin(9600);
    handleCommand(Serial.read());
  }
}

