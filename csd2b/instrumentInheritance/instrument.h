#ifndef _INSTR_H_
#define _INSTR_H_
#include <iostream>

class Instrument
{
public:
    Instrument(std::string name);
    ~Instrument();

    void play();
protected:
    std::string name;
};

#endif