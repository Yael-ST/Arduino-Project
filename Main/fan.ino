void config_fan()
{
  pinMode(FAN_IN_A, OUTPUT);
  pinMode(FAN_IN_B, OUTPUT);
}

void on_fan()
{
    // LEFT - fan
  digitalWrite(FAN_IN_A, LOW);
  digitalWrite(FAN_IN_B, HIGH);
}
void off_fan(){
  digitalWrite(FAN_IN_A, LOW);
  digitalWrite(FAN_IN_B, LOW);
}