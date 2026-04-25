#include "TVC.h"
#include <Servo.h>

Servo servoX;
Servo servoY;

void TVC::init() {
    servoX.attach(18);
    servoY.attach(19);
}

void TVC::stabilize(IMUData imu) {
    float errorX = 0 - imu.ax;
    float errorY = 0 - imu.ay;

    int x = constrain(90 + errorX, 60, 120);
    int y = constrain(90 + errorY, 60, 120);

    servoX.write(x);
    servoY.write(y);
}