import simpleaudio as sa
import time

noteValue = [] #a list for individual note values

# Input mode, next code asks a couple of inputs.
# I am implementing some sleep time in between to make it feel more human.
numPlaybackTimes = int(input("How many notes to you want to play?"))
time.sleep(1)
print("Now we are going to implement a rythm")
time.sleep(1)

#BPM must and can only be a possitive integer
bpm = 1
#while loop for bpm
while bpm == 1:
    try:
        userInput = int(input("Please enter a bpm."))
        if userInput >= 1:
            break #Breaks the loop
        else:
            print("The BPM must not be 0 or negative.")
    except ValueError:
        print("Please use an integer as an input value...")

#Funny bpm add-on
if bpm < 50:
    print("Thanks.. Snail..")
    time.sleep(1)
elif bpm > 200:
    print("Wow.. Are you in a hurry?")
    time.sleep(1)
else:
    print("Great!")
time.sleep(1)

print("Now please enter the note value of " + str(numPlaybackTimes) + " notes.")
time.sleep(1)
print("Great notevalue choices are: 0.25, 0.5, 1, 1.5, 2.")

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
