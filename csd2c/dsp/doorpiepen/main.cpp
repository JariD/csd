#include <iostream>
#include <thread>
#include "writeToFile.h"
#include "math.h"
#include <limits>

#define SAMPLE_RATE 48000

class FIR {
public:
    FIR(){
        buffer = 0.0f;
    }
    float processLPF(float input) {
        output = 0.5f * input + 0.5f * buffer;
        buffer = input;
        return output;
    }
    float processHPF(float input) {
        output = 0.5f * input - 0.5f * buffer;
        buffer = input;
        return output;
    }

private:
    float output;
    float buffer;
};


int main(int argc,char **argv) {

    FIR filter;
    float frequency = SAMPLE_RATE / 2;

    WriteToFile fileWriter("output.csv", true);
    for (int n = 0; n < SAMPLE_RATE; n++) {
        float sample = sin(2 * M_PI * frequency * n / SAMPLE_RATE);
        fileWriter.write(std::to_string(filter.processHPF(sample)) + "\n");
    }
}