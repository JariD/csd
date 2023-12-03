#ifndef _OSC_H_
#define _OSC_H_
#include <iostream>
#include <cmath>

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator(float frequency, float samplerate = 44100);
  ~Oscillator();
  void setSamplerate(float samplerate);
  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;
};

#endif
