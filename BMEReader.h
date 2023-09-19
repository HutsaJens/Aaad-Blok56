#ifndef BMEREADER_H
#define BMEREADER_H

#include <Arduino.h>
#include <BME280I2C.h>
#include <Wire.h>

void setupBMEReader();
void getBMESensor(float* _temp, float* _hum, float* _pressure);


#endif