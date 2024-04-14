void config_LDR() {

  pinMode(LDR, INPUT);
}

bool read_LDR() {

  analogReadPin = analogRead(LDR);
  if (analogReadPin < 2000)
    return true;

  return false;
  
}
