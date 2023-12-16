#include "oscillator.h"
#include "math.h"

//parts of the code are from csd github

Oscillator::Oscillator(float frequency, float sampleRate) : frequency(frequency),
    amplitude(1.0), phase(0), sample(0), sampleRate(sampleRate)
{
    std::cout << "Oscillator - constructor\n";
}


Oscillator::~Oscillator() {
    std::cout << "Oscillator - destructor\n";
}

void Oscillator::setSampleRate(float sampleRate) {
    this->sampleRate = sampleRate;
}

float Oscillator::getSample() {
    return sample;
}


//getters and setters
void Oscillator::setFrequency(float frequency)
{
    // TODO
    // add check to see if parameter is valid
    this->frequency = frequency;
}

float Oscillator::getFrequency()
{
    return frequency;
}

void Oscillator::tick()
{
    // increment the phase to allow calculation of next sample
    phase += frequency / sampleRate;
    // wrap the phase to interval [0, 1]
    if(phase > 1) phase -= 1.0;
    // calculate sample for the incremented phase
    calculate();
}