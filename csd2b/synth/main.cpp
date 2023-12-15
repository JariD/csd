#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "audioToFile.h"
#include "oscillator.h"
#include "callback.h"
#include "ui.h"
//parts of the code are from csd github

#define WRITE_TO_FILE 0

int main(int argc, char **argv) {
    std::cout << "Welcome to SimpleSynth" << std::endl;
    std::cout << "Please choose your waveform" << std::endl;
    std::string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
    int numWaveFormOptions = 4;

    UI console_ui;

    int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions,numWaveFormOptions);
    std::string oscillatorType = waveFormOptions[waveTypeSelection];
// use the selected option to show the corresponding text
    std::cout << "You selected: " << waveFormOptions[waveTypeSelection] << std::endl;
    // UI function for how many notes the user wants to play
    std::cout << "How many notes do you want to play?: " << std::endl;
    int numNotes =  console_ui.retrieveValueInRange(1, 15);

    Melody melody (numNotes);

    //for loop that fills the melody array with notes
    for(int index = 0; index < numNotes; index++) {
        std::cout << "Add a MIDI note. You chose in range of the following midi notes: " << "40 - 70" << std::endl;
        int note = console_ui.retrieveValueInRange(40, 70);
        melody.setNote(index, note);
    }
    auto callback = CustomCallback{};
    auto jackModule = JackModule{callback};

#if WRITE_TO_FILE
  AudioToFile audioToFile;
  audioToFile.write(callback);

#else
  jackModule.init(0, 1);

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
