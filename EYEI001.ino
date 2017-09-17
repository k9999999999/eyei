#include <SPI.h>
#include <SdFat.h>
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;

int redPin = 12;
int greenPin = 5;
int bluePin = 3;
int btnPin = 0;
int val = 0;

void setup() {

  Serial.begin(9600);
  pinMode(btnPin, INPUT);
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
  val = digitalRead(btnPin);
  if(val == HIGH){
      setColor(255, 0,0);
  }else{
      setColor(0,0,255);
  }
}

void setColor(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;

  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}

