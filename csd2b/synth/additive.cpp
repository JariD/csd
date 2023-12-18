#include <iostream>
#include "additive.h"
#include "oscillator.h"

//TODO Clean up code

AdditiveSynth::AdditiveSynth() : Synth(44100.0f) ,osc1(nullptr), osc2(nullptr), osc3(nullptr)
{
}

AdditiveSynth::~AdditiveSynth()
{
}

float AdditiveSynth::process(float input)
{
    // osc2 octave below and osc3 octave up
    float output = 0.0f;
    if (osc1) {
        osc1->setFrequency(input);
        output += osc1->getSample();
        osc1->tick();
    }
    if (osc2) {
        osc2->setFrequency(input / 2.0f);
        output += osc2->getSample();
        osc2->tick();
    }
    if (osc3) {
        osc3->setFrequency(input * 2.0f);
        output += osc3->getSample();
        osc3->tick();
    }
    //devide the amplitudy by numOscillators
    output /= numOsc;
//    std::cout << "numOsc output: " << output << std::endl;

    return output;
}

void AdditiveSynth::addOscillator()
{
    //for now just add 2 saws and a square
    //if oscillatorpointers are empty, it fills the pointers
    if (numOsc < maxOsc) {
        if (!osc1) {
            osc1 = &sawOsc1;
            numOsc++;
        }
        if (!osc2) {
            osc2 = &triangleOsc;
            numOsc++;
        }
        if (!osc3) {
            osc3 = &squareOsc;
            numOsc++;
        }
    } else {
        std::cout << "All Oscillators Created." << std::endl;
    }
}
