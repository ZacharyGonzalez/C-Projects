#ifndef VALID_CHECK_H
#define VALID_CHECK_H

#include <stdbool.h>
#include <stdlib.h>

#include "Board.h"
#include "Square.h"
#include "PieceAttack.h"
#include "PieceMovement.h"

bool isWithinBounds(int row, int col);
bool isSameColor(square board[8][8],int fromRow,int fromCol,int toRow, int toCol);
bool isPathClear(square board[8][8],int fromRow,int fromCol,int toRow, int toCol);
bool isKingInCheck(square board[8][8], int kingColor);
bool isSafeMove(square board[8][8],int toRow,int toCol, int KingColor);
bool isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int turnCounter);
int isMoveSafe(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, int playerColor);
int getCurrentPlayerColor(int turnCounter);

#endif
