import time
import simpleaudio as sa
import midi as mi
from midiutil import MIDIFile
import functions as func
import ikeda_attractor as ia
import random

# =======================
# init bpm for midi engine
bpm = 300

# load samples (add to assets folder and change sample name)
samples = {}
# put high sample here (hi hats)
samples["low"] = sa.WaveObject.from_wave_file("assets/Hat-Little.wav")
# put mid sample here (snares)
samples["high"] = sa.WaveObject.from_wave_file("assets/Snare-Ditty.wav")
# put low sample
samples["mid"] = sa.WaveObject.from_wave_file("assets/Basedrum-Dancy.wav")
# put sample for init sound
samples["init"] = sa.WaveObject.from_wave_file("assets/Ocarina_C2_Short.wav")

print("Irregular Beat Generator")
# init simpleaudio driver to prevent glitching of first ts
samples["init"].play()
time.sleep(1)

bpm = func.user_input_bpm()


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


# 2 simple input functions for presenting the algorithm.
# might put in while loop latern
# points = int(input("points?"))
# start = int(input("start?"))

#endless loop of generating new ikeda sequence, if Y is pressed inside midi loop the script is exit()
while True:
    # translated x to high, y to mid, and z to low samples
    # transform list into true bpm timestamp list by multiplying original ts with multiplyer
    ts_seq_high, ts_seq_mid, ts_seq_low = ia.gen_sequence_ikeda_output(u=random.uniform(0.90,1.02), x0=0, y0=0, z0=1, num_points=1000, seq_start=random.randint(200,600), seq_end=-1, save_to_file='output.txt')
    # multiply the ts by quarternote_dur for all array
    ts_seq_high = [x * quarternote_dur for x in ts_seq_high]
    ts_seq_mid = [x * quarternote_dur for x in ts_seq_mid]
    ts_seq_low = [x * (quarternote_dur * 2) for x in ts_seq_low]

    # create event sequence
    event_seq = []
    event_seq += func.create_events(ts_seq_high, "high")
    event_seq += func.create_events(ts_seq_mid, "mid")
    event_seq += func.create_events(ts_seq_low, "low")

    # print event list
    # print(event_seq)

    # order events based on timestamp
    event_seq.sort(key=func.get_ts)

    # iterate through time sequence and play sample

    time_zero = time.time()
    play_seq = event_seq.copy()
    event = play_seq.pop(0)

    num_playback_times = 1

    # endless loop of playback generation

    func.playback(num_playback_times,time,time_zero,event,samples,play_seq,event_seq)


    # # Ask user to save midi sequence Y/n
    # # either Y or n save the sequence to file_name output
    mi.user_input_save_midi(event_seq,bpm,quarternote_dur)
        