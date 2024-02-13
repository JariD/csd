#include <iostream>
#include "writeToFile.h"
#include "math.h"
#define SAMPLE_RATE 48000
//All processes are connected to DSP assignments
class FIR {
public:
    FIR(){
        buffer = 0.0f;
        buffer2 = 0.0f;
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
    float processHPFinv(float input) {
        output = -0.5f * input + 0.5f * buffer;
        buffer = input;
        return output;
    }
    float processFour(float input) {
        output = -0.5f * input - 0.5f * buffer;
        buffer = input;
        return output;
    }
    float processFive(float input) {
        output = 0.25f * input + 0.5f * buffer + 0.25f * buffer2;
        buffer2 = buffer;
        buffer = input;
        return output;
    }
    float processSix(float input) {
        output = 0.25f * input - 0.5f * buffer + 0.25f * buffer2;
        buffer2 = buffer;
        buffer = input;
        return output;
    }
    float processSeven(float input) {
        output = 0.5f * input - 0.5f * buffer2;
        buffer2 = buffer;
        buffer = input;
        return output;
    }
    float processEight(float input) {

//        output = -0.75f * input - 0.5f * buffer + 0.25f * buffer5; <- Heel geinig
        output = -0.75f * buffer5;
        buffer5 = buffer4;
        buffer4 = buffer3;
        buffer3 = buffer2;
        buffer2 = buffer;
        buffer = input;
        return output;
    }
private:
    float output;
    float buffer, buffer2, buffer3, buffer4, buffer5;
};

//float sine(int frequency,)

int main(int argc,char **argv) {

    FIR filter;

    WriteToFile fileWriter("output.csv", true);
    for (int frequency = 0; frequency < SAMPLE_RATE/2; frequency +=200) {
        for (int n = 0; n < SAMPLE_RATE; n++) {
            float sample = sin(2 * M_PI * frequency * n / SAMPLE_RATE);
            fileWriter.write(std::to_string(filter.processEight(sample)) + "\n");
        }
    }
}