void config_LDR(){
  
   pinMode(LDR, INPUT );

}

void read_LDR() {

   int analogReadPin;
   String print_str;

   analogReadPin = analogRead(LDR);

   print_str = "ldr is: " + String(analogReadPin);
   Serial.println(print_str);

}