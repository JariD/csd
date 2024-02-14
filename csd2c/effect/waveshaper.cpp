#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper(float drive) {
    this->drive = drive;
}

float applyEffect(float sample) {
//    (1/arctan(drive))*arctan(drive*x);
// TODO: build arctan effect
}

