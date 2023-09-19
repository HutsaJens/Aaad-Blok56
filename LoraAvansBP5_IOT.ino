#include "MHZ19Reader.h"
#include "BMEReader.h"
#include "PIRReader.h"
#include "LoadReader.h"

#include "TTNAbp.h"

#define BAUDRATE 9600
#define PIR_PIN 3  // pin 2 to which the pir sensor is attached
#define CLK 14      // pins of the loadcell
#define DOUT 15

void setup() {

  Serial.begin(BAUDRATE);
  while (!Serial)
    ;  // Wait

  Wire.begin();


  Serial.println();
  Serial.println(F("Setup TTN"));
  setupTTN();

  // Serial.println(F("Setup MHZ19"));
  setupMHZ19(BAUDRATE);

  // Serial.println(F("Setup BME"));
  setupBMEReader();

  // Serial.println(F("Setup pir"));
  setupPir(PIR_PIN);

  // Serial.println(F("Setup Load"));
  setupLoadCell(DOUT, CLK);

  Serial.println(F("Setup done"));
}

void loop() {

  static int last_time = millis();
  int current_time = millis();

  os_runloop_once();

  if (current_time - last_time >= 2000) {


    Serial.print(F("Co2: "));
    Serial.println(getCO2Value());

    Serial.print(F("Load: "));
    Serial.println(getLoad());

    Serial.print(F("Pir: "));
    Serial.println(readPir());

    float temp, hum, pres;
    getBMESensor(&temp, &hum, &pres);
    Serial.print(F("temp: "));
    Serial.println(temp);
    Serial.print(F("hum: "));
    Serial.println(hum);
    Serial.print(F("press: "));
    Serial.println(pres);

    Serial.println();
    last_time = current_time;
  }

  if (Serial.available()) {
    char temp = Serial.read();
    if (temp == 't')
      tareScale();
  }
}
