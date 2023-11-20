#include <iostream>

class Guitar
{
public:
    char resonator;
    char stringtype;
    int priceInEuro;
    
    void play(int priceInEuro)
    {
        if (priceInEuro > 1500) {
            std::cout << "plinky ploink!" << std::endl;
        }
        else {
            std::cout << "Plinky Clankgggg" << std::endl;
        }
    }
};
