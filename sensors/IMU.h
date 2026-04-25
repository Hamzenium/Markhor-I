#pragma once

struct IMUData {
    float ax, ay, az;
};

class IMU {
public:
    static void init();
    static IMUData read();
};