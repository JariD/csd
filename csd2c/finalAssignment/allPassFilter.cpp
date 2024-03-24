#include "allPassFilter.h"
#include <iostream>
#include <ostream>

//code from github.com/timschippers


AllPassFilter::AllPassFilter(float milliseconds, float feedback)
    : feedbackAmount(feedback) {
  samplerate = 44100;
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel] = new CircularBuffer;
  }
  setDelayTime(milliseconds);
};
AllPassFilter::~AllPassFilter(){
  for (int channel = 0; channel < 2; channel++) {
   delete(buffer[channel]); 
  }
};

void AllPassFilter::applyFilter(const float &input, float &output,
                                int channel) {
  float sample = buffer[channel]->readLinear();
  output = -feedbackAmount * input + sample + feedbackAmount * sample;
  buffer[channel]->write(input + sample * feedbackAmount);
};
void AllPassFilter::setFeedback(float feedback) { feedbackAmount = feedback; };

void AllPassFilter::setDelayTime(float milliseconds) {
  numSamplesDelay = samplerate * (milliseconds / 1000);
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel]->setSize(numSamplesDelay + 1);
    buffer[channel]->setDistanceReadHead(numSamplesDelay);
  }
};
