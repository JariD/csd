#include "callback.h"
#include "effect.h"
#include "tremolo.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    bitcrusher.setBitDepth(8.0f);
//    filter.setCoefficient(0.2);
}

void CustomCallback::process(AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    for (int i = 0u; i < numFrames; i++) {
        float sample = bitcrusher.processFrame(inputChannels[0][i]);
//        float sample =  inputChannels[0][i];
        outputChannels[0][i] = sample;


//        broeder = delay.processFrame(inputChannels[1][i]);
//        outputChannels[1][i] = broeder;
//          float sample = bitcrusher.processFrame(inputChannels[channel][i]);
//          outputChannels[channel][i] = 0;
    }
}



//void CustomCallback::process(AudioBuffer buffer) {
//    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
//        for (int i = 0u; i < numFrames; i++) {
//            sample = filter.process(saw.genNextSample());
//            for (int channel = 0u; channel < numOutputChannels; channel++) {
//                outputChannels[channel][i] = sample;
//        }
//    }
//}

//    // //Stereo implementation
//    for (int i = 0u; i < numFrames; i++) {
//        sample = delay2.processFrame(inputChannels[0][i]);
//        outputChannels[0][i] = sample;
//        broeder = delay.processFrame(inputChannels[0][i]);
//        outputChannels[1][i] = broeder;
////      sample = delay.processFrame(inputChannels[channel][i]);
////      outputChannels[channel][i] = 0;
//    }
//  }
//
