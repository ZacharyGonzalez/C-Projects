#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include "square.h"

bool is_within_bounds(int from_position, int to_positions);
bool correct_player_moving(board_state *state,int from_position, int current_player);

#endif