#include "callback.h"
#include "melody.h"
#include "synth.h"
#include "sine.h"
#include "oscillator.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"
#include "fm.h"



// USER INPUT
UI console_ui;
std::string synthOptions[4] = {"FM", "Additive"};
int numSynthOptions = 2;

int synthSelection = console_ui.retrieveUserSelection(synthOptions,numSynthOptions);
bool selectedSynth = (synthSelection ==0);

// AUDIOCALLBACK
CustomCallback::CustomCallback(){
    //fm init
    static Sine sineCarrier(440, 44100);
//    std::cout << "Sine Carrier" << std::endl;
    static Square squareModulator(100, 44100);
//    std::cout << "square Modulator" << std::endl;
    //koppelen van pointers aan waveforms
    carrierOscillator = &sineCarrier;
    modulatorOscillator = &squareModulator;
    fmSynth = FM(carrierOscillator, modulatorOscillator, 44100);

    //additive init
    //I use the same sineCarrier so the melody updates on the sineCarrier
    static Sine melodySine(440, 44100);
//    std::cout << "Sine Carrier" << std::endl;
    melodyOscillator = &melodySine;
    additiveSynth.addOscillator();
}

double mtof(float mPitch)
{
    return 440.0 * pow(2.0, (mPitch - 69.0f)/12.0f);
} // mtof()

//ciska's code for melody
void updatePitchFM(Melody& melody, Oscillator* carrierOscillator) {
    float note = melody.getNote();
    double freq = mtof(note);
//    std::cout << "next note FM: " << note << ", has frequency " << freq << std::endl;
    carrierOscillator->setFrequency(freq);
}

void updatePitchAdditiveSynth(Melody& melody, Oscillator* melodyOscillator) {
    float note = melody.getNote();
    double freq = mtof(note);
//    std::cout << "next note Add: " << note << ", has frequency " << freq << std::endl;
    melodyOscillator->setFrequency(freq);
}

void CustomCallback::prepare (int rate) {
    fmSynth.setSampleRate(rate);
    fmSynth.setModulationDepth(1.0f);
    additiveSynth.setSampleRate(rate);
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    for (int channel = 0; channel < numOutputChannels; ++channel) {
        for (int sample = 0; sample < numFrames; ++sample) {
            if (selectedSynth) {
                float currentNote = carrierOscillator->getFrequency();
//                std::cout << currentNote << std::endl;
                float fmOutput = fmSynth.process(currentNote);
//            std::cout << fmOutput << std::endl;
                outputChannels[channel][sample] = fmOutput * amplitude;
            } else {
                float nowNote = melodyOscillator->getFrequency();
//            std::cout << currentNote << std::endl;
                float additiveOutput = additiveSynth.process(nowNote);
//            std::cout << additiveOutput << std::endl;
                outputChannels[channel][sample] = additiveOutput * amplitude;
            }

/* After every sample, check if we need to advance to the next note
 * This is a bit awkward in this scheme of buffers per channel
 *  In a multichannel setting we should update pitches independently per channel!
 */
            if(frameIndex >= noteDelayFactor * sampleRate) {
// reset frameIndex
//                std::cout << "notedelay" << noteDelayFactor << std::endl;
                frameIndex = 0;
                if (selectedSynth) {
                    updatePitchFM(melody, carrierOscillator);
                } else
                {
                    updatePitchAdditiveSynth(melody, melodyOscillator);
                }
            }
            else {
// increment frameindex
//                std::cout << "framIndex" << frameIndex << std::endl;
                frameIndex++;
            }
        } // for sample
    } // for channel
}
