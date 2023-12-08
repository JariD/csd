#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "saw.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;


private:
  float samplerate = 44100;
  Saw saw = saw(220, samplerate);
};

#endif
