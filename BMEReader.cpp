#include "BMEReader.h"

#include <Arduino.h>
#include <BME280I2C.h>
#include <Wire.h>

BME280I2C bme;

void setupBMEReader() {
  // Start BME object and wait until it is ready
  while (!bme.begin()) {
    Serial.println(F("Could not find BME280 sensor!"));
    delay(1000);
  }
}


void getBMESensor(float* _temp, float* _hum, float* _pressure) {

  // Specify the types of the tempeture and pressure
  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
  BME280::PresUnit presUnit(BME280::PresUnit_bar);

  // read the sensor and store the results in the corsponding vars
  bme.read(*_pressure, *_temp, *_hum, tempUnit, presUnit);

}
