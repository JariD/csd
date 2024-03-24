#pragma once
#include <math.h>
#include <iostream>
#include "effect.h"

// bitcrusher calculations from pirkle

class Bitcrusher : public Effect {
public:
    Bitcrusher() {
    }

    ~Bitcrusher(){}

    void prepare(float samplerate) override {

    }

    void setBitDepth(float bitDepth) {
        this->bitDepth = 8.0 / (pow(8.0, bitDepth) -1.0);
        std::cout << this->bitDepth << std::endl;
    }

    float applyEffect(float input) override {
//        std::cout << "Input: " << input << std::endl;
        return bitDepth * static_cast<int>(input/ bitDepth);
//        std::cout << "Output: " << output << std::endl;
//        return output;
    }

private:
    float bitDepth;
};