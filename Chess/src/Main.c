#include <stdio.h>

#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/ValidCheck.h"
#include "../include/PieceMovement.h"
#include "../include/PieceAttack.h"
#include "../include/ThreatUpdate.h"

void isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter);

int main(){

	int fromRow,fromCol,toRow,toCol,game=0;
	square board[8][8];
	initializeBoard(board);

	int *turnCounter=malloc(sizeof(int));
	if(turnCounter==NULL)exit(1);
	*turnCounter=0;
	
	while(game!=1){//TODO Temp loop to keep game going
		threatUpdate(board); 
		printBoard(board);
		printf("Move which piece to where? (from square: row col | to Square:row col)\n");
		
		if(scanf("%d %d %d %d",&fromRow,&fromCol,&toRow,&toCol) == 4){
			isMoveLegal(board,fromRow,fromCol,toRow,toCol,turnCounter);
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

//can detect when king is in check, we know which king is in check, we have the board state and we know where the king can move to. Can we determine 
