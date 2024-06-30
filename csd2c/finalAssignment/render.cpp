#include <Bela.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "init.h"
#include "bitcrusher.h"
#include "effect.h"
#include "tremolo.h"
#include "waveshaper.h"
#include "init.h"

//Render, main on BELA

//setup for the audio
bool setup(BelaContext *context, void *userData)
{
    // If input/output not same: use minimum between in/out
	gAudioChannelNum = std::min(context->audioInChannels, context->audioOutChannels);

	//setup for scope with 2 channel
	scope.setup(3, context->audioSampleRate);

    //set base param for effects
	bitCrusher.setDryWet(0.5f);
	tremolo.setDryWet(0.3f);

	// Checker for same number of inputs and outputs.
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

//void loop on BELA
void render(BelaContext *context, void *userData)
{
	// loops for audio
	for(unsigned int n = 0; n < context->audioFrames; n++) {

		if(gAudioFramesPerAnalogFrame && !(n % gAudioFramesPerAnalogFrame)) {
			// analogRead and mapping for sensors
			gSensor = analogRead(context, n/gAudioFramesPerAnalogFrame, 0);
			sensorCrush = map(gSensor, 0.1, 0.6, 16, 2);
			sensorTrem = map(gSensor, 0.1, 0.6, 0.0, 0.8);
			sensorWS = map(gSensor, 0.1, 0.6, 0.0, 8.0);
			
			//sensor controlling the effect setters
			bitCrusher.setBitDepth(sensorCrush);
			tremolo.setModDepth(sensorTrem);
			waverShaper.setDrive(sensorWS);
		}


		for(unsigned int channel = 0; channel < gAudioChannelNum; channel++) {
			// Read the audio input and half the amplitude and map for effect ranges
			float input = audioRead(context, n, channel) * 0.5f;
            //Efect processing and writing to audio channel
			bitCrusher.processSignal(input, processedSample, channel);
			tremolo.processSignal(processedSample, processedSample, channel);
			waverShaper.processSignal(processedSample, processedSample, channel);
			// Write the processedSignals to the audio output
			audioWrite(context, n, channel, (processedSample));
		}
		

	}

}

void cleanup(BelaContext *context, void *userData)
{
}
