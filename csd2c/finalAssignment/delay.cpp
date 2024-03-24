#include "delay.h"
#include <iostream>
#include <ostream>

//code for final assignment
//code from github.com/timschippers
Delay::Delay(float milliseconds) {
  // TODO clock = main clock
  prepare(44100);
  setDryWet(0.5);
  setMaxDelayTime(4000);
  setDelayTime(milliseconds, 0.33);
  setFeedbackAmount(0.4f);
};
Delay::~Delay() {
  for (int channel = 0; channel < 2; channel++) {
    delete (buffer[channel]);
  }
};

void Delay::prepare(int sampleRate) {
  this->sampleRate = sampleRate;
  std::cout << "preparing delay" << std::endl;
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel] = new CircularBuffer;
  }
}

void Delay::applyEffect(const float &input, float &output, int channel) {
  output = feedbackAmount * buffer[channel]->read();
  buffer[channel]->write(input + output);
};

void Delay::setDelayTime(float milliseconds, float stereoOffset) {
  // TODO valuate stereoOffset to buffersize
  std::cout << "setting delay time in " << milliseconds << " milliseconds"
            << std::endl;
  numDelaySamples = sampleRate * (milliseconds / 1000);
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel]->setDistanceReadHead(numDelaySamples *
                                         (1 + (channel * stereoOffset)));
  }
};

void Delay::setMaxDelayTime(float milliseconds) {
  std::cout << "setting max delay time in " << milliseconds << " milliseconds"
            << std::endl;
  numMaxDelaySamples = sampleRate * (milliseconds / 1000);
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel]->setSize(numMaxDelaySamples);
  }
};

void Delay::setFeedbackAmount(float feedback) { feedbackAmount = feedback; };

float Delay::getDelayTime() { return numDelaySamples / sampleRate * 1000; };

float Delay::getFeedbackAmount() { return feedbackAmount; };
