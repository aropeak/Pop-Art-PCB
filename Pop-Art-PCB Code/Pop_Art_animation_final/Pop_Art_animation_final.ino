#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(24, 0);

#include <Bounce2.h>
Bounce button1 = Bounce();

char colors[9][3] {
  {255, 0, 255},
  {255, 128, 0},
  {255, 0, 0},
  {0, 255, 0},
  {0, 0, 255},
  {0, 255, 255},
  {255, 255, 255},
  {255, 255, 0},
  {153, 76, 0},
};


char whichFrame = 0;

char caseVal = 0;

long previousMillis = 0;
long intervals = 1000;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  strip.setBrightness(255);

  button1.attach(1, INPUT);
  button1.interval(5);

}

void loop() {
  // put your main code here, to run repeatedly:


  button1.update();
  if (button1.rose()) {
    caseVal = (caseVal + 1) % 4;
  }

  switch (caseVal) {
    case 0: off(); break;
    case 1:
      on();
      break;
    case 2:
     // simple();
      break;
    case 3:
      anime();
      break;
  }
}

void off() {
  strip.clear();
  strip.show();
}

void on() {
  strip.setPixelColor(0, 0, 255, 255);
  strip.setPixelColor(1, 0, 255, 255);
  strip.setPixelColor(2, 0, 255, 255);
  strip.setPixelColor(3, 0, 255, 255);
  strip.setPixelColor(4, 255, 255, 255);
  strip.setPixelColor(5, 255, 255, 255);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 255, 255);
  strip.setPixelColor(8, 255, 255, 255);
  strip.setPixelColor(9, 255, 0, 0);
  strip.setPixelColor(10, 255, 255, 255);
  strip.setPixelColor(11, 255, 255, 255);
  strip.setPixelColor(12, 255, 255, 255);
  strip.setPixelColor(13, 255, 255, 0);
  strip.setPixelColor(14, 255, 255, 255);
  strip.setPixelColor(15, 255, 255, 255);
  strip.setPixelColor(16, 255, 255, 255);
  strip.setPixelColor(17, 0, 0, 255);
  strip.setPixelColor(18, 255, 255, 255);
  strip.setPixelColor(19, 255, 255, 255);
  strip.setPixelColor(20, 255, 0, 0);
  strip.setPixelColor(21, 255, 0, 0);
  strip.setPixelColor(22, 255, 0, 0);
  strip.setPixelColor(23, 255, 0, 0);

  strip.show();
}

//void simple() {
//
//  for (int j = 0; j < strip.numPixels(); j++) {
//
//    for (int i = 0; i < 255; i++) {
//      button1.update();
//      strip.setPixelColor(j, 51, 204, 51);
//
//      strip.setBrightness(i);
//      strip.show();
//    }
//    for (int i = 255; i < 255; i--) {
//      button1.update();
//      strip.setPixelColor(j, 51, 204, 51);
//
//      strip.setBrightness(i);
//      strip.show();
//    }
//  }
//
//
//  for (int j = 0; j < strip.numPixels(); j++) {
//
//    for (int i = 0; i < 255; i++) {
//      button1.update();
//      strip.setPixelColor(j, 255, 0, 255);
//
//      strip.setBrightness(i);
//      strip.show();
//    }
//    for (int i = 255; i < 255; i--) {
//      button1.update();
//      strip.setPixelColor(j, 255, 0, 255);
//
//      strip.setBrightness(i);
//      strip.show();
//    }
//  }
//
//}


void anime() {
  unsigned long currentMillis = millis();

  for (int i = 0; i < strip.numPixels(); i++) {
    char pixAddress = pixelMap[i];
    char whichColor = animation[whichFrame][i];
    char red = colors[whichColor][0];
    char green = colors[whichColor][1];
    char blue = colors[whichColor][2];
    if (pixAddress != -1) {
      strip.setPixelColor(pixAddress, red, green, blue);
    }

  }
  strip.show();
  if (currentMillis - previousMillis > intervals) {
    previousMillis = currentMillis;

    whichFrame = (whichFrame + 1) % 6;
  }
}
