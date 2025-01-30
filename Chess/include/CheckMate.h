#ifndef CHECKMATE_H
#define CHECKMATE_H

#include "ValidCheck.h"

bool checkMate(square board[8][8],int kingTeamColor);
bool findThreat(square board[8][8],int row,int col);

#endif

