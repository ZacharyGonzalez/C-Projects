#ifndef PIECE_VALIDATION_H
#define PIECE_VALIDATION_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "square.h"
#include "helper_functions.h"

bool piece_validation(board_state *state, int from_position, int to_position);
bool rook_logic(int from_position, int to_position);
bool knight_logic(int from_position, int to_position);
bool bishop_logic(int from_position, int to_position);
bool queen_logic(int from_position, int to_position);
bool king_logic(int from_position, int to_position);
bool pawn_logic(board_state *state, int from_position, int to_position);

#endif
