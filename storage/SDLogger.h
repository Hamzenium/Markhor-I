#pragma once
#include "../sensors/IMU.h"

class SDLogger {
public:
    static void init();
    static void log(float t, IMUData imu,
                    float vx, float vy, float vz,
                    float alt);
};