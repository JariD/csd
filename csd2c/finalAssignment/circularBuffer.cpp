#include "circularBuffer.h"
#include <cstring>

//code from github.com/timschippers

CircularBuffer ::CircularBuffer() : CircularBuffer(256){};
CircularBuffer::CircularBuffer(int size)
    : indexWriteHead(0), indexReadHead(0), size(size) {
  setSize(size);
};

CircularBuffer::~CircularBuffer() { free(buffer); };

void CircularBuffer::setDistanceReadHead(float samples) {
  // TODO check if distance is bigger than size to catch error
  distance = samples;
  indexReadHeadFloat = indexWriteHead - distance;
  indexReadHead = (int)indexReadHeadFloat;
  wrapHead(indexReadHead);
  wrapHeadFloat(indexReadHeadFloat);
};

void CircularBuffer::setSize(int size) {
  // TODO check if size is smaller than num delaysamples to catch error
  free(buffer);
  this->size = size;
  //std::cout << "setting max delay time in " << size << " samples" << std::endl
  buffer = (float *)malloc(size * sizeof(float));
  memset(buffer, 0, size * sizeof(float));
};
