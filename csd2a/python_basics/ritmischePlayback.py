import simpleaudio as sa
import time

noteValue = [] #a list for individual note values

# Input mode, next code asks a couple of inputs.
# I am implementing some sleep time in between to make it feel more human.
numPlaybackTimes = int(input("How many notes to you want to play?"))
time.sleep(1)
print("Now we are going to implement a rythm")
time.sleep(1)
bpm = int(input("Please enter a bpm "))
time.sleep(1)

#if statements to check if bpm is legit
#funny check to not break bpm
if bpm < 0:
    bpm = int(input("That is not a possible bpm.. Please re-enter"))
    time.sleep(1)
if bpm < 0:
    bpm = int(input("No.. Just no.. Please re-enter"))
    time.sleep(1)
if bpm < 0:
    bpm = int(input("For fuck sake.. Are you serious?"))
    time.sleep(1)
if bpm < 0:
    bpm = int(input("Last chance.. Weirdo.."))
    time.sleep(1)
if bpm < 0:
    print("Nope.. Bye.")
    exit()

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
