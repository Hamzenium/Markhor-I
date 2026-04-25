#include "Barometer.h"
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void Barometer::init() {
    bmp.begin(0x76);
}

float Barometer::read() {
    return bmp.readAltitude(1013.25);
}