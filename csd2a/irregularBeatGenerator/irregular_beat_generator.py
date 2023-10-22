import time
import simpleaudio as sa
import midi as mi
from midiutil import MIDIFile
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


# init bpm for midi engine
bpm = 300

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

bpm = func.user_input_bpm()
print(bpm)

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
# duration of quarternote gives the multiplyer for ts
    # seconds in a minute / prefered bpm: 60 / 120 = 0.5
            # / 2 to make it more musical
quarternote_dur = (60.0 / bpm) / 2


# # TODO loop or function to ask user for long or short loop, + enter loop length
# while True:
#     # enter sequence start 
#     seq_length = float(input("Enter a loop length, leave empty for full sequence."))
#     if seq_length == int:

#         break
#     elif seq_length == '':
#         seq_start = 0
#         break
#     else:
#         print("Please enter a loop length or leave empty")
#         break

# print(seq_start)

# translated x to high, y to mid, and z to low samples
# transform list into true bpm timestamp list by multiplying original ts with multiplyer
ts_seq_high, ts_seq_mid, ts_seq_low = ia.gen_sequence_ikeda_output(u=0.919, x0=0, y0=0, z0=1, num_points=10, seq_start=0, seq_end=-1, save_to_file='output.txt')
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

# print event list
#print(event_seq)

# order events based on timestamp
event_seq.sort(key=get_ts)

# iterate through time sequence and play sample

time_zero = time.time()
play_seq = event_seq.copy()
event = play_seq.pop(0)

num_playback_times = 1


func.playback(num_playback_times,time,time_zero,event,samples,play_seq,event_seq)


# # Ask user to save midi sequence Y/n
# # either Y or n save the sequence to file_name output
mi.user_input_save_midi(event_seq,bpm,quarternote_dur)
