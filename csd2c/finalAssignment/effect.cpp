#include "effect.h"

//code for final assignment
//code from github.com/timschippers

Effect::Effect() : channels(2){ setDryWet(1.0f); };

Effect::~Effect() {}

void Effect::processSignal(const float &input, float &output, int channel) {
  applyEffect(input, output, channel);
  output = input * dryVolume + output * wetVolume;
};

void Effect::setDryWet(float dryWet) {
  dryVolume = 1 - dryWet;
  wetVolume = dryWet;
};
