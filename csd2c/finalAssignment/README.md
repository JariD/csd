## CSD 2C Effect Processing Duo-Project

This project is a duo project for CSD,

During block 2c, Tim and I collaborated on developing a 
series of audio effects and their integration, of which I used the Bela platform.
I wanted to create interactive audio effects that could be controlled
through interactions with a plant.

### Effect Chain (see systemDiagram.jpg)

The system consists of an audioRead and an audioWrite, inbetween the chain are 3 effects. And a sensor connected to the plants controll the parameters of the audio effects.

For the effect chain, I combined a bit crusher, tremolo, and waveshaper.
My goal was to create the impression that the plant doesn't like to be touched. 
The combination of the waveshaper and bit crusher works exceptionally well, 
producing a distortion that is surprisingly pleasing to the ears. 

#### The sensor
The systems effects are controlled by a distance sensor in the plant, these are read on the BELA and the data is then used to controll the parameters of the effects.

#### The system chain flowchart: (see systemDiagram.jpg)

    input (audioRead) → bitcrusher → tremolo → waveshaper → output (audioWrite)
                plant sensor: ^ bitDepth  ^ modDepth ^ drive

### Class Flow Diagrams (Own effects)

       Render  ←  Effect
                    ↑
                 Bitcrusher      Oscillator
                 Waveshaper       ↑
                 Tremolo     ←   Sine

#### Bitcrusher
The bitcrusher crushes the bitrate of the incoming samples and give the sound a distorted square wave kind of sound.

    input → Bitcrusher Calculation → output
                 ^ setBitDepth (sensor)
                
#### Waveshaper
The waveshaper I used to add an extra crunch to the already distorted sound of the bitcrusher.

    input → Atan Calculation applyEffect() → output
                ^ set drive (sensor)

### Contributions

We shared the effect baseclass and implemented our own effects on that.

#### Hours on the project

During 2c, overall I worked around 6-10 hours a week on the project. Near the end of the project that was around 10-20 hours.

### Reflection

Looking back on it now, I can see that there are definitely things I would do differently. For example, there was a lot of outcommented code and the files were very messy. Overall, though, I am very happy with the results and outcome of the project. As I was reviewing the code and revising some of the comments I noticed several aspects that I'd write more efficient next time.