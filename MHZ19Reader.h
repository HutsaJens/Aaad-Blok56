#include <stdint.h>
#ifndef MHZ19READER_H
#define MHZ19READER_H

#include "MHZ19.h"
#include <SoftwareSerial.h> 

void setupMHZ19(int BAUDRATE);
uint16_t getCO2Value();

#endif