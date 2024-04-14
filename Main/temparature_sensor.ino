
void config_temp(byte add) {
  
    Wire.beginTransmission(add);
    Wire.write(0x0);
    Wire.endTransmission();
}

float read_temp(int add) {

  float temp;
 
  Wire.requestFrom(add, 2);

  if(Wire.available()) {
   temp = ((Wire.read() << 8 | Wire.read()) >> 5) * 0.125;
   return temp;
  }
}
