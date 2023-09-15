import simpleaudio as sa
import time

noteValue = [] #a list for individual note values

# Input mode, next code asks a couple of inputs.
# I am implementing some sleep time in between to make it feel more human.

#Daan kept trying to break my code so I implemented some while loops to stop that from happening. :)
#so here, just like with the bpm it tries to check if the number of notes to playback are not negative or anything other than an integer
numPlaybackTimes = 1
while numPlaybackTimes == 1:
    try:
        numPlaybackTimes = int(input("How many notes to you want to play?"))
        if numPlaybackTimes >= 1:
            break #breaks the loop
        elif numPlaybackTimes == 0:
            time.sleep(1)
            print("Hmmm... Seems like you don't want me to play any notes.")
            time.sleep(1)
            print("Well okay then... Bye!")
            time.sleep(1)
            exit()
        else:
            print("No negative integer please\n:)")
    except ValueError:
        print("Please use an integer as an input value.")

time.sleep(1)
print("Now we are going to implement a rythm")
time.sleep(1)

#BPM must and can only be a possitive integer
bpm = 1
#while loop for bpm
#Had to change while bpm = 1 to while true and change user-input to bpm so that a bpm > 50 and a bpm > 200 wouldn't print Thanks.. Snail..
while True:
    try:
        bpm = int(input("Please enter a bpm."))
        if bpm >= 1:
            #funny input add-on, didn't work as well outside of the while loop
            #here it checks if the bpm is a certain value and responds accordingly
            if bpm < 50:
                print("Thanks.. Snail..")
                break
            elif bpm > 200:
                print("Wow.. are you in a hurry?")
                break
            else:
                print("Great!")
                break
        else:
            print("The BPM must not be 0 or negative.")
    except ValueError:
        print("Please use an integer as an input value...")


time.sleep(1)
print("Now please enter the note value of " + str(numPlaybackTimes) + " notes.")
time.sleep(1)
print("Great notevalue choices are: 0.25, 0.5, 1, 1.5, 2.")
#Cant seem to find a working way to implement the while code in a for loop.
#Next part is still breakable, for now...
for x in range(numPlaybackTimes):
    noteValue.append(float(input("")))

time.sleep(1)
print("Thank you.")
time.sleep(1)
print("Now starting the sequence.")

#Sequence
wave_obj = sa.WaveObject.from_wave_file("/Users/admin/Desktop/Button_Select.wav")
for i in range(numPlaybackTimes): #Speelt x aantal keer de sample af
    play_obj = wave_obj.play()
    play_obj.wait_done()
    #Delay of the duration of a note within the bpm, times its value.
    time.sleep((60 / float(bpm)) * float(noteValue[i])) #Enorm geklooi hier
