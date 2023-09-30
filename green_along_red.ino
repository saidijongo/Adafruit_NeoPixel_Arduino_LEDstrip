#include <FastLED.h>

#define NUM_LEDS 6
#define LED_PIN 6

CRGB leds[NUM_LEDS];

// Number of LEDs in the moving group
#define GROUP_SIZE 2

// Animation delay in milliseconds
#define ANIMATION_DELAY 100 // Decreased delay for faster movement

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10); // Adjust the brightness as needed
}

void loop() {
  // Initialize color values
  CRGB magenta = CRGB(255, 0, 255);
  CRGB green = CRGB(0, 255, 0);

  // Move the group of green LEDs from left to right
  for (int i = 0; i <= NUM_LEDS - GROUP_SIZE; i++) {
    for (int j = 0; j < GROUP_SIZE; j++) {
      leds[i + j] = green;
    }
    FastLED.show();
    delay(ANIMATION_DELAY);
    // Clear the group
    for (int j = 0; j < GROUP_SIZE; j++) {
      leds[i + j] = CRGB::Red;
    }
  }

  // Move the group of green LEDs from right to left
  for (int i = NUM_LEDS - GROUP_SIZE; i >= 0; i--) {
    for (int j = 0; j < GROUP_SIZE; j++) {
      leds[i + j] = green;
    }
    FastLED.show();
    delay(ANIMATION_DELAY);
    // Clear the group
    for (int j = 0; j < GROUP_SIZE; j++) {
      leds[i + j] = CRGB::Red;
    }
  }
}
