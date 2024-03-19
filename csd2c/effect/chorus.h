#pragma once
#include "effect.h"
#include "sine.h"
#include "circbuffer.h

class Chorus : public Effect {
public:
   Chorus() {
       std::cout << "Chorus constructor.\n";
   }
   ~Chorus() {
       std::cout << "Chorus Destructor.\n";
   }

   void prepare(float samplerate){
       sine.prepare(float samplerate);
   }

private:
    float applyEffect(float sample) override {
       // input -> delay<-lfo met depth en rate -> y[n]
   }

   float modRate;
   float modDepth;
   float lfoFreq;
   Sine sine;
};