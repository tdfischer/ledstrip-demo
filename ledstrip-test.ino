#include <FastLED.h>

// How many LEDs are in our strip?
#define NUM_LEDS 100

// Define the space in the Teensy's memory where the LEDs will live.
CRGB leds[NUM_LEDS];

void setup() {
  // We add our strip of WS2812B on pin 13
  FastLED.addLeds<WS2812B, 13>(leds, NUM_LEDS);

  // This loop sets all of our LEDs to RGB(0, 0, 0), aka black.
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }

  // Instruct FastLED to write the color data to your LED strip.
  FastLED.show();
}

uint8_t hue = 0;
uint8_t sat = 255;

void loop() {
  // Loop through every LED in the strip and set its color
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, sin8(sat), 128);
  }

  // Hue and saturation shift
  hue += 1;
  sat += 4;

  // Render the frame
  FastLED.show();

  // With a small number of LEDs, the above code will render frames in just a
  // few microseconds - faster than a human eye can appreciate! This 10ms delay
  // will slow things down and produce a smoother animation.
  delay(10);
}
