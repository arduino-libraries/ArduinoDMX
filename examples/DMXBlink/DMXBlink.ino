/*
  DMX Blink

  This sketch toggles the value of DMX channel 1 between 255 and 0.

  Circuit:
   - DMX light
   - MKR board
   - MKR 485 shield
     - ISO GND connected to DMX light GND (pin 1)
     - Y connected to DMX light Data + (pin 2)
     - Z connected to DMX light Data - (pin 3)
     - Jumper positions
       - Z \/\/ Y set to ON

  created 5 July 2018
  by Sandeep Mistry
*/

#include <ArduinoRS485.h> // the ArduinoDMX library depends on ArduinoRS485
#include <ArduinoDMX.h>

const int universeSize = 16;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // initialize the DMX library with the universe size
  if (!DMX.begin(universeSize)) {
    Serial.println("Failed to initialize DMX!");
    while (1); // wait for ever
  }
}

void loop() {
  // set channel 1 value to 255
  DMX.beginTransmission();
  DMX.write(1, 255);
  DMX.endTransmission();

  delay(1000);

  // set channel 1 value to 0
  DMX.beginTransmission();
  DMX.write(1, 0);
  DMX.endTransmission();

  delay(1000);
}

