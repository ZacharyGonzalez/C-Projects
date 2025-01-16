#include <stdio.h>

#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/ValidCheck.h" //for isMoveLegal
#include "../include/PieceAttack.h" //for threatUpdate

bool isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int turnCounter);

int main(){

	int fromRow,fromCol,toRow,toCol,game=0;
	square board[8][8];
	initializeBoard(board);
	int turnCounter=0;
	
	while(game!=1){//TODO Temp loop to keep game going
		threatUpdate(board); 
		printBoard(board);
		printf("Move which piece to where? (from square: row col | to Square:row col %d)\n",turnCounter);
		if(scanf("%d %d %d %d",&fromRow,&fromCol,&toRow,&toCol) == 4){
			if(isMoveLegal(board,fromRow,fromCol,toRow,toCol,turnCounter)){
				movePiece(board,fromRow,fromCol,toRow,toCol);
				turnCounter=turnCounter+1;
			}			
		}
		else printf("you did not enter enough parameters, try again \n");
	}
}


