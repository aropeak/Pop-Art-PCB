#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(24, 0);

int colors2[3][3] {
  {51, 255, 51},
  {255, 51, 255},
  {255, 255, 255}
};

int whichFrame = 0;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  strip.setBrightness(50);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < strip.numPixels(); i++) {
    int pixAddress = pixelMap[i];
    int whichColor = animation[whichFrame][i];
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];
    if (pixAddress != 1) {
      strip.setPixelColor(pixAddress, red, green, blue);
    }
    
  }
  strip.show();
  delay(500);
  whichFrame = (whichFrame + 1) % 2;
  
}
