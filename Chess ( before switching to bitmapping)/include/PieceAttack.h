#ifndef PIECE_ATTACK_H
#define PIECE_ATTACK_H

#include "../include/ValidCheck.h"
#include <stdint.h>

void threatUpdate(square board[8][8]);
void attackRange(square board[8][8],int row, int col);
void calculateAttackRange(square board[8][8], int row, int col, int moveCount, int dRow, int dCol);

#endif
