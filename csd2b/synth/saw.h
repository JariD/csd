#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw : public Oscillator {
public:
    Saw(float frequency= 0, float sampleRate = 44100);
    ~Saw();

    //override calculate from base class
    void calculate();
};


#endif
