#include <stdio.h>

#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/ValidCheck.h"
#include "../include/PieceLogic.h"

void isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter);


int main (){
	int row,col,row2,col2,game=0;
	square board[8][8];
	initializeBoard(board);
	int *turnCounter=malloc(sizeof(int));
	if(turnCounter==NULL)exit(1);
	else *turnCounter=0;
	while(game!=1){
		printBoard(board);
		printf("Move which piece to where? (from square: row col | to Square:row col)\n");
		if(scanf("%d %d %d %d",&row,&col,&row2,&col2) == 4){
			isMoveLegal(board,row,col,row2,col2,turnCounter);
			printf("\n\n%d\n\n",*turnCounter);
		}else printf("you did not enter enough parameters, try again \n");
	}
}

void isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	if (isWithinBounds(fromRow,fromCol) && isWithinBounds(toRow,toCol) && !isSameColor(board,fromRow,fromCol,toRow,toCol)){
		gameLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);	
	}
	else printf("The requested move is not valid\n");
}

