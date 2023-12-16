#include "callback.h"
#include "melody.h"
#include "sine.h"
#include "oscillator.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"

//parts of the code are from csd github
#define writeToFileSingleOsc 0

#if writeToFileSingleOsc
void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] = saw.getSample();
    saw.tick();
  }
}

void CustomCallback::prepare(int rate) {
    //sampleRate = (float) rate;
    saw.setSamplerate(sampleRate);
    std::cout << "\nsamplerate: " << sampleRate << "\n";
}

#else
double mtof(float mPitch)
{
    return 440.0 * pow(2.0, (mPitch - 69.0f)/12.0f);
} // mtof()

void updatePitch(Melody& melody, Saw& saw) {
    float note = melody.getNote();
    double freq = mtof(note);
    std::cout << "next note: " << note << ", has frequency " << freq << std::endl;
    saw.setFrequency(freq);
} // updatePitch()

void CustomCallback::prepare (int rate) {
    this->sampleRate=rate;
    updatePitch(melody,saw);
} // new prepare()

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    for (int channel = 0; channel < numOutputChannels; ++channel) {
        for (int sample = 0; sample < numFrames; ++sample) {
            outputChannels[channel][sample] = saw.getSample() * amplitude;
            saw.tick(); // rather mixed up functionality

/* After every sample, check if we need to advance to the next note
 * This is a bit awkward in this scheme of buffers per channel
 *  In a multichannel setting we should update pitches independently per channel!
 */
            if(frameIndex >= noteDelayFactor * sampleRate) {
// reset frameIndex
                frameIndex = 0;
                updatePitch(melody, saw);
            }
            else {
// increment frameindex
                frameIndex++;
            }
        } // for sample
    } // for channel
}
#endif
