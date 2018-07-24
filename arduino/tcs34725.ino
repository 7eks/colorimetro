#include <Wire.h>
#include "Adafruit_TCS34725.h"


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_4X);
long startTime;

void setup(void) {
  Serial.begin(115200);

    tcs.begin();
    delay(1000);
    //da aggiungere conferma via Led
    startTime = millis();
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);


  Serial.print(r, DEC); Serial.print(" ");
  Serial.print(g, DEC); Serial.print(" ");
  Serial.print(b, DEC); Serial.print(" ");
  Serial.print(c, DEC); Serial.print(" ");
  Serial.print(millis() - startTime, DEC); Serial.println("");
  delay(200);
};
