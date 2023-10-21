import time
import simpleaudio as sa
from midiutil import MIDIFile




# =================== Functions ====================================

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


# ================== create events and playback loop =================



# load samples
samples = {}
samples["high"] = sa.WaveObject.from_wave_file("assets/Plop.wav")
samples["mid"] = sa.WaveObject.from_wave_file("assets/Button_Select.wav")
samples["low"] = sa.WaveObject.from_wave_file("assets/kick.wav")

print("Irregular Beat Generator")
samples["high"].play()

#TODO Loop met user input

ts_seq_high = [1.0, 1.5, 2.0, 2.5, 3.0, 3.5]
ts_seq_mid = [1.0, 3.0, 4.0]
ts_seq_low = [0, 0.14, 2.0]


# create event sequence
# event_seq = []
# event_seq += create_events(ts_seq_high, "high")
# event_seq += create_events(ts_seq_mid, "mid")
# event_seq += create_events(ts_seq_low, "low")

event_seq = [create_events(ts_seq_low, x) for x in ["high", "mid","low"] ]

print(event_seq)

# orden events based on timestamp
event_seq.sort(key=get_ts)

# iterate through time sequence and play sample

time_zero = time.time()
play_seq = event_seq.copy()
event = play_seq.pop(0)


num_playback_times = 4

# code from ciska 
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
            


## ======================== MIDI FUNCTION ===================================
"""
User input(do you want to store midi data?)
    y => store data
    n => not store 
"""
