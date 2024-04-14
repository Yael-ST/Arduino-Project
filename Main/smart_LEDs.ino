void config_LEDs() {
  pixels.begin();  // This initializes the NeoPixel library.
}
void on_LEDs() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for (byte i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, random(255), random(255), random(255));  // Moderately bright green color.
    pixels.show();                                                   // This sends the updated pixel color to the hardware.
    delay(100);                                                      // Delay for a period of time (in milliseconds).
  }
  pixels.clear();
  pixels.show();

  delay(100);
}
void off_LEDs() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for (byte i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, random(0), random(0), random(0));  // Moderately bright green color.
    pixels.show();                                             // This sends the updated pixel color to the hardware.
    delay(100);                                                // Delay for a period of time (in milliseconds).
  }
  pixels.clear();
  pixels.show();

  delay(100);
}
