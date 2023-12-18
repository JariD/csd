#ifndef _UI_H_
#define _UI_H_
/*
 * Utility code for validating user input
 *
 * Available checks and queries:
 * - expected numeric
 * - value within range
 * - string selection
 */
#include <iostream>
#include <string>

class UI
{
public:
    bool selectSynth();
    int retrieveUserSelection(std::string selectionOptions[], int numOptions);
    float retrieveValueInRange(float min, float max);
private:
    //TODO: FIX
//    UI* selectionSynth;
//    bool selectedSynth;
//    int synthSellect;
    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);
};

#endif