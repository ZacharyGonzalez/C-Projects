#ifndef MAIN_H
#define MAIN_H

#include "../include/Board.h"
#include "../include/ValidCheck.h"
#include "../include/CheckMate.h"

void printWelcomeMessage();
void playGame(square board[8][8]);
bool isGameOver(/*square board[8][8], int currentPlayer*/);
void playerTurn(square board[8][8], int currentPlayer);

#endif
