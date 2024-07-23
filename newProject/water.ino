float resval;

//initialization
void config_water() {
  pinMode(WATER_PIN, INPUT);
}
//Checking if it's raining
bool is_raining() {

  String print_str;
  //Read data from analog pin and store it to resval variable
  resval = analogRead(WATER_PIN);  
  print_str = "water is: " + String(resval);
 // Serial.println(print_str);
  return resval>3000;
  
}