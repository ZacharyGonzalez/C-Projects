#ifndef BIT_CONTROLLER_H
#define BIT_CONTROLLER_H

#include <stdio.h>
#include "square.h"


bool collision_controller(uint64_t move_mask, uint64_t piece_bitmap);
uint64_t generate_threat_map(square *board, int color);
uint64_t bishop_moves(int position);
uint64_t rook_moves(int position);
uint64_t pawn_moves(int position,int color);
uint64_t queen_moves(int position);
uint64_t king_moves(int position);
uint64_t knight_moves(int position);

#endif