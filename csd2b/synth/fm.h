#ifndef _FM_H_
#define _FM_H_
#include <iostream>
#include "synth.h"

//TODO add protected
class FM : public Synth
{
public:
    FMSynth();
    ~FMSynth();
    freqModulation();
protected:
    Oscillator* carrier;
    Oscillator* modulator;
};

#endif