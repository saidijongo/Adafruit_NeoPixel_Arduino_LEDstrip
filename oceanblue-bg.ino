#include <FastLED.h>

#define LED_PIN 8
#define NUM_LEDS 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // Turn lights from ocean blue to green from left to right
  for (int i = 0; i < NUM_LEDS - 2; i++) {
    leds[i] = CRGB(26, 70, 71);  // Ocean blue background
    leds[i + 1] = CRGB(0, 255, 0); // Green LEDs
    leds[i + 2] = CRGB(0, 255, 0);
    FastLED.setBrightness(255); // Full brightness for green LEDs
    FastLED.show();
    delay(100);
    leds[i] = CRGB(26, 70, 71); // Restore ocean blue background
    leds[i + 1] = CRGB::Black; // Turn off green LEDs
    leds[i + 2] = CRGB::Black;
    FastLED.show();
  }
  
  // Turn lights from green to ocean blue from right to left
  for (int i = NUM_LEDS - 1; i >= 2; i--) {
    leds[i] = CRGB(26, 70, 71);  // Ocean blue background
    leds[i - 1] = CRGB(0, 255, 0); // Green LEDs
    leds[i - 2] = CRGB(0, 255, 0);
    FastLED.setBrightness(255); // Full brightness for green LEDs
    FastLED.show();
    delay(100);
    leds[i] = CRGB(26, 70, 71); // Restore ocean blue background
    leds[i - 1] = CRGB::Black; // Turn off green LEDs
    leds[i - 2] = CRGB::Black;
    FastLED.show();
  }
}
