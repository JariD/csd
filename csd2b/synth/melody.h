#ifndef _MELODY_H_
#define _MELODY_H_
#include <iostream>
#include <vector>

# define NUM_NOTES 10

class Melody
{
public:
  // setters and getters
  Melody();
  ~Melody();
//    void setNote(int index, float note);
  float getNote();

private:
protected:
    // makes the melody array dynamic
    // fixes the unable to build
    // from stackoverflow
//    std::vector<float> melody;
//    int numNotes;
    int index;
    float melody[NUM_NOTES] = {61, 63, 64, 66, 63, 63, 59, 61, 61, 61};
};

#endif