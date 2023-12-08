#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency, samplerate)
{
    std::cout << "• Saw::Saw - constructor\n";
}


Saw::Saw() : Oscillator()
{
    std::cout << "• Saw::Saw\n";
}

Saw::~Saw()
{
    std::cout << "• Saw::~Saw\n";
}

void Saw::calculate() {
    sample = phase * 2 -1;
}