#include <stdio.h>
#include "../include/Board.h"

void initializeBoard(square board[8][8]){
	//INSERT PIECES
	for (int row = 0; row < 8; row++) {
        	for (int col = 0; col < 8; col++) {
            		board[row][col].piece = ' ';
            		board[row][col].color = 0;
			board[row][col].value = 0;
        	}
    	}
	//PAWNS White and Black
	for (int i=0;i<8;i++){
		board[1][i].piece='p';
		board[1][i].value=1;
		board[1][i].color=1;
		board[6][i].piece='p';
		board[6][i].value=1;
		board[6][i].color=-1;
	}
	//ROOKS
	board[0][0].piece=board[0][7].piece='r';
	board[0][0].value=board[0][7].value=3;
	board[0][0].color=board[0][7].color=1;
	board[7][0].piece=board[7][7].piece='r';
	board[7][0].value=board[7][7].value=3;
	board[7][0].color=board[7][7].color=-1;
	//KNIGHTS
	board[0][1].piece=board[0][6].piece='n';
	board[0][1].value=board[0][6].value=5;
	board[0][1].color=board[0][6].color=1;
	board[7][1].piece=board[7][6].piece='n';
	board[7][1].value=board[7][6].value=5;
	board[7][1].color=board[7][6].color=-1;
	//BISHOPS
	board[0][2].piece=board[0][5].piece='b';
	board[0][2].value=board[0][5].value=4;
	board[0][2].color=board[0][5].color=1;
	board[7][2].piece=board[7][5].piece='b';
	board[7][2].value=board[7][5].value=4;
	board[7][2].color=board[7][5].color=-1;
	//QUEENS
	board[0][3].piece='q';
	board[0][3].value=7;
	board[0][3].color=1;
	board[7][3].piece='q';
	board[7][3].value=7;
	board[7][3].color=-1;
	//KINGS
	board[0][4].piece='k';
	board[0][4].value=7;
	board[0][4].color=1;
	board[7][4].piece='k';
	board[7][4].value=7;
	board[7][4].color=-1;

}


void printBoard(square board[8][8]){
	for(int row=7;row>=0;row--){//top of board
		printf("%d   ", row);
		for(int col=0;col<8;col++){//left of board
			if(board[row][col].piece == ' '){
				printf("[ ] ");
			}else{
				printf("[%c] ",board[row][col].piece);
			}
		}
		printf("\n\n");
	}
	printf("\n     0   1   2   3   4   5   6   7 \n");
}

void movePiece(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	//ADD WITHIN BOUNDS CHECK
	board[fromRow][fromCol].lastMove=*turnCounter;
	board[fromRow][fromCol].lastPiece=board[fromRow][fromCol].piece;
	board[toRow][toCol].piece = board[fromRow][fromCol].piece;
	board[toRow][toCol].value = board[fromRow][fromCol].value;
	board[toRow][toCol].color = board[fromRow][fromCol].color;

	board[fromRow][fromCol].piece = ' ';
	board[fromRow][fromCol].value = 0;
	board[fromRow][fromCol].color = 0;
	*turnCounter=*turnCounter+1;
}
