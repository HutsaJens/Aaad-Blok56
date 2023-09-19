#ifndef LOADREADER_H
#define LOADREADER_H

#include "HX711.h"

void setupLoadCell(int DOUT, int CLK);
float getLoad();
void tareScale();

#endif