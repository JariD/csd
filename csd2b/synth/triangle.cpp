#include "triangle.h"
#include "math.h"

Triangle::Triangle(float frequency, float sampleRate) : Oscillator(frequency, sampleRate)
{
    std::cout << "• Triangle::Triangle - constructor\n";
}

Triangle::~Triangle()
{
    std::cout << "• Triangle::~Triangle\n";
}

void Triangle::calculate() {
    //phase to 0.5; -1 to 1
    if (phase < 0.5) {
        sample = (phase * 4.0) - 1.0;
    //phase after 0.5; 1 to -1
    } else {
        //phase after 0.5 is 2 so - 3 makes -1
        sample = -((phase * 4.0) - 3.0);
    }
}