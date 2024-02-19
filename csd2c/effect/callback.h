#pragma once

#include "jack_module.h"
#include "tremolo.h"
#include "oscillator.h"
#include "square.h"
#include "waveshaper.h"



class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Tremolo tremolo = Tremolo(14, 1);
//  Square square = Square(465);
  // TODO - implement Delay
//  Delay delay = Delay(0.7f, 100, 2048, 0.5f);
  Waveshaper waveshaper = Waveshaper();
};
