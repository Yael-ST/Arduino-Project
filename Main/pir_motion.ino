void config_pir(){
  pinMode(PIR_PIN, INPUT); 

}
bool read_pir(){
  return digitalRead(PIR_PIN);
}