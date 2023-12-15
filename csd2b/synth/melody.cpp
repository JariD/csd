#include "melody.h"

Melody::Melody(int numNotes) : melody(numNotes, 0), numNotes(numNotes), index(0)
{}

Melody::~Melody()
{}

void Melody::setNote(int index, float note)
{
    if (index >= 0 && index < numNotes)
    {
        melody[index] = note;
    }
}

/*
 * getNote() reads the next note from the melody
 *  and wraps around to the beginning when it reached the end
 *  of the melody
 */
float Melody::getNote()
{
  // wrap index back to the beginning
  if(index >= numNotes) {
    index = 0;
  }
  // index++ --> use value, then increment
  return melody[index++];
}
