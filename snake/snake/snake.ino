#include "FastLED.h"

#define NUM_LEDS 40
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

typedef struct Point {
  int x;
  int y;
};

int direction = 0;

int snake[1] = { 8 };
int snakelength = 1;

int mapping[5][8] = 
{
  {17, 18, 19, 20, 21, 22, 23, 24},
  {16, 15, 14, 13, 28, 27, 26, 25},
  { 9, 10, 11, 12, 29, 30, 31, 32},
  { 8,  7,  6,  5, 36, 35, 34, 33},
  { 1,  2,  3,  4, 37, 38, 39, 40},
};

Point getPointByIndex(int index) {
  int yCounts = sizeof(mapping)/sizeof(mapping[0]);
  int xCounts = sizeof(mapping[0])/sizeof(mapping[0][0]);
  for (int i = 0; i < xCounts; i++) {
    for (int j = 0; j < yCounts; j++) {
      if (mapping[j][i] == index) {
        Point retVal;
        retVal.x = i;
        retVal.y = j;
        return retVal;
      }
    }
  }
}

int getIndexByCoords(int x, int y)
{
  return mapping[y][x]-1;
}

void setLed(int x, int y, CRGB col)
{
  leds[getIndexByCoords(x, y)] = col;
}



void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  
  Point foobar = getPointByIndex(9);
  Serial.print("X: ");
  Serial.println(foobar.x);
  Serial.print("Y: ");
  Serial.println(foobar.y);
  setLed(foobar.x, foobar.y, CRGB::Green);

  FastLED.show();
}
