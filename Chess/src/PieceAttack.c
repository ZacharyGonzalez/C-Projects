#include "../include/PieceAttack.h"
#include "../include/ValidCheck.h"
#include <stdio.h>

void attackRange(square board[8][8],int row, int col){ //TODO add knight & pawn attack check  
	char piece = board[row][col].piece; //piece that is attacking
	char color = board[row][col].color;
	
	// Horizontal & Vertical Attack Range 
	if(piece=='r'||piece=='q'){	
		int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int d = 0; d < 4; d++) {
			int dx = directions[d][0], dy = directions[d][1];
				for (int steps = 1; steps < 8; steps++) {
					int newRow = row + steps * dx, newCol = col + steps * dy;
					if (!isWithinBounds(newRow, newCol)) break;
					if (board[newRow][newCol].piece != ' ') {
						if (board[newRow][newCol].color != color){
							board[newRow][newCol].threatened = color;
						}
				   		break; // Stop if a piece is encountered.
					}
					board[newRow][newCol].threatened = color;
		    		}	
		}
	}
	
	//Diagonal Attack Range
	if(piece=='b'||piece=='q'){	
		int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
		for (int d = 0; d < 4; d++) {
		    int dRow = directions[d][0], dCol = directions[d][1];
		    for (int steps = 1; steps < 8; steps++) {
			int newRow = row + steps * dRow, newCol = col + steps * dCol;
			if (!isWithinBounds(newRow, newCol)) break;
			if (board[newRow][newCol].piece != ' ') {
			    if (board[newRow][newCol].color != color) {
				board[newRow][newCol].threatened = color;
			}
			    break; // Stop if a piece is encountered.
			}
			board[newRow][newCol].threatened = color;
		    }
		}
	}
	if(piece == 'n'){

		int directions[8][2]={{2,-1},{2,1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
		for (int d = 0; d < 8; d++) {
			int dx = directions[d][0], dy = directions[d][1];
			int newRow = row + dx, newCol = col + dy;
			if (!isWithinBounds(newRow, newCol)) break;
			if (board[newRow][newCol].piece != ' ') {
			    if (board[newRow][newCol].color != color) {
				board[newRow][newCol].threatened = color;
			}
			    break; // Stop if a piece is encountered.
			}
			board[newRow][newCol].threatened = color;
		    }
	}
}
//i love going through the board 4 times in one function, truely remarkable
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

