
//initialization
void config_ultrasoni() {
  pinMode(ECHO_PIM, INPUT);
  pinMode(TRIG_PIM, OUTPUT);
}
//Checking if anyone is found
bool is_anyone_here() {

   long duration, distance;
   String print_str;

  digitalWrite(TRIG_PIM, HIGH);       // the trigger
  delayMicroseconds(10);              // Waiting 10 ms
  digitalWrite(TRIG_PIM, LOW);        // the trigger

  duration = pulseIn(ECHO_PIM, HIGH); // Calculate the assert time

  distance = duration/58;             // Convert to cm

 print_str = "distance is: " + String(distance);
 //Serial.println(print_str);

return distance<12;
}