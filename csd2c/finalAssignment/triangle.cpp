#include "triangle.h"
#include "math.h"

//edited own triangle with more efficient code parts from Tim
Triangle::Triangle() : Triangle(0, 0) {}

Triangle::Triangle(float frequency, float samplerate)
    : Oscillator(frequency, samplerate) {
  std::cout << "Triangle - constructor\n";
}

Triangle::~Triangle() { std::cout << "Triangle - destructor\n"; }

void Triangle::calcNextSample() {
  sample = phase * 4.0 - 1.0;
  if (phase >= 0.5) {
    sample = -phase * 4 + 3;
  }
}
