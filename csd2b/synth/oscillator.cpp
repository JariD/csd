#include <iostream>
#include <oscillator.h>

Oscillator::Oscillator() : Oscillator(220, 0)
{
    std::cout << "Inside Oscillator constructor ()\n"
}

Oscillator::Oscillator(float frequency, float amp)
    : freq(frequency), amp(amp)
{
    std::cout << "Inside Oscillator constructor (frequency)\n";
}

Oscillator::~Oscillator()
{
    std::cout << "Inside Oscillator destructor\n";
}

void Oscillator::setFreq(float freq)
{
    if freq > 0 && freq < 22050) {
        this->freq = fre;
    } else {
    std::cout << "The frequency value is incorrect"
    << "please present a value in the interval [0, 22049]\n";
    }
}

float Oscillator::getFreq()
{
    return freq;
}