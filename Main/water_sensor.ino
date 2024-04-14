bool read_water( ) {

  resval = analogRead(WATER_PIN);  //Read data from analog pin and store it to resval variable
  Serial.println(resval);

  if (resval <= 3000) {
    return false;
  }
  else if (resval > 3000 ) {
    return true;
  }

}