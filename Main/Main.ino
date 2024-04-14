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
#define NUMPIXELS 24  // How many NeoPixels are attached to the Arduino?
#define LDR 4

Servo myServo;
float resval;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDS_PIN, NEO_GRB + NEO_KHZ800);  //LEDs
void setup() {
  Serial.begin(115200);
  config_servo(myServo);
  configTemp(LM75_addr);
  config_fan();
  config_pir();
}

void loop() {
  if (water_sensor()) {  //סגירת חלון אם יורד גשם
    write_servo(myServo);
  }
  if (readTemp(LM75_addr) >= 30)  //הדלקת/ כיבוי מאוורר באופן אוטומטי לפי טמפרטורה.
  {
    on_fan();
  } 
  else 
  {
    off_fan();
  }
  if (read_pir()) //הדלקת לד אם י ש תנועה בחדר וכיבוי כשאין
  {
    on_LEDs();
  }
  else
  {
    off_LEDs();
  }
}
