#include "callback.h"
#include "melody.h"
#include "synth.h"
#include "sine.h"
#include "oscillator.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"
#include "fm.h"

//parts of the code are from csd github
#define writeToFileSingleOsc 0
#define fmSynth 0

#if writeToFileSingleOsc

void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] = sineCarrier.getSample();
    sineCarrier.tick();
  }
}


#elif fmSynth

CustomCallback::CustomCallback(){
    //static om bus error te fixen
    static Sine sineCarrier(440, 44100);
    std::cout << "Sine Carrier" << std::endl;
    static Square squareModulator(100, 44100);
    std::cout << "square Modulator" << std::endl;
    carrierOscillator = &sineCarrier;
    modulatorOscillator = &squareModulator;
    //koppelen van pointers aan sinus
    fmSynth = FM(carrierOscillator, modulatorOscillator, 44100);
}

double mtof(float mPitch)
{
    return 440.0 * pow(2.0, (mPitch - 69.0f)/12.0f);
} // mtof()

//ciska's code for melody
void updatePitch(Melody& melody, Oscillator* carrierOscillator) {
    float note = melody.getNote();
    double freq = mtof(note);
    std::cout << "next note: " << note << ", has frequency " << freq << std::endl;
    carrierOscillator->setFrequency(freq);
}

void CustomCallback::prepare (int rate) {
    fmSynth.setSampleRate(rate);
    fmSynth.setModulationDepth(1.0f);
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    for (int channel = 0; channel < numOutputChannels; ++channel) {
        for (int sample = 0; sample < numFrames; ++sample) {
            float currentNote = carrierOscillator->getFrequency();
            std::cout << currentNote << std::endl;
            float fmOutput = fmSynth.process(currentNote);
//            std::cout << fmOutput << std::endl;
            outputChannels[channel][sample] = fmOutput * amplitude;

/* After every sample, check if we need to advance to the next note
 * This is a bit awkward in this scheme of buffers per channel
 *  In a multichannel setting we should update pitches independently per channel!
 */
            if(frameIndex >= noteDelayFactor * sampleRate) {
// reset frameIndex
//                std::cout << "notedelay" << noteDelayFactor << std::endl;
                frameIndex = 0;
                updatePitch(melody, carrierOscillator);
            }
            else {
// increment frameindex
//                std::cout << "framIndex" << frameIndex << std::endl;
                frameIndex++;
            }
        } // for sample
    } // for channel
}

#else
//
double mtof(float mPitch)
{
    return 440.0 * pow(2.0, (mPitch - 69.0f)/12.0f);
} // mtof()

void updatePitch(Melody& melody, Triangle& triangle) {
    float note = melody.getNote();
    double freq = mtof(note);
    std::cout << "next note: " << note << ", has frequency " << freq << std::endl;
    triangle.setFrequency(freq);
} // updatePitch()

void CustomCallback::prepare (int rate) {
    this->sampleRate=rate;
    updatePitch(melody,triangle);
} // new prepare()

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    for (int channel = 0; channel < numOutputChannels; ++channel) {
        for (int sample = 0; sample < numFrames; ++sample) {
            outputChannels[channel][sample] = triangle.getSample() * amplitude;
            triangle.tick(); // rather mixed up functionality

/* After every sample, check if we need to advance to the next note
 * This is a bit awkward in this scheme of buffers per channel
 *  In a multichannel setting we should update pitches independently per channel!
 */
            if(frameIndex >= noteDelayFactor * sampleRate) {
// reset frameIndex
                frameIndex = 0;
                updatePitch(melody,triangle);
            }
            else {
// increment frameindex
                frameIndex++;
            }
        } // for sample
    } // for channel
}

#endif
