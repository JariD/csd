#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}

//void Melody::setNote(int index, float note)
//{
//    if (index >= 0 && index < numNotes)
//    {
//        melody[index] = note;
//    }
//}

/*
 * getNote() reads the next note from the melody
 *  and wraps around to the beginning when it reached the end
 *  of the melody
 */
float Melody::getNote()
{
  // wrap index back to the beginning
  if(index >= NUM_NOTES) {
    index = 0;
  }
  // index++ --> use value, then increment
  return melody[index++];
}
