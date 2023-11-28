#! /bin/zsh

## build script for synth

g++ -c main.cpp
g++ -c oscillator.cpp
g++ -o synth main.o oscillator.o