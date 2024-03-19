#pragma once
#include <math.h>
// bitcrusher calculations from pirkle

class Bitcrusher : public Effect {
public:
    Bitcrusher() {
    }

    ~Bitcrusher(){}

    void prepare(float samplerate) override {}

    void setBitDepth(float bitDepth) {
        this->bitDepth = 2.0 / (pow(2.0, bitDepth) -1.0);
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