//initialization
void config_fan() {
  pinMode(FAN_IN_A, OUTPUT);
  pinMode(FAN_IN_B, OUTPUT);
}

void fan_on() {
  // LEFT - fan
  digitalWrite(FAN_IN_A, LOW);
  digitalWrite(FAN_IN_B, HIGH);
}
void fan_off(){
  digitalWrite(FAN_IN_A, LOW);
  digitalWrite(FAN_IN_B, LOW);
}