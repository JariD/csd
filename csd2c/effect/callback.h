#pragma once

#include "jack_module.h"
#include "tremolo.h"
#include "oscillator.h"
#include "saw.h"
#include "waveshaper.h"
//#include "delay.h"
//#include "filters.h"
#include "bitcrusher.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Tremolo tremolo = Tremolo(2, 1);
//  Saw saw = Saw(465);
  // TODO - implement Delay
//  float broeder;
//  float sample;
//  Delay delay = Delay(10000, 40000, 0.6f, 0.6f);
//  Delay delay2 = Delay(20000, 40000, 0.6f, 0.6f);
//  Waveshaper waveshaper = Waveshaper();
//  IIRFilter filter;
    Bitcrusher bitcrusher;
};
