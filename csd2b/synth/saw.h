#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include <cmath>

class Saw
{
public:
    Saw(float frequency, float samplerate = 44100);
    ~Saw();
    void setSamplerate(float samplerate);
    float getSample();
    void tick();

    void setFrequency(float frequency);
    float getFrequency();

private:
    const float pi = acos (-1);
    float frequency;
    float amplitude;
    float phase;
    float sample;
    float samplerate;
};

#endif