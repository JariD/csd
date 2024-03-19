//
// Created by Dean on 02/12/2023.
//

#include "audiocomponent.h"
#include <iostream>
#include "oscillator.h"
#include "Filters.h"
#include "deltasequence.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback(double Fs) : AudioCallback(Fs) {
        filter.setCoefficient(0.0);
    }

    ~CustomCallback() override {
        delete saw;
        saw = nullptr;
    }

    void prepare(int sampleRate, int blockSize) override {
        saw = new Saw();
        saw->prepare(sampleRate);
        saw->setFrequency(110);
    }

    void process(AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;


        for (auto sample = 0u; sample < numFrames; ++sample) {
            auto output = saw->output() * 0.2;
            for(auto channel = 0u; channel < numOutputChannels; ++channel) {
                outputChannels[channel][sample] = filter.process(output);

            }
        }
    }


    Saw *saw;
    SimpleLadder filter;
};

#define Delta_Sequence 1

int main() {


#if Delta_Sequence
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource(48000);
    DeltaSequence::run(audioSource.filter);
#else
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource(48000);
    JUCEModule juceModule(audioSource);
    juceModule.init(2, 2);


    std::cout << "Press q Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }
#endif
    return 0;
}
