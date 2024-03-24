#pragma once
#include <cmath>
#include <iostream>
#include "effect.h"

// bitcrusher calculations from pirkle

class Bitcrusher : public Effect {
public:
    Bitcrusher() {
    }

    ~Bitcrusher(){}

    void prepare(int samplerate) override {
    }

    void setBitDepth(float input) {
        this->bitDepth = 2.0 / (pow(2.0, input) -1.0);
        // std::cout << this->bitDepth << std::endl;
    }

    void applyEffect(const float &input, float &output, int channel) override {
//        std::cout << "Input: " << input << std::endl;
        // output = bitDepth * static_cast<int>(input/ bitDepth);
        // output = bitDepth * std::floor(input/bitDepth);
        output = bitDepth * static_cast<int>(std::floor(static_cast<double>(input) / bitDepth));
//        std::cout << "Output: " << output << std::endl;
    }

private:
    float bitDepth = 4.0f;
};