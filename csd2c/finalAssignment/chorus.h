#pragma once

#include "effect.h"
#include "circularBuffer.h"
#include <triangle.h>

//code for final assignment
//code from github.com/timschippers
class Chorus : public Effect {
public:
  Chorus(float milliseconds);
  ~Chorus();

  void applyEffect(const float &intput, float &output, int channel) override;
  void prepare(int sampleRate) override;

  // setters
  void setDelayTime(float milliseconds);
  void setMaxDelayTime(float milliseconds);
  void setFeedbackAmount(float feedback);
  void setModRate(double freq);
  void setModDepth(double modDepth);

private:
  // TODO change to vector to have an modular amount of buffers
  CircularBuffer *buffer[2];
  // TODO more waveforms
  Triangle lfos[2];
  int sampleRate;
  double delayTime;
  //TODO duplicate code (multiple layers inheritence?)
  float numDelaySamples;
  float numMaxDelaySamples;
  double modDepth = 9;
  double modRate;
  double modSignal[2];
};
