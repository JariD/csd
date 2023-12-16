#include "fm.h"
#include <iostream>
#include "callback.h"

FM::FM(Oscillator* carrier, Oscillator* modulator, float sampleRate)
        : Synth(sampleRate), carrier(carrier), modulator(modulator), modulationDepth(1.0f) {
    if (this->carrier) this->carrier->setSampleRate(sampleRate);
    if (this->modulator) this->modulator->setSampleRate(sampleRate);
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
    float modulatedFrequency = input + (modulationDepth * modulator->getSample());
    carrier->setFrequency(modulatedFrequency);

    modulator->tick();
    return carrier->getSample();
}

// NEW INIT OF FM
FM::FM() : Synth(44100), (carrierOscillator), (modulatorOscillator), modulationDepth(500)
{
}