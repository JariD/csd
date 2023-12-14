#ifndef _MELODY_H_
#define _MELODY_H_
#include <iostream>
#define NUM_NOTES 10

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getNote();

protected:
  // Cmaj7 -  arpeggio
  float melody[NUM_NOTES] = {60, 61, 61, 75, 62, 67, 64, 69, 60, 55};
  // the index of the current note - readIndex
  int index;
};

#endif