#ifndef PIECE_LOGIC_H
#define PIECE_LOGIC_H

#include "../include/ValidCheck.h"

bool gameLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol);
bool pawnLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol);
bool rookLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol);
bool bishopLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol);
bool knightLogic(int fromRow, int fromCol, int toRow, int toCol);
bool queenLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol);
bool kingLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol);

#endif

