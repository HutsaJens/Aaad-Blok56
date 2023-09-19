#ifndef TTNABP_H
#define TTNABP_H

#include <Arduino.h>

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

void setupTTN();
void onEvent(ev_t ev);
void do_send(osjob_t* j);


#endif