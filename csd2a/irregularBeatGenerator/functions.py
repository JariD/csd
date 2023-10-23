# some functions for the irregular beat generator

# function from ciska's code
# returns a list of event dictionaries, present it with a list of ts and the sample_id
def create_events(ts_seq=list, sample_id=str):
    events = []
    for i in ts_seq:
        events.append({"ts": i, "sample_id": sample_id})
    return events

# function from ciska's code
def get_ts(event=float):
    return event["ts"]

# playback function to play the sample lists
def playback(num_playback_times=int,time=float,time_zero=float,event=float,samples=str,play_seq=list,event_seq=list):
    global stop_loop
    #while loop is from ciska's code
    while num_playback_times:
        now = time.time() - time_zero
        
        # round the timestamp event if errors are in the list
        rounded_ts = round(event["ts"], 2)
        # check if we need to play a sample
        if(now > rounded_ts):
            sample_id = event["sample_id"]
            samples[sample_id].play()
            if play_seq:
                event = play_seq.pop(0)
            # if esc is pressed, stop loop = true and break loop
            # if stop_loop:
            #     break
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
            bpm = int(input("Please enter a bpm."+ "\n"))
            if bpm >= 1:
                break
            else:
                print("The value must not be 0 or negative.")
        except ValueError:
            print("Please use an integer as an input value...")
    return bpm

# function for u = user input
def user_input_u(u=float):
    while True:
        try:
            u = float(input("Enter parameter for Ikeda sequence." + "\n" + "Values between 0.8 and 1.2 are musically pleasing" + "\n"))
            if 0.1 < u < 1.5:
                break
        except ValueError:
            u = 0.918
            break
    return u