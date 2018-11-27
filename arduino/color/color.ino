#include <Wire.h>
#include "Adafruit_TCS34725.h"


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
long startTime;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int red = 0;
int green = 50;
int blue = 50;
int rele = 4;
int runstatus = 5;

void setup(void) {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(rele,OUTPUT);
  digitalWrite(rele,0);
  pinMode(runstatus,INPUT_PULLUP);
  Serial.begin(115200);

  if (tcs.begin()) {
    analogWrite(redPin,255);
    analogWrite(bluePin,255);
    analogWrite(greenPin,0);
    
  } else {
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
    analogWrite(greenPin,255);
    while (1);
  }
    tcs.setInterrupt(true);


    
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

while(digitalRead(runstatus) == LOW)
{
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);
  digitalWrite(rele,1);
  startTime = millis(); 
  while(digitalRead(runstatus) == LOW)
{
  tcs.getRawData(&r, &g, &b, &c);

  Serial.print(r, DEC); Serial.print(" ");
  Serial.print(g, DEC); Serial.print(" ");
  Serial.print(b, DEC); Serial.print(" ");
  Serial.print(c, DEC); Serial.print(" ");
  Serial.print(millis() - startTime, DEC); Serial.println("");
  delay(188);
}
digitalWrite(rele,0);
analogWrite(redPin,255);
analogWrite(bluePin,255);
}
}
