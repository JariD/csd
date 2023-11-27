#! /bin/zsh

## build script for the instrument inheritance assignment

g++ -c main.cpp
g++ -c instrument.cpp
g++ -c violin.cpp
g++ -c guitar.cpp
g++ -o instrument main.o instrument.o violin.o guitar.o

