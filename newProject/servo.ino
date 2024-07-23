//initialization
void config_servo() {
  servo_win.attach(servo_win_pin);
  servo_door.attach(servo_door_pin);
}
void open_win(){
    servo_win.write(90);
}
void close_win() {
  servo_win.write(0);
}
void open_door(){
  servo_door.write(90);
}
void close_door(){
  servo_door.write(0);
}


/*
int angle=0, i=0; // the current angle of servo motor

void open_servo() {
  //servo.write(100);
    for(angle=0 ; angle<100 ; angle++) {
    servo.write(angle);
    delay(50);
 }
}


void close_servo() {
  servo.write(0);
//    for( ; angle>0 ; angle--) {
//    servo.write(angle);
//    delay(50);
//  }
}
*/
