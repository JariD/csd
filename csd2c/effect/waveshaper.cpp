#include "waveshaper.h"
#include <cmath>

Waveshaper::Waveshaper() {
}

void Waveshaper::setDrive(float drive) {
    this->drive = drive;
}

Waveshaper::~Waveshaper(){}
//
void Waveshaper::prepare(float samplerate) {
}


float Waveshaper::applyEffect(float sample) {
//    (1/arctan(drive))*arctan(drive*x);
    float drive = 0.7f;
    float output = (1.0f / std::atan(drive)) * std::atan(drive * sample);
    return output;
}

