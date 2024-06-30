#include "effect.h"

//code from github.com/timschippers
//co-written, implemented effect.cpp


Effect::Effect() : channels(2){ setDryWet(wetVolume); };

Effect::~Effect() {}

void Effect::processSignal(const float &input, float &output, int channel) {
  applyEffect(input, output, channel);
  output = input * dryVolume + output * wetVolume;
};

void Effect::setDryWet(float dryWet) {
  dryVolume = 1 - dryWet;
  wetVolume = dryWet;
};
