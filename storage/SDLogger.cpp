#include "SDLogger.h"
#include <SD.h>
#include <SPI.h>

File file;

void SDLogger::init() {
    SD.begin(5);

    file = SD.open("/flight.csv", FILE_WRITE);
    file.println("t,ax,ay,az,vx,vy,vz,alt");
    file.close();
}

void SDLogger::log(float t, IMUData imu,
                   float vx, float vy, float vz,
                   float alt) {

    file = SD.open("/flight.csv", FILE_APPEND);

    if (file) {
        file.print(t); file.print(",");
        file.print(imu.ax); file.print(",");
        file.print(imu.ay); file.print(",");
        file.print(imu.az); file.print(",");
        file.print(vx); file.print(",");
        file.print(vy); file.print(",");
        file.print(vz); file.print(",");
        file.println(alt);

        file.close();
    }
}