#include <SPI.h>
#include <SdFat.h>
#include <SFEMP3Shield.h>
#include <TimeLib.h>

#include <Adafruit_NeoPixel.h>

#define PIN 15

//libaries for the mp3 shield
SdFat sd;
SFEMP3Shield MP3player;

//Adafruit NeoPixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  //NeoPixel
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show();
  
  Serial.begin(9600);
}

//do something else now
void loop() {
  MP3player.playTrack(1);
  colorWipe(strip.Color(255, 0, 0), 50); // Red
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
