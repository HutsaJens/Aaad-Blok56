#include "PIRReader.h"

#include <Arduino.h>

uint8_t _pirPin;

// setup the pin of the put as input
void setupPir(int pirPin) {
  _pirPin = pirPin;
  pinMode(_pirPin, INPUT);
}

// return pir status
bool readPir() {
  return digitalRead(_pirPin);
}