#include <SPI.h>
#include <SdFat.h>
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;

int redPin = 12;
int greenPin = 5;
int bluePin = 3;

void setup() {

  Serial.begin(9600);

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  //setup led rgb pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //start playing track 1
  MP3player.playTrack(2);
  
}

//do something else now
void loop() {
  setColor(255,0,0);
  Serial.println("red");
  delay(2000);
  setColor(0,255,0);
  Serial.println("green");
  delay(2000);
  setColor(0,0,255);
  Serial.println("blue");
  delay(2000);
}

void setColor(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

