#pragma once

#include "circularBuffer.h"
#include "effect.h"
//code from github.com/timschippers

class Delay : public Effect {
public:
  Delay(float milliseconds);
  ~Delay();

  void applyEffect(const float &intput, float &output, int channel) override;
  void prepare(int sampleRate) override;

  // setters & getters
  void setDelayTime(float milliseconds, float stereoOffset);
  void setMaxDelayTime(float milliseconds);
  void setFeedbackAmount(float feedback);
  float getDelayTime();
  float getFeedbackAmount();

private:
  // TODO change to vector to have an modular amount of buffers
  CircularBuffer* buffer[2];
  int sampleRate;
  float numDelaySamples;
  float numMaxDelaySamples;
  float feedbackAmount;
};
