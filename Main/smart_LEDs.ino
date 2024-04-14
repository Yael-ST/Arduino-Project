void config_LEDs() {
  pixels.begin();  // This initializes the NeoPixel library.
}

void on_LEDs() {
  for (byte i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, random(255), random(255), random(255)); // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.show();                                                   // This sends the updated pixel color to the hardware.
  }

}

void off_LEDs() {

  pixels.clear();
  pixels.show();

}
