# Markhor-I — ESP32 Flight Computer

A modular ESP32-based flight data logger designed for simulation, analysis, and trajectory reconstruction.

Reads IMU + barometer at 50 Hz, estimates velocity via numerical integration, and logs everything to SD card as CSV — ready for Python or MATLAB post-processing.

---

## Features

| Feature | Detail |
|---|---|
| IMU | MPU6050 acceleration data via I2C |
| Barometer | BMP280 altitude estimation |
| SD Logging | CSV output to micro SD card |
| Velocity Estimation | Euler numerical integration |
| Modular Architecture | Aerospace-style module separation |
| Simulation-Ready | Python / MATLAB compatible output |

---

## Important Note

This is a data acquisition and simulation system — not a flight controller, autopilot, or safety-certified avionics system. Intended for educational and experimental use only.

---

## System Architecture

```
main.ino                        <- entry point
└── FlightCore
    ├── IMU           sensors/IMU.h/.cpp
    ├── Barometer     sensors/Barometer.h/.cpp
    ├── SDLogger      storage/SDLogger.h/.cpp
    └── Integrator    math/Integrator.h
```

---

## Hardware Requirements

- ESP32 Dev Board
- MPU6050 (IMU)
- BMP280 (barometer)
- Micro SD card module (SPI)

---

## Pin Configuration

### I2C — Sensors

| Signal | GPIO |
|--------|------|
| SDA    | 21   |
| SCL    | 22   |

### SPI — SD Card

| Signal | GPIO |
|--------|------|
| CS     | 5    |
| MOSI   | 23   |
| MISO   | 19   |
| SCK    | 18   |

---

## Project Structure

```
Markhor-I/
|
├── main.ino
|
├── core/
|   ├── FlightCore.h
|   └── FlightCore.cpp
|
├── sensors/
|   ├── IMU.h
|   ├── IMU.cpp
|   ├── Barometer.h
|   └── Barometer.cpp
|
├── storage/
|   ├── SDLogger.h
|   └── SDLogger.cpp
|
└── math/
    └── Integrator.h
```

---

## CSV Output Format

Data is logged to `/flight.csv` on the SD card.

```
t,ax,ay,az,vx,vy,vz,alt
0.02,0.12,-0.03,9.70,0.002,-0.001,0.000,1.32
0.04,0.10,-0.05,9.68,0.004,-0.002,0.001,1.35
```

| Column | Description | Unit |
|--------|-------------|------|
| t | Time elapsed | s |
| ax / ay / az | Raw acceleration (XYZ) | m/s2 |
| vx / vy / vz | Integrated velocity (XYZ) | m/s |
| alt | Barometric altitude | m |

---

## Physics Model

Velocity is computed using Euler numerical integration:

```
v = v + a * dt

dt = 0.02 s  (50 Hz loop)
az_corrected = az - 9.81  (gravity compensation)
```

---

## Dependencies

Install via Arduino Library Manager:

| Library | Purpose |
|---------|---------|
| Adafruit_MPU6050 | IMU sensor driver |
| Adafruit_BMP280 | Barometer driver |
| Adafruit_Unified_Sensor | Sensor abstraction layer |
| SD | SD card read/write |
| SPI | SPI communication |
| Wire | I2C communication |

---

## Setup Instructions

1. Open Arduino IDE and install the ESP32 board package via Board Manager
2. Install all libraries listed above via Library Manager
3. Open `main.ino`, select your ESP32 board and correct COM port
4. Insert a FAT32-formatted micro SD card
5. Upload the sketch
6. Open Serial Monitor at `115200` baud to verify sensor readings
7. Pull `/flight.csv` from the SD card to plot in Python or MATLAB

---

## Future Improvements

- [ ] Kalman filter for better state estimation
- [ ] GPS module integration for position tracking
- [ ] Wind and drag simulation model
- [ ] 3D trajectory reconstruction in Python
- [ ] Real-time WiFi telemetry dashboard
- [ ] Flight state machine: IDLE > BOOST > COAST > DESCENT

---

## License

Educational use only.
