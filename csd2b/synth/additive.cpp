#include <iostream>
#include "additive.h"
#include "oscillator.h"

//TODO ADDITIVE FUNCTIONS

AdditiveSynth::AdditiveSynth() : Synth(44100.0f)
{
    //TODO for loop for adding oscillator pointers
}

AdditiveSynth::~AdditiveSynth()
{
    //TODO for loop for deleting oscillator pointers
}

float AdditiveSynth::process(float input)
{
    //TODO process for the audio signalpath
    //>add up or multiply<? the number oscillator waveforms
    //devide the amplitude by numOscillators
    //for now output = 0.0 to skip warning in building
    float output = 0.0f;
    return output;
}

void AdditiveSynth::addOscillator()
{
    //TODO add oscillator function
    //for now maybe just add 2 saws and a square
    //if oscillatorpointers are empty, it fills the pointers
    if (numOsc < maxOsc) {
        if (!osc1) {
            osc1 = new Saw(frequency,sampleRate);
            numOsc++;
        }
        if (!osc2) {
            //oscillator 2 is octave below TODO check if works
            osc2 = new Saw((frequency/2),sampleRate);
            numOsc++;
        }
        if (!osc3) {
            osc3 = new Square((frequency*2),sampleRate);
            numOsc++;
        }
    } else {
        std::cout << "All Oscillators Created." << std::endl;
    }
}
