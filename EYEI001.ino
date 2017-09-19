#include <SPI.h>
#include <SdFat.h>
#include <SFEMP3Shield.h>

//libaries for the mp3 shield
SdFat sd;
SFEMP3Shield MP3player;

//set values of led rgb pins

int redPin = 12;
int greenPin = 5;
int bluePin = 3;

int pushButton = 0;

int val = 0;
int deviceOn = false;

void setup() {


  
  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();

  //setup led rgb pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColor(0,0,0);
  pinMode(pushButton, INPUT_PULLUP);
  
  Serial.begin(9600);
}

//do something else now
void loop() {
  val = digitalRead(pushButton);

  Serial.println(deviceOn);
  if(deviceOn){
    
  }else{
    
  }
  
  if(val == LOW){
    //button is pressed  
    if(deviceOn){
      deviceOn = false;
      Serial.println("device turned off");
    }else{
      deviceOn = true;
      Serial.println("device turned on");
    }
    delay(1000);
  }else{
    //button releases
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

