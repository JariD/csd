#pragma once

#include "effect.h"
#include <iostream>
#include "sine.h"

class Tremolo : public Effect {
public:
  Tremolo();
  ~Tremolo();

  // setters and getters
  void setModRate(double freq);
  void setModDepth(double modDepth);

protected:
  void applyEffect(const float &input, float &output, int channel) override;
  void prepare(int sampleRate) override;

private:
  double modDepth;
  double modRate;
  double modSignal;

  // TODO make it so it has different waves
  Sine sines[2];
};
