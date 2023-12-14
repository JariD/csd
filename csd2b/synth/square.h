#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "oscillator.h"

class Square : public Oscillator{
public:
    Square(float frequency= 0, float sampleRate = 44100);
    ~Square();
protected:
    void calculate();
};

#endif
