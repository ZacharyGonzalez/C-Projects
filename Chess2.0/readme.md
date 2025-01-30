# BETTER CHESS-CLI #
## Overview
For fun i wanted to make a chess, but while i was working on the original version i realized a better way to implement my systems and i made a new version from scratch. This version of chess uses unsigned 64bit integers to represent the board, to fasciliate 
movement on the board, and it is used to check for collisions for those movements. This is accomplished by using the outcomes of bitwise operations (xor,or,and). 
## How to Build
All you need to do is copy the files, and in a terminal at the directory with the make file type "make run". This will compile everything and also create their object files for inspection (typing make clean will delete everything created by make run)

## How to play
I did not implement a translation for the board movements, so an input of which row you want to select, and the which column within that row will be the selected piece. the following two numbers will be for where the selected piece moves too.

## Issues i have with this ##
i can make things better than they are, currently the algorithm for detecting collisions and how pieces can move is computationally tense, when i could make a bit-map of potential moves and then find the corresponding mvoe within that map and immediately determine
it's validity. That system would be significantly more useful for ML and an AI opponent as they will process information faster
