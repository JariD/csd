#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>

class Synth
{
public:
    Synth(float sampleRate);
    void setSampleRate(float sampleRate);
    ~Synth();
    void setGain(float gain);

protected:
    float gain;
    float sampleRate;
//    float frequency;
};

#endif