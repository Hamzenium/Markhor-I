#include "FlightController.h"
#include "../sensors/IMU.h"
#include "../sensors/Barometer.h"
#include "../storage/SDLogger.h"
#include "../math/Integrator.h"

static float timeSec = 0;

static Integrator vx;
static Integrator vy;
static Integrator vz;

void FlightContoller::init() {
    IMU::init();
    Barometer::init();
    SDLogger::init();
}

void FlightCore::update() {

    float dt = 0.02;
    timeSec += dt;

    IMUData imu = IMU::read();
    float alt = Barometer::read();

    // gravity compensation (basic simulation model)
    float ax = imu.ax;
    float ay = imu.ay;
    float az = imu.az - 9.81;

    // velocity integration
    vx.update(ax, dt);
    vy.update(ay, dt);
    vz.update(az, dt);

    SDLogger::log(
        timeSec,
        imu,
        vx.value(),
        vy.value(),
        vz.value(),
        alt
    );
}