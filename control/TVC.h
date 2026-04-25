#pragma once
#include "../sensors/IMU.h"

class TVC {
public:
    static void init();
    static void stabilize(IMUData imu);
};