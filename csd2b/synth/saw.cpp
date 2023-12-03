#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float samplerate) : frequency(frequency),
amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
    std::cout << "Saw - constructor\n";
}

Saw::~Saw() {
    std::cout << "Saw - destructor\n";
}

void Saw::setSamplerate(float samplerate) {
    this->samplerate =samplerate;
}

float Saw::getSample() {
    return sample;
}

