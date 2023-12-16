#include "fm.h"
#include <iostream>
#include "callback.h"

FM::FM(Oscillator* carrier, Oscillator* modulator, float sampleRate)
        : Synth(sampleRate), carrierOscillator(carrier), modulatorOscillator(modulator), modulationDepth(1.0f) {
    if (this->carrierOscillator) this->carrierOscillator->setSampleRate(sampleRate);
    if (this->modulatorOscillator) this->modulatorOscillator->setSampleRate(sampleRate);
}

FM::~FM()
{
    std::cout << "FM deconstructor" << std::endl;
}

void FM::setModulationDepth(float depth)
{
    modulationDepth = depth;
}

float FM::process(float input)
{
    float modulatedFrequency = input + (modulationDepth * modulatorOscillator->getSample());
    carrierOscillator->setFrequency(modulatedFrequency);
    modulatorOscillator->tick();

    return carrierOscillator->getSample();
}

// NEW INIT OF FM
FM::FM() : Synth(44100), carrierOscillator(nullptr), modulatorOscillator(nullptr), modulationDepth(1.0f)
{
}