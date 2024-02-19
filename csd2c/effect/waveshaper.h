#pragma once

#include <iostream>
#include "effect.h"

class Waveshaper : public Effect {
public:
    Waveshaper();
    virtual ~Waveshaper();
    void prepare(float samplerate) override;
    void setDrive(float drive);

private:
    float drive;
    float applyEffect(float sample) override;
};