# CHESS-CLI#
## Overview
Just for fun, I wanted to make a board game I rarely play and only use C standard libraries. I also only had a few hours every couple of days to work on this; in total i spent about six hours on this version of chess that i was writting before changing to the "Chess 2.0" version which is a better system.

## How to Build
All you need to do is copy the files, and in a terminal at the directory with the make file type "make run". This will compile everything and also create their object files for inspection (typing make clean will delete everything created by make run)

## How to play
I did not implement a translation for the board movements, so an input of which row you want to select, and the which column within that row will be the selected piece. the following two numbers will be for where the selected piece moves too.
