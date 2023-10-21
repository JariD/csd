#   The following code uses an adaptation of the following code:
#   https://pypi.org/project/MIDIUtil
#

from midiutil import MIDIFile

# function to store midi data
def save_to_midi(event_seq:list, bpm:int, event_dur:float,quarternote_dur:int, file_name:str):

    # set the necessary values for MIDI util
    velocity=80
    track = 0
    channel = 9 # corresponds to channel 10 drums


    # create the MIDIfile object, to which we can add notes
    mf = MIDIFile(1)
    # set name and tempo
    time_beginning = 0
    mf.addTrackName(track, time_beginning, "Beat Sample Track")
    mf.addTempo(track, time_beginning, bpm)

    instr_midi_pitch = {
        "high": 36,
        "mid": 37,
        "low": 38
    }


    for event in event_seq:
        # transform time (sec) to (qnote)
        qnote_time = event["ts"] / quarternote_dur
        instr_name = event["sample_id"]
        mf.addNote(track, channel, instr_midi_pitch[instr_name], qnote_time,
            event_dur, velocity)

    with open(file_name,'wb') as outf:
        mf.writeFile(outf)
