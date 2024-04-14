void config_buzzer() {
  pinMode(tonepin, OUTPUT);
}
void buzzer_on() {
  digitalWrite(tonepin, HIGH);  // Sound
  delay(1000);
  digitalWrite(tonepin, HIGH);  // Sound
  delay(1000);
  digitalWrite(tonepin, HIGH);  // Sound
  delay(1000);
}
void buzzer_off(){
  digitalWrite(tonepin, LOW);  // Sound 
}
