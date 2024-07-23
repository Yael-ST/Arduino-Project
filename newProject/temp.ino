//initialization
void config_temp() {
  Wire.begin();
  Wire.beginTransmission(LM75_addr);
  Wire.write(0x0);
  Wire.endTransmission();
}
//Checks if the temperature is above 26
bool is_hot() {
  float temp = 0;
  String print_str;
  Wire.requestFrom(LM75_addr, 2);
  if (Wire.available()) {
    temp = ((Wire.read() << 8 | Wire.read()) >> 5) * 0.125;
    print_str = "temp is: " + String(temp);
    //Serial.println(print_str);
  }
  return temp>26;
}
