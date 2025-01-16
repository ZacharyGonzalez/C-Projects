#ifndef PIECE_ATTACK_H
#define PIECE_ATTACK_H

#include "../include/ValidCheck.h"

void threatUpdate(square board[8][8]);
void attackRange(square board[8][8],int row, int col);
void pawnAttack(square board[8][8],int row,int col);
void knightAttack(square board[8][8],int row,int col);
void kingAttack(square board[8][8],int row,int col);
void rookAttack(square board[8][8],int row,int col);
void bishopAttack(square board[8][8],int row,int col);
void queenAttack(square board[8][8],int row,int col);

#endif
