#pragma once
#include <cmath>
#include <iostream>
#include "effect.h"

//waveshaper calculations based on pirkle

class Waveshaper : public Effect {
public:
    Waveshaper() {}
    ~Waveshaper() {}
    void prepare(int samplerate) override {
    }

    void setDrive(float drive) {
        this->drive = drive;
    }

    // applying the effect on the input signal
    void applyEffect(const float &input, float &output, int channel) override {
        // (1/arctan(drive))*arctan(drive*x); drive around 8 is nice
        output = (1.0f / std::atan(drive)) * std::atan(drive * input);
    }

private:
    float drive;
    //initiation of waveshaper
    Waveshaper waverShaper;
};