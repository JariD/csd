# Functions for the irregular beat generator

# function from ciska's code
# returns a list of event dictionaries, present it with a list of ts and the sample_id
def create_events(ts_seq, sample_id):
    events = []
    for i in ts_seq:
        events.append({"ts": i, "sample_id": sample_id})
    return events

# function from ciska's code
def get_ts(event):
    return event["ts"]

# playback function to play the sample lists
def playback(num_playback_times=int,time=float,time_zero=float,event=float,samples=str,play_seq=list,event_seq=list):
    #while loop is from ciska's code
    while num_playback_times:
        now = time.time() - time_zero
        # check if we need to play a sample
        if(now > event["ts"]):
            sample_id = event["sample_id"]
            samples[sample_id].play()
            if play_seq:
                event = play_seq.pop(0)
            else:
                    #NOTE: a bit of duplicate code below, this is just a couple
                    time_zero = time.time()
                    play_seq = event_seq.copy()
                    num_playback_times -= 1
                    event = play_seq.pop(0)
                    time_zero = time.time()
        else:
                time.sleep(0.001)

# function for bpm user input
def user_input_bpm():
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
                print("The value must not be 0 or negative.")
        except ValueError:
            print("Please use an integer as an input value...")
    return bpm


# Ask user to save midi sequence Y/n
# either Y or n save the sequence to file_name output
def user_input_save_midi():
    while True:
        yesno = input("Do you want to save this midi sequence? Y/n?")
        if yesno == 'Y':
            file_name = input("Enter file name: ")
            mi.save_to_midi(event_seq=event_seq, bpm=bpm, event_dur=0.1, quarternote_dur=quarternote_dur, file_name=file_name + ".midi")
            break
        elif yesno == 'n':
            break
        else:
            print("That is not a valid input. Please enter Y or n.")
    return