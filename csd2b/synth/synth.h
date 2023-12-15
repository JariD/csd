#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>


//TODO fill in the class
class Synth
{
public:
    Synth(float sampleRate);
    ~Synth();
    void setGain(float gain);

protected:
    float gain;
    //frequentie hier?
    float sampleRate;
};

#endif