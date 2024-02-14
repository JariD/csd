#pragma once

//Code parts from class
class Effect
{
public:
    Effect(float dryWet = 1.0);
    virtual ~Effect();
    float processFrame(float input);
    virtual void prepare(float rate) {};
    void setDryWet(float dryWet);

protected:
    virtual float applyEffect(float input) = 0; //abstract
private:
    float dry;
    float wet;
};