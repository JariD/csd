import simpleaudio as sa
import time

# Input mode, next code asks a couple of inputs.
# I am implementing some sleep time in between to make it feel more human.

#Daan kept trying to break my code so I implemented some while loops to stop that from happening. :)
#so here, just like with the bpm it tries to check if the number of notes to playback are not negative or anything other than an integer
while True:
    try:
        numPlaybackTimes = int(input("How many notes to you want to play?"))
        if numPlaybackTimes >= 1:
                if numPlaybackTimes > 40:
                    print("That is a bit much to individualy add, but if you say so.")
                    break
                else:
                    break
        if numPlaybackTimes == 0:
            time.sleep(1)
            print("Hmmm... Seems like you don't want me to play any notes.")
            time.sleep(1)
            # here I added an exit script, so it exits the script when a user puts in a 0
            print("Well okay then... Bye!")
            time.sleep(1)
            exit()
        elif numPlaybackTimes < 0:
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
            #else if the bpm is above 200 it jokes if the user is in a hurry
            elif bpm > 200:
                print("Wow.. are you in a hurry?")
                break
            else:
                print("Great!")
                break #break the loop
        # stops breaking the code with negative bpm value
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

# added a list for individual notevalues
noteValue = []

#So here I added yet another while loop
#Only breaks the loop when the lenght of the list is equal to the number of playbacks
while len(noteValue) < numPlaybackTimes:
    try:
        # makes a newValue each loopround and a pretty string of the new lenght of the list + 1 to represent the new value
        newValue = float(input("Please enter value nr " + str(len(noteValue) + 1) + ": "))
        # straight forward like in the last loop, if newValue is les or equal to 0 its restarts the loop.
        if newValue <= 0:
            print("This value is not possible.")
        # Saw that a value of for instance 939491 could be added so I added a maximum value
        elif newValue > 10:
            print("This wouldn't be 'musically'.. Sorry.")    
        else:
            noteValue.append(newValue)      
    #if anything other than a float or int is added it gives an error message.       
    except ValueError:
        print("Please add a valid input value")

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

#just wanted to add a little bit of a goodbye party at the end of the sequence.
print("The sequence has finished playing. Bye!")
time.sleep(1)
exit()