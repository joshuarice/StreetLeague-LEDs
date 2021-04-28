#include <FastLED.h>
#include <pixeltypes.h>

#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 1
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

int i = 0;

void setup() {
  delay(1000);
  // Front Right (PIN 7)
  FastLED.addLeds<WS2812,7,GRB>(leds[0], NUM_LEDS_PER_STRIP);
  // Front Left (PIN 8)
  FastLED.addLeds<WS2812,8,GRB>(leds[1], NUM_LEDS_PER_STRIP);
  // Back Left (PIN 9)
  FastLED.addLeds<WS2812,9,GRB>(leds[2], NUM_LEDS_PER_STRIP);
  // Back Right (PIN 10)
  FastLED.addLeds<WS2812,10,GRB>(leds[3], NUM_LEDS_PER_STRIP);
  // Clockwise by current setup: 7, 10, 9, 8
}

void loop() {
  // alternating red/blue
  for (i = 0; i < 4; i++) {
    leds[0][0] = CRGB::Blue;
    leds[3][0] = CRGB::Red;
    leds[2][0] = CRGB::Blue;
    leds[1][0] = CRGB::Red;
    FastLED.show();
    delay(300);

    leds[0][0] = CRGB::Red;
    leds[3][0] = CRGB::Blue;
    leds[2][0] = CRGB::Red;
    leds[1][0] = CRGB::Blue;
    FastLED.show();
    delay(300);
  }
  
  // spinning blue bar
  for (i = 0; i < 4; i++) {
    leds[0][0] = CRGB::Blue;
    leds[3][0] = CRGB::Red;
    leds[2][0] = CRGB::Red;
    leds[1][0] = CRGB::Red;
    FastLED.show();
    delay(100);
  
    leds[0][0] = CRGB::Red;
    leds[3][0] = CRGB::Blue;
    leds[2][0] = CRGB::Red;
    leds[1][0] = CRGB::Red;
    FastLED.show();
    delay(100);
  
    leds[0][0] = CRGB::Red;
    leds[3][0] = CRGB::Red;
    leds[2][0] = CRGB::Blue;
    leds[1][0] = CRGB::Red;
    FastLED.show();
    delay(100);
  
    leds[0][0] = CRGB::Red;
    leds[3][0] = CRGB::Red;
    leds[2][0] = CRGB::Red;
    leds[1][0] = CRGB::Blue;
    FastLED.show();
    delay(100);
  }
}
