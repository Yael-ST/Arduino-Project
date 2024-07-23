
void config_OLED() {
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);  //(1,0)
  display.setTextSize(1);
}

void print_OLED(String print_str) {

  display.clearDisplay();
  display.setCursor(35, 10);
  display.print(print_str);
  display.display();
}

void clear_OLED(){
  display.clearDisplay();
  display.display();
}
