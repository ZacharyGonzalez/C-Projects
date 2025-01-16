#include <stdio.h>

#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/ValidCheck.h"
#include "../include/PieceMovement.h"
#include "../include/PieceAttack.h"

void isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter);

int playGame(){
	int row,col,row2,col2,game=0;
	square board[8][8];
	initializeBoard(board);
	int *turnCounter=malloc(sizeof(int));
	if(turnCounter==NULL)exit(1);
	*turnCounter=0;
	
	while(game!=1){
		threatUpdate(board); //what pieces can be captured and is either king in check
		printBoard(board);
		printf("Move which piece to where? (from square: row col | to Square:row col)\n");
		
		if(scanf("%d %d %d %d",&row,&col,&row2,&col2) == 4){
			isMoveLegal(board,row,col,row2,col2,turnCounter);
		}
		
		else printf("you did not enter enough parameters, try again \n");
	}
}

//gameLogic continues to evaluvate if the move is legal for the specific piece
void isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	if (isWithinBounds(fromRow,fromCol) && isWithinBounds(toRow,toCol) && !isSameColor(board,fromRow,fromCol,toRow,toCol)){
		gameLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}
	else printf("The requested move is not valid\n");
}
