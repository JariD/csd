#include <Bela.h>
#include <cmath>
#include <algorithm>
#include "bitcrusher.h"
#include "effect.h"
#include <libraries/Scope/Scope.h>

// Code includes code from bela.io for audio rendering

unsigned int gAudioChannelNum; // number of audio channels to iterate over
float gSensor, gPhase, gInverseSampleRate, processedSample;
int gAudioFramesPerAnalogFrame = 0;

// init scope and bitcrusher
Scope scope;
Bitcrusher bitCrusher;

bool setup(BelaContext *context, void *userData)
{
    // If the amout of audio input and output channels is not the same
    // we will use the minimum between input and output
    gAudioChannelNum = std::min(context->audioInChannels, context->audioOutChannels);

    //setup for scope with 2 channel
    scope.setup(2, context->audioSampleRate);

    // Check that we have the same number of inputs and outputs.
    if(context->audioInChannels != context->audioOutChannels){
        printf("Different number of audio outputs and inputs available. Using %d channels.\n", gAudioChannelNum);
    }

    if(context->analogSampleRate > context->audioSampleRate)
    {
        fprintf(stderr, "Error: for this project the sampling rate of the analog inputs has to be <= the audio sample rate\n");
        return false;
    }

    if(context->audioFrames)
        gAudioFramesPerAnalogFrame = context->audioFrames / context->analogFrames;
    gInverseSampleRate = 1.0 / context->audioSampleRate;
    gPhase = 0.0;

    return true;
}

void render(BelaContext *context, void *userData)
{
    // loops for audio
    for(unsigned int n = 0; n < context->audioFrames; n++) {

        if(gAudioFramesPerAnalogFrame && !(n % gAudioFramesPerAnalogFrame)) {
            // analogIn0
            gSensor = analogRead(context, n/gAudioFramesPerAnalogFrame, 0);

        }


        for(unsigned int channel = 0; channel < gAudioChannelNum; channel++) {
            // Read the audio input and half the amplitude
            float input = audioRead(context, n, channel) * 0.5f;
            //sample proccess
            processedSample = bitCrusher.processFrame(input);

            // Write to audio output the audio input
            audioWrite(context, n, channel, (processedSample));
        }


        //FIXME: SCOPE SQUAREWAVE
        scope.log(gSensor, processedSample);
    }

}

void cleanup(BelaContext *context, void *userData)
{

}
