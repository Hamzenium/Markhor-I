#include "IMU.h"
#include <Adafruit_MPU6050.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void IMU::init() {
    Wire.begin(21, 22);
    mpu.begin();
}

IMUData IMU::read() {
    sensors_event_t a, g, t;
    mpu.getEvent(&a, &g, &t);

    IMUData data;
    data.ax = a.acceleration.x;
    data.ay = a.acceleration.y;
    data.az = a.acceleration.z;

    return data;
}