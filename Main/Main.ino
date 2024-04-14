#include <Wire.h>               //temparature
#include <ESP32Servo.h>         //servo
#include <Adafruit_NeoPixel.h>  //smart leds

#define servo_pin 18
#define WATER_PIN 15
#define LM75_addr 0x48  //temparature
#define FAN_IN_A 25     //fan
#define FAN_IN_B 33     //fan
#define PIR_PIN 2
#define LEDS_PIN 18
#define NUMPIXELS 24  // How many NeoPixels are attached to the Arduino
#define LDR 4
#define tonepin = 3;  // buzzer
#define MQ2 = 5;      //gas

Servo servo_win;
Servo servo_door;
float resval;
int val = 0;                                                                              // declare variable for gas sensor
int analogReadPin;                                                                        //declare variable for LDR;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDS_PIN, NEO_GRB + NEO_KHZ800);  //LEDs
void setup() {
  Serial.begin(115200);
  config_servo(myServo);
  config_temp(LM75_addr);
  config_fan();
  config_pir();
  config_buzzer();
}

void loop() {

  if (read_water()) {  //סגירת חלון אם יורד גשם
    close_window(myServo);
  }

  if (read_temp(LM75_addr) >= 30) {  //הדלקת/ כיבוי מאוורר באופן אוטומטי לפי טמפרטורה.
    fan_on();
  } else {
    fan_off();
  }

  if (read_pir() && read_LDR()) {  //הדלקת לד אם י ש תנועה בחדר וכיבוי כשאין
    LEDs_on();
  } else {
    LEDs_off();
  }
  if (read_gas()) {  //הדלקת זמזם אם יש ריכוז גבוה של גז
    buzzer_on();
  } else {
    buzzer_off();
  }
}
