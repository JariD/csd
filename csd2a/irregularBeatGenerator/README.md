# Irregular Beat Generator

The Irregular Beat Generator is an algoritmic rythm generator.
It uses an Ikeda Attractor to generate a rythmic composition.
You can either use the finetuned beat generator or tinker with the ikeda generation input

## Finetuned for final assignment

The code is finetuned for the presentation of the end assignment. 
    When the beat generator runs the following function, u is the amount of chaos in the sequence. I finetuned the code as much so that 
    the outcome is always interesting as a u of less than 0.8 sometimes only gives the 
        gen_sequence_ikeda_output(u=0.918, x0=0, y0=0, z0=1, num_points=1000, seq_start=0, seq_end=50)
Originally the generator creates a list of num_points with a lot of rythmic beats and fills that you can export as a total midi list so you can
edit it easily in your DAW of preference.

## Focus

For the end assignment I put the focus on the generation part. As I wanted to have a meaningfull and usefull outcome that I can use in my own music.
A lot of time went in transforming the raw Ikeda data into usefull and meaningfull data for the beat generator.
Added in the files is an example of implementation. (The midi data in the example is unedited). The data creats a lot of uneven beats and therefore 
inherently has a polyrithmic function.

## Implementation

Sometimes when the code is run the round function does not work properly, you can check this with the print(event_seq) function. Because of this issue
I made it that you can retrigger generation. This will take new values for the u, number of points and start of the sequence. You can re-generate as much as you like untill you get usefull output which you can save to a custom midi file. I gave a try at the decimal library but found out that it would make the program too complex for now. This could be an implementation in the future. A user of the program probably has some experience with python as the real value in the program is in tinkering with the ikeda generation. A plot function is added to visualise the data outcome and I added some example plots in the plot files and some noteworthy function examples.

## Reflection

I would've liked to add a user input function so that a user can really customize the sequence to it's own liking but found out that the data out of the sequence can become really chaotic or boring with some inputs so I hardcoded certain limits to the data input so it would always give a perpetual rythmic outcome.

Because of the naturally occurring polyrhythmic patterns in the Ikeda output, I decided to leave out the user input for irregular time signatures, and therefore made a consious choice to slightly deviate from the final assignment as this would be more in line with the vision I had for the end result.

For the next block, I aim to keep the final assignment in mind from the beginning and ensure that the assignments in between contribute to my artistic vision for the final assignment.

### Time spent on assignment

The following is an estimation of the time I spent on the assignment
    6-10 hrs: Making the irregular_beat_generator.py work with code (this includes other assignments)
    10-15hrs: Building ikeda_attractor and filtering/implementing data
    1-2hrs: midi implementation
    5-20hrs: practicing python with automate the boring stuff