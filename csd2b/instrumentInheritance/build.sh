#! /bin/zsh

## build script for the instrument inheritance assignment

g++ -c main.cpp
g++ -c instrument.cpp
g++ -o instrument main.o instrument.o

