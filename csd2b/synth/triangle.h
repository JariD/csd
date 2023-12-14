#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "oscillator.h"

class Triangle : public Oscillator {
public:
    Triangle(float frequency= 220, float sampleRate = 44100);
    ~Triangle();

    //override calculate from base class
    void calculate();
};


#endif
