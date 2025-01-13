#ifndef BOARD_H
#define BOARD_H

#include "Square.h"

void initializeBoard(square board[8][8]);
void printBoard(square board[8][8]);
void movePiece(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter);

#endif

