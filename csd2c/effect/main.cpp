#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "audioToFile.h"
//parts of the code are from csd github

#define WRITE_TO_FILE 0

int main(int argc, char **argv) {

    auto callback = CustomCallback{};
    auto jackModule = JackModule{callback};

#if WRITE_TO_FILE
    AudioToFile audioToFile;
  audioToFile.write(callback);

#else
    jackModule.init(1, 1);

    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
        }
    }
#endif
    //end the program
    return 0;
} // main()
