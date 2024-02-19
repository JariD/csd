#include "waveshaper.h"
#include <cmath>

Waveshaper::Waveshaper(float drive) {
    this->drive = drive;
}
//
//void Waveshaper::prepare(float samplerate) {
//}


float applyEffect(float sample, float drive) {
//    (1/arctan(drive))*arctan(drive*x);
    float output = (1.0f / std::atan(drive)) * std::atan(drive * sample);
    return output;
}

