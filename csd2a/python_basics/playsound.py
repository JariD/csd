import simpleaudio as sa

n = int(input("hoe vaak wilt u afspelen?"))

wave_obj = sa.WaveObject.from_wave_file("/Users/jari/Documents/MUSIC/SAMPLES/Casio SA-10/WAV/Button_Select.wav")
for x in range(n):
    play_obj = wave_obj.play()
    play_obj.wait_done()
# Code from https://pypi.org/project/simpleaudio/j