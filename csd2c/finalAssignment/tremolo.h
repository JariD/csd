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
  Sine sines[2];
  Tremolo tremolo;
};
