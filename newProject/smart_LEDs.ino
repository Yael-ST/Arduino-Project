//initialization
void config_LEDs() {
  pixels.begin();  // This initializes the NeoPixel library.
}

void LEDs_on() {
  for (byte i = 0; i < NUMPIXELS; i++) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, 255, 255, 255);
     // This sends the updated pixel color to the hardware.
    pixels.show();                                                  
  }

}

void LEDs_off() {
  pixels.clear();
  pixels.show();
}
