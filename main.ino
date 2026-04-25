#include "core/FlightController.h"

FlightCore flight;

void setup() {
    Serial.begin(115200);
    flight.init();
}

void loop() {
    flight.update();
    delay(20); // 50Hz loop
}