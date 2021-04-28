#include <FastLED.h>
#include <pixeltypes.h>

#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 1
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup() {
  delay(1000);
  // WS2812 Type, PIN 7
  FastLED.addLeds<WS2812,7,GRB>(leds[0], NUM_LEDS_PER_STRIP);
}

void loop() {
    leds[0][0] = CRGB::Blue;
    FastLED.show();
}
