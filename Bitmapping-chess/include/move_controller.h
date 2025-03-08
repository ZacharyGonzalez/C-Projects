#ifndef MOVE_CONTROLLER_H
#define MOVE_CONTROLLER_H
#include <stdbool.h>
#include <stdio.h>
#include "square.h"

void move_controller(square *board, board_state *state, int from_position, int to_position);
void move_piece(board_state *state, int from_position, int to_position);

#endif