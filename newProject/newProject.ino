#include <Wire.h>               //temparature
#include <ESP32Servo.h>         //servo
#include <Adafruit_NeoPixel.h>  //smart leds
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <WiFi.h>
#include <string.h>

#define servo_win_pin 13
#define servo_door_pin 4

#define i2c_Address 0x3c
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO

#define LM75_addr 0x48  //temparature

#define WATER_PIN 12

#define FAN_IN_A 25  //fan
#define FAN_IN_B 26  //fan

#define LEDS_PIN 18
#define NUMPIXELS 24  // How many NeoPixels are attached to the Arduino

#define ECHO_PIM 32  //ultrasonic
#define TRIG_PIM 33  //ultrasonic

//chip
#define BUFFER_SIZE 14
#define DATA_SIZE 10
#define DATA_VERSION_SIZE 2
#define DATA_TAG_SIZE 8
#define CHECKSUM_SIZE 2

uint8_t buffer[BUFFER_SIZE];

int buffer_index = 0;
typedef struct user {
  String nameUser;
  String chipNum;
} user;
byte users_size = 1;
user users[4] = { { "Yael", "00D34DDA" }, { "", "" }, { "", "" }, { "", "" } };
bool is_register = false;
String chipID = "";
//chip-end

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDS_PIN, NEO_GRB + NEO_KHZ800);  //LEDs
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo servo_win;
Servo servo_door;

bool is_web = false;
void setup() {
  Serial.begin(115200);
  config_RFID();
  config_servo();
  config_temp();
  config_fan();
  config_ultrasoni();
  config_water();
  config_OLED();
  config_WiFi();
}

void loop() {
  read_RFID();  //פתיחת הדלת באמצעות ציפ
  if (is_register){
    open_door();
    is_register=false;
  }    
  if (!is_web) {
    if (is_raining()) {  //סגירת חלון אם יורד גשם
      close_win();
    }

    if (is_hot() && is_anyone_here()) {  //הדלקת/ כיבוי מאוורר לפי טמפרטורה.
      fan_on();
    } else {
      fan_off();
    }

    if (is_anyone_here()) {  //הדלקת אור אם הוא מזהה מישהו
      LEDs_on();
    } else {
      LEDs_off();
    }
  }
  WiFi2();
}