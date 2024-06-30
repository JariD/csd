#pragma once

class Effect {
public:
  Effect();
  virtual ~Effect();

  void processSignal(const float &input, float &output, int channel);
  virtual void prepare(int sampleRate) { };
  // setters
  void setDryWet(float dryWet);

protected:
  virtual void applyEffect(const float &input, float &output, int channel) = 0;
  int channels;

private:
  float dryVolume;
  float wetVolume;
};
