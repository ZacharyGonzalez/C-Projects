#include "PieceAttack.h"
#include "ThreatUpdate.h"
#include "ValidCheck.h"
#include <stdio.h>

void threatUpdate(square board[8][8]){
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			board[i][j].threatened=0;//reset current board
		}
	}
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (board[i][j].piece != ' ') {
			    attackRange(board, i, j);
			}
		}
	}
	if(isKingInCheck(board,-1)){
		printf("Black King in Check\n");
	}
	if(isKingInCheck(board,1)){
		printf("White King in Check\n");
	}
	
}
