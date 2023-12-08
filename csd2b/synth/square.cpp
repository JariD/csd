#include "square.h"
#include "math.h"

Square::Square(float frequency, float samplerate) : Oscillator(frequency, samplerate)
{
  std::cout << "• Square::Square - constructor\n";
}

Square::Square() : Oscillator()
{
  std::cout << "• Square::Square\n";
}

Square::~Square()
{
  std::cout << "• Square::~Square\n";
}

void Square::calculate() {
    sample = amplitude;
    if(phase >= 0.5) {
        sample *=-1.0f;
    }

