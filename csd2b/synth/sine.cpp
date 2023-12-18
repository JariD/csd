#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float sampleRate) : Oscillator(frequency, sampleRate)
{
//  std::cout << "• Sine::Sine - constructor\n";
}

Sine::~Sine()
{
//  std::cout << "• Sine::~Sine\n";
}

void Sine::calculate() {
    sample = sin(M_PI * 2 * phase) * amplitude;
}
