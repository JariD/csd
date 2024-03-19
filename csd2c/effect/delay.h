#pragma once
#include "circbuffer.h"

class Delay : Effect {
public:

    Delay() {
        std::cout << "Delay constructor. \n";
    }

    ~Delay() {
        std::cout << "Delay Destructor.\n";
    }

    void prepare(float samplerate) {
        // buffer.initBuffer(size);
    }


    float applyEffect(float sample) override {
        // input vangen in circbuffer : buffer.writeBuffer(input);
        // return buffer.readBuffer();
        // read/writeHead incrementen
    }

    void setDelayTime() {
    }

    void setDryWet() {
    }

    void setFeedback() {
    }

private:
    int delayTime;
    float feedback;
    float dryWet;
    CircBuffer buffer;
};