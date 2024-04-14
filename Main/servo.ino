#include <ESP32Servo.h>

void config_servo(){
  myServo.attach(servo_pin);
  myServo.write(90);
}
void write_servo()
{
  myServo.write(90);
}