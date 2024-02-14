#include "tremolo.h"

Tremolo::Tremolo(float freq, float modDepth, float dryWet)
{
    setModFreq(freq);
   this->modDepth = modDepth;
}

Tremolo::~Tremolo() {}

void Tremolo::prepare(float samplerate) {
  // NOTE: example, keeping things 'simple', hence no validation
  sine.prepare(samplerate);
}

float Tremolo::applyEffect(float sample) {
  // transform sine in range [-1, 1] to range [0, 1]
  float modSignal = (sine.genNextSample() + 1) * 0.5;
  // apply modDept
  modSignal *= modDepth;
  modSignal += 1.0 - modDepth;
  // apply modulation signal to input
  return sample * modSignal;
}

void Tremolo::setModFreq(float freq) {
  // NOTE: example, keeping things 'simple', hence no validation
  sine.setFrequency(freq);
}

