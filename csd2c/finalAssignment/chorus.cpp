#include "chorus.h"
#include <iostream>
#include <ostream>

//code for final assignment
//code from github.com/timschippers
Chorus::Chorus(float milliseconds) : delayTime(milliseconds) {
  // TODO clock = main clock
  prepare(44100);
  setMaxDelayTime(30);
  setDelayTime(delayTime);
};
Chorus::~Chorus() {
  for (int channel = 0; channel < 2; channel++) {
    delete (buffer[channel]);
  }
};

void Chorus::prepare(int sampleRate) {
  this->sampleRate = sampleRate;
  std::cout << "preparing delay" << std::endl;
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel] = new CircularBuffer;
    lfos[channel].prepare(sampleRate);
    lfos[channel].setFrequency(0.5);
  }
}

void Chorus::applyEffect(const float &input, float &output, int channel) {
  // Generates an LFO with an inverse polarity at the Right channel if effect is stereo
  modSignal[channel] = lfos[channel].genNextSample() * (1 + (-2 * channel));
  modSignal[channel] *= modDepth;
  setDelayTime(delayTime + modSignal[channel]);
  output = buffer[channel]->readLinear();
  buffer[channel]->write(input);
};

void Chorus::setDelayTime(float milliseconds) {
  // TODO valuate stereoOffset to buffersize
  numDelaySamples = sampleRate * (milliseconds / 1000);
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel]->setDistanceReadHead(numDelaySamples);
  }
};

void Chorus::setMaxDelayTime(float milliseconds) {
  std::cout << "setting max delay time in " << milliseconds << " milliseconds"
            << std::endl;
  numMaxDelaySamples = sampleRate * (milliseconds / 1000);
  for (int channel = 0; channel < 2; channel++) {
    buffer[channel]->setSize(numMaxDelaySamples);
  }
};

void Chorus::setModRate(double freq) {
  // for (int channel = 0; channel < channels; channel++) {
  //  lfos[channel].setFrequency(freq);
  //}
  lfos[0].setFrequency(freq);
  lfos[1].setFrequency(1.5 * freq);
}

void Chorus::setModDepth(double modDepth) { this->modDepth = modDepth; }
