#include "effect.h"
#include <iostream>

//Code parts from class
Effect::Effect(float dryWet) {
    setDryWet(dryWet);
}


//code from class
void Effect::setDryWet(float dryWet) {
    if(dryWet >=0.0f && dryWet <= 1.0f){
        wet = dryWet;
        dry = 1.0f - dryWet;
    } else {
        std::cout << "LOG ERROR - setDryWet" << std::endl;
    }
}

Effect::~Effect() {}

float Effect::processFrame(float input) {
    float output = applyEffect(input);
    output *= wet;
    output += input * dry;
    return output;
}