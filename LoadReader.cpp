#include "LoadReader.h"

#include <Arduino.h>

//This value is obtained using the SparkFun_HX711_Calibration sketch
#define calibration_factor -994.7156

// new scale object
HX711 scale;

void setupLoadCell(int DOUT, int CLK) {
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare(); // set scale to zero, so make sure the scale is empty when first running the sketch
}

void tareScale() {
  scale.tare();
}


// get a load of this guy
// and return the weight
float getLoad() {
  return scale.get_units();
}