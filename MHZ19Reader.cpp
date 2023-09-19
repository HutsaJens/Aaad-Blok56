#include "MHZ19Reader.h"

#include <MHZ19.h>
#include <SoftwareSerial.h>

#define RX_PIN 4  // Green   // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 5  // Blue    // Tx pin which the MHZ19 Rx pin is attached to

MHZ19 myMHZ19;                            // Constructor for library
SoftwareSerial mySerial(RX_PIN, TX_PIN);


// TODO: CHeck if this works, should do the trick
void setupMHZ19(int BAUDRATE) {
  
  mySerial.begin(BAUDRATE);  // (Uno example) device to MH-Z19 serial start

  myMHZ19.begin(mySerial);   // *Serial(Stream) refence must be passed to library begin().
  myMHZ19.autoCalibration(true);  // Turn auto calibration ON (OFF autoCalibration(false))
}

uint16_t getCO2Value() {
  return myMHZ19.getCO2();  // Request CO2 (as ppm)
}
