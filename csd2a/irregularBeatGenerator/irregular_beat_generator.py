import time
import simpleaudio as sa
from midiutil import MIDIFile
import midi as mi
import functions as func
import ikeda_attractor as ia




# =================== Functions ====================================

# function from ciska's code
# returns a list of event dictionaries, present it with a list of ts and the sample_id
def create_events(ts_seq, sample_id):
    events = []
    for i in ts_seq:
        events.append({"ts": i, "sample_id": sample_id})
    return events

# also ciska
def get_ts(event):
    return event["ts"]


# ================== create events and playback loop =================


# load samples (add to assets folder and change sample name)
samples = {}
# put high sample here (hi hats)
samples["high"] = sa.WaveObject.from_wave_file("assets/Plop.wav")
# put mid sample here (snares)
samples["mid"] = sa.WaveObject.from_wave_file("assets/Button_Select.wav")
# put low sample
samples["low"] = sa.WaveObject.from_wave_file("assets/kick.wav")


print("Irregular Beat Generator")
# init simpleaudio driver to prevent glitching of first ts
samples["high"].play()
time.sleep(1)

#TODO 
# user input for bpm

# user input for sequence length
# user input for sequence start (or random)

#TODO maybe add a function which makes u a variable for if input 0-10 -> u=0.1-1.0 
""""
implementing the above will add a more chaos if number = higher and less if number is lower
but implementing this will break the filter for data will give different plot
possibly makes the sequence less musically
"""

# original list for testing the sequence with pre existing arrays
"""
ts_seq_high = [0.0,0.5,1.5,2.0,2.5,3.0,4.0,4.5]
ts_seq_mid = [1.0, 1.5, 3.0, 4.0]
ts_seq_low = [1.5, 2.0,3.0]
"""

# transform timestamps into true bpm timestamps
bpm = 300

# duration of quarternote gives the multiplyer for ts
    # seconds in a minute / prefered bpm: 60 / 120 = 0.5
quarternote_dur = 60.0 / bpm

# translated x to high, y to mid, and z to low samples
# transform list into true bpm timestamp list by multiplying original ts with multiplyer
ts_seq_high, ts_seq_mid, ts_seq_low = ia.ikeda_sequence_tornado()
ts_seq_high = [x * quarternote_dur for x in ts_seq_high]
ts_seq_mid = [x * quarternote_dur for x in ts_seq_mid]
ts_seq_low = [x * (quarternote_dur * 2) for x in ts_seq_low]

# load samples (add to assets folder and change sample name)
samples = {}
samples["high"] = sa.WaveObject.from_wave_file("assets/Plop.wav")
samples["mid"] = sa.WaveObject.from_wave_file("assets/Button_Select.wav")
samples["low"] = sa.WaveObject.from_wave_file("assets/kick.wav")


# create event sequence
event_seq = []
event_seq += create_events(ts_seq_high, "high")
event_seq += create_events(ts_seq_mid, "mid")
event_seq += create_events(ts_seq_low, "low")

print(event_seq)

# print(event_seq)

# order events based on timestamp
event_seq.sort(key=get_ts)

# iterate through time sequence and play sample

time_zero = time.time()
play_seq = event_seq.copy()
event = play_seq.pop(0)

num_playback_times = 1


func.playback(num_playback_times,time,time_zero,event,samples,play_seq,event_seq)
            


## ======================== MIDI FUNCTION ===================================

# TODO user input
"""
do you want to save? y/n
    if n
        regenerate
    if y
        save generation to user input string
"""

# function to save the mididata to a separate file
mi.save_to_midi(event_seq=event_seq,bpm=bpm,event_dur=0.1,quarternote_dur=quarternote_dur,
file_name="events_lists.midi")

