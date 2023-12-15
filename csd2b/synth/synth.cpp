#include "synth.h"
#include <iostream>

//TODO make synth cpp
//Pointer to oscillator to point to oscillatorclass?
//need oscillatortype as well

Synth::Synth(float sampleRate)
{
    std::cout << "Synth constructor" << std::endl;
}

Synth::~Synth()
{
    std::cout << "Synth Destructor" << std:endl;
}

void Synth::setGain(float gain)
{
    //gain pointer here
}
//SET SAMPLERATE
//SET AMPLITUDE

/* THIS PART IN ADDITIVE SYNTH?
void addOscillator()
{
    std::cout << "Oscillator added\n";
}
void removeOscillator()
{
    std::cout << "Oscillator removed\n";
}
*/

