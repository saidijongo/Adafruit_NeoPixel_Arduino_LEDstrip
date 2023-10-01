#include <FastLED.h>

#define LED_PIN 8
#define NUM_LEDS 6

#define BRIGHTNESS 20  // Specify the size of the group

CRGB leds[NUM_LEDS];

float animation = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); 
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {

  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CHSV(animation + (i * (255 / (NUM_LEDS))), 255, 255);
  }

  FastLED.show();
  animation += 0.3;
}
