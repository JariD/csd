#ifndef _OSC_H_
#include <iostream>

class Oscillator
{
public:
    //constructor and destructor
    Oscillator();
    Oscillator(float freq, float amp);
    ~Oscillator();

    // methods
    void setFreq(float freq);
    float getFreq();

protected:
    float freq;
    float amp;
};

#endif