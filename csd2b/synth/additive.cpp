#include <iostream>
#include "additive.h"
#include "oscillator.h"

//TODO ADDITIVE FUNCTIONS

AdditiveSynth::additiveSynth()
{
    //TODO for loop for adding oscillator pointers
}

AdditiveSynth::~additiveSynth()
{
    //TODO for loop for deleting oscillator pointers
}

float AdditiveSynth::process(float input)
{
    //TODO process for the audio signalpath
    //>add up or multiply<? the number oscillator waveforms
    //devide the amplitude by numOscillators
}

void AdditiveSynth::addOscillator(Oscillator*, osc);
{
    //TODO add oscillator function
    //for now maybe just add 2 saws and a square
}