#pragma once

class Integrator {
    float v = 0;

public:
    void update(float a, float dt) {
        v += a * dt;
    }

    float value() {
        return v;
    }
};