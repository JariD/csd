#include <iostream>
#include "instrument.h"

Instrument::Instrument(std::string name)
{
    std::cout << "Instrument::Instrument - constructor, name::"
    << name << "\n";
    this ->name = name;
}