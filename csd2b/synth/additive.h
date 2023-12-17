#ifndef _ADDITIVE_H_
#define _ADDITIVE_H_
#include <iostream>
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"

//TODO BUILD ADDITIVE CLASS

class AdditiveSynth : public Synth
{
public:
    AdditiveSynth();
    ~AdditiveSynth();
    //function to add an oscillator to an oscillatorpointer
    void addOscillator();
    float process(float input);
    void setOscillatorFrequency(float frequency);
private:
    int maxOsc = 3;
    Oscillator* osc1;
    Oscillator* osc2;
    Oscillator* osc3;
    Saw sawOsc1;
    Saw sawOsc2;
    Square squareOsc;

protected:
    //num Oscillators for destructor
    float numOsc = 0.0f;




};

#endif