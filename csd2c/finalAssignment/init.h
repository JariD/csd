#pragma once
#include <Bela.h>
#include <cmath>
#include <algorithm>

class Init {
public:
    //initiation for the render.cpp
    unsigned int gAudioChannelNum;
    float gSensor, sensorCrush, sensorTrem, sensorWS, gPhase, gInverseSampleRate, input, processedSample;
    int gAudioFramesPerAnalogFrame = 0;

private:
};

