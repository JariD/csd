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