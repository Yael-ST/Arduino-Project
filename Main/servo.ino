
void config_servo() {
  myServo.attach(servo_pin);
  myServo.write(90);
}


void close_window() {
  servo_win.write(90);
}
void open_door(){

}