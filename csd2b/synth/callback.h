#ifndef _CALLBACK_H_
#define _CALLBACK_H_

#include "jack_module.h"
#include "saw.h"
#include "square.h"
#include "sine.h"
#include "triangle.h"
#include <math.h>
#include "melody.h"

//parts of the code are from csd github
class CustomCallback : public AudioCallback {
public:
    void prepare(int rate) override;
    void process(AudioBuffer buffer) override;
    double mtof(float mPitch);
private:
  double sampleRate = 44100;
  Sine sine;
  Square square;
  Saw saw;
  Triangle triangle;
  Melody melody = {60};
  float amplitude = 0.25;
//  Melody melody;
  int frameIndex = 0;
  /* instead of using bpm and specifying note lenghts we'll make every note
  equal length and specify the delay between notes in terms of the samplerate
  A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be played
  */
  double noteDelayFactor=0.1;
};

#endif
