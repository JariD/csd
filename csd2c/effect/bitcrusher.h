#pragma once
#include <math.h>
// bitcrusher calculations from pirkle

class Bitcrusher : Effect {
public:
    Bitcrusher();
    ~Bitcrusher();

    void prepare(float samplerate) override;
    void setBitDepth(float bitDepth) {
        this->bithDepth = bitDepth;
        bitDepth = 2.0 / (pow(2.0, bitDepth) -1.0);
        return bitDepth;
    }

private:
    float bitDepth;

    float applyEffect(float sample) override() {
        setbitDepth(float bitDepth);
        output = bitDepth*(int(input / bitDepth));
    }
};