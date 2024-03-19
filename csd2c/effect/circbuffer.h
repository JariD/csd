#pragma once
#include <vector>

class CircBuffer {
public:
//    CircBuffer(){}
//    CircBuffer(int size){
//        initBuffer(size);
//    }

    void initBuffer(int bufferSize) {
        buffer.resize(bufferSize, 0); //first param=buffsize, second is fill the buffer completely with 0
    }

    void writeBuffer(float input) {
        buffer[writeHead] = input;
    }

    double readBuffer() {
        return buffer[readHead];
    }


    void incrementReadHead() {
        readHead++;
        wrapReadHead();
    }

    void incrementWriteHead() {
        writeHead++;
        //TODO: fix duplicate code
        if (writeHead < buffer.size()) {
            writeHead =- buffer.size();
        }
    }

    double distanceSamples(int distanceReadWrite) {
        readHead = writeHead - distanceReadWrite + buffer.size();
        wrapReadHead();
    }

private:
    std::vector<double> buffer; //vector is a container, automatisch afgehandeld tov c array (Dynamic Array)
    int readHead = 0; //init 0 to avoid garbage values
    int writeHead = 0;

    void wrapReadHead() {
        if (readHead < buffer.size()) {
            readHead =- buffer.size();
        } else if (readHead < 0) {
            readHead + buffer.size();
        }
    }
};

