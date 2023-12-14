#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float sampleRate) : Oscillator(frequency, sampleRate)
{
    std::cout << "• Saw::Saw - constructor\n";
}

Saw::~Saw()
{
    std::cout << "• Saw::~Saw\n";
}

void Saw::calculate() {
    sample = (2.0 * phase) - 1.0;
}