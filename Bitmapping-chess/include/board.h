#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include "square.h"

void print_board(square *board);
void printBitsGrid(uint64_t num);

void initialtize_board(square *board);
void initialize_state(board_state *state,square *board);


#endif

