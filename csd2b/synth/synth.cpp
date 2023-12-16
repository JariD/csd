#include "synth.h"
#include <iostream>

//TODO make synth cpp
//Pointer to oscillator to point to oscillatorclass?
//need oscillatortype as well

Synth::Synth(float sampleRate)
{
    std::cout << "Synth constructor" << std::endl;
    this->sampleRate = sampleRate;
}

Synth::~Synth()
{
    std::cout << "Synth Destructor" << std::endl;
}

void Synth::setSampleRate(float sampleRate)
{
    this->sampleRate = sampleRate;
    std::cout << "samplerate set to: " << sampleRate << std::endl;
}

void Synth::setGain(float gain)
{
    this->gain = gain;
}
