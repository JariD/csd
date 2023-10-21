import simpleaudio as sa
import time

# Ask for input playback times
while True:
    try:
        num_playback_times = int(input("How many notes to you want to play?"))
        if num_playback_times >= 1:
                if num_playback_times > 40:
                    print("That is a bit much to individualy add, but if you say so.")
                    break
                else:
                    break
        if num_playback_times == 0:
            print("Hmmm... Seems like you don't want me to play any notes.")
            # here I added an exit script, so it exits the script when a user puts in a 0
            print("Well okay then... Bye!")
            exit()
        elif num_playback_times < 0:
            print("No negative integer please\n:)")
    except ValueError:
        print("Please use an integer as an input value.")

print("Now we are going to implement a rhythm")

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
                break #break the loopx
        # stops breaking the code with negative bpm value
        else:
            print("The BPM must not be 0 or negative.")
    except ValueError:
        print("Please use an integer as an input value...")

print("Now please enter the note value of " + str(num_playback_times) + " notes.")
print("Great notevalue choices are: 0.25, 0.5, 1, 1.5, 2.")

# added a list for individual notevalues
note_durations = []

#So here I added yet another while loop
#Only breaks the loop when the lenght of the list is equal to the number of playbacks
while len(note_durations) < num_playback_times:
    try:
        # makes a newValue each loopround and a pretty string of the new lenght of the list + 1 to represent the new value
        new_dur = float(input("Please enter value nr " + str(len(note_durations) + 1) + ": ").replace(',','.'))
        # straight forward like in the last loop, if newValue is les or equal to 0 its restarts the loop.
        if new_dur <= 0:
            print("This value is not possible.")
        # Saw that a value of for instance 939491 could be added so I added a maximum value
        elif new_dur > 10:
            print("This wouldn't be 'musically'.. Sorry.")    
        else:
            note_durations.append(new_dur)      
    #if anything other than a float or int is added it gives an error message.       
    except ValueError:
        print("Please add a valid input value")

print("Thank you.")
print("Now starting the sequence.")

# inserts the sample
sample_button = sa.WaveObject.from_wave_file("/Users/admin/Desktop/Button_Select.wav")

## For the timestamps function I used the code by Ciska
#
# calculate the duration of a quarternote in seconds
quarternote_dur = 60.0 / bpm
print("bpm:", bpm, "quarternote_dur", quarternote_dur)

# transform note durations to sequence of time durations
time_durations = []
for note_dur in note_durations:
    time_durations.append(quarternote_dur * note_dur)

print("time_durations", time_durations)


# transform time durations to a sequence of timestamps
timestamp_seq = []
# use the sum of the durations to calculate the timestamp for each note
sum = 0
for time_dur in time_durations:
    timestamp_seq.append(sum)
    sum = sum + time_dur

print("timestamp_seq:", timestamp_seq)


# retrieve the first time stamp
if timestamp_seq:
    ts = timestamp_seq.pop(0)
else:
    # list contains no items
    print("no timestamps --> exit")
    exit()

# store the current time
time_zero = time.time()
print("time zero:", time_zero)

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    # check if we passed the next timestamp,
    # if so, play sample and fetch new timestamp
    if(now >= ts):
        sample_button.play()
        if timestamp_seq:
            ts = timestamp_seq.pop(0)
        else:
            # no new timestamp available --> break while loop
            break

    time.sleep(0.001)

# wait till last sample is done playing before exit
time.sleep(time_durations[-1])

#just wanted to add a little bit of a goodbye party at the end of the sequence.
print("The sequence has finished playing. Bye!")
exit()