#ifndef PIECE_LOGIC_H
#define PIECE_LOGIC_H

#include <stdlib.h>
#include <stdio.h>
#include "Square.h"
#include "Board.h"

void gameLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter);
void pawnLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol,int *turnCounter);
void rookLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol,int *turnCounter);
void bishopLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol,int *turnCounter);
void knightLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol,int *turnCounter);
void queenLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol,int *turnCounter);
void kingLogic(square board[8][8], int fromRow, int fromCol, int toRow, int toCol,int *turnCounter);

#endif

