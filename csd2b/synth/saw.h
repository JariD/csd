#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw {
public:
    Saw();
    ~Saw();

    //override calculate from base class
    void calculate();
};


#endif
