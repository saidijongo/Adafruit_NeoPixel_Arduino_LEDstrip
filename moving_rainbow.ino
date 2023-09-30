#include <FastLED.h>

#define NUM_LEDS 6
#define LED_PIN 6
#define BRIGHTNESS 100

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(115200);
}

void loop() {
  static uint8_t startIndex = 0;
  static uint8_t hue = 0;

  // Fill the entire LED strip with a rainbow gradient
  fill_rainbow(leds, NUM_LEDS, hue, 2);
  
  // Move the rainbow effect from left to right
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = leds[(i + startIndex) % NUM_LEDS];
  }

  FastLED.show();
  FastLED.delay(30);

  // Increment the rainbow hue to change colors
  hue++;

  // Move the rainbow gradient index
  startIndex++;
  if (startIndex >= NUM_LEDS) {
    startIndex = 0;
  }
}
