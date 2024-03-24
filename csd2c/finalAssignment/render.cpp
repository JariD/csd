#include <Bela.h>
#include <cmath>
#include <algorithm>
#include <libraries/Scope/Scope.h>
#include <iostream>
#include "bitcrusher.h"
#include "effect.h"
#include "tremolo.h"
#include "waveshaper.h"



unsigned int gAudioChannelNum; // number of audio channels to iterate over
float gSensor, sensorCrush, sensorTrem, sensorWS, gPhase, gInverseSampleRate, input, processedSample;
int gAudioFramesPerAnalogFrame = 0;

// init scope and bitcrusher
Scope scope;
Bitcrusher bitCrusher;
Tremolo tremolo;
Waveshaper waverShaper;




bool setup(BelaContext *context, void *userData)
{
	// If the amout of audio input and output channels is not the same
	// we will use the minimum between input and output
	gAudioChannelNum = std::min(context->audioInChannels, context->audioOutChannels);
	
	//setup for scope with 2 channel
	scope.setup(3, context->audioSampleRate);
	
	bitCrusher.setDryWet(0.5f);
	tremolo.setDryWet(0.3f);

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
			// analogRead and mapping for sensors
			gSensor = analogRead(context, n/gAudioFramesPerAnalogFrame, 0);
			sensorCrush = map(gSensor, 0.1, 0.6, 16, 2);
			sensorTrem = map(gSensor, 0.1, 0.6, 0.0, 0.8);
			sensorWS = map(gSensor, 0.1, 0.6, 0.0, 8.0);
			
			//setters for sensors
			bitCrusher.setBitDepth(sensorCrush);
			tremolo.setModDepth(sensorTrem);
			waverShaper.setDrive(sensorWS);
			
		}
		

		for(unsigned int channel = 0; channel < gAudioChannelNum; channel++) {
			// Read the audio input and half the amplitude and map for effect ranges
			float input = audioRead(context, n, channel) * 0.5f;
			bitCrusher.processSignal(input, processedSample, channel);
			tremolo.processSignal(processedSample, processedSample, channel);
			waverShaper.processSignal(processedSample, processedSample, channel);
			
			// Write to audio output the audio input
			audioWrite(context, n, channel, (processedSample));
		
			//scope 
			scope.log(gSensor, sensorTrem, input);
		}
		

	}

}

// release mem alloc
void cleanup(BelaContext *context, void *userData)
{

}
