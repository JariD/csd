#ifndef _FM_H_
#define _FM_H_
#include <iostream>
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"

//TODO add protected
class FM : public Synth
{
public:
    FM();
    FM(Oscillator* carrier, Oscillator* modulator, float sampleRate);
    ~FM();
    void setModulationDepth(float depth);
    float process(float input);
    //default constructor
private:
    Oscillator* carrierOscillator;
    Oscillator* modulatorOscillator;
    float modulationDepth;
//    float carrierFrequency;
};

#endif