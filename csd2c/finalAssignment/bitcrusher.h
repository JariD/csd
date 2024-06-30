#pragma once
#include <cmath>
#include <iostream>
#include "effect.h"

// bitcrusher based on calculations from pirkle

class Bitcrusher : public Effect {
public:
    Bitcrusher() {
    }

    ~Bitcrusher(){}

    void prepare(int samplerate) override {
    }

    //calculation for effect
    void setBitDepth(float input) {
        this->bitDepth = 2.0 / (pow(2.0, input) -1.0);
    }

    void applyEffect(const float &input, float &output, int channel) override {
        output = bitDepth * static_cast<int>(std::floor(static_cast<double>(input) / bitDepth));
    }

private:
    float bitDepth = 4.0f;
    //initiation of the bitcrusher
    Bitcrusher bitCrusher;
};