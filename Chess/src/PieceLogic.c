#include "../include/PieceLogic.h"
#include "../include/ValidCheck.h"
#include <stdbool.h>

void gameLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
		char piece = board[fromRow][fromCol].piece;
		int color =board[fromRow][fromCol].color;
		if((*turnCounter%2 ==0 && color == 1) || (*turnCounter%2 !=0 && color == -1)){//correct player moves their piece
			switch(piece){
				case('p'):pawnLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				//case('n'):knightLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				//case('k'):kingLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('r'):rookLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				//case('b'):bishopLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('q'):queenLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				default:printf("The requested move is illegal\n");
			}
		}
}

void pawnLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol, int *turnCounter){
	bool isValid=true;
	int direction = board[fromRow][fromCol].color; //either 1 for white or -1 for black (up or down)

	// this will be broken into a isPathBlocked()
	if(board[fromRow+direction][fromCol].color != 0 && fromCol == toCol){ //if infront is occupied and we are moving forwards
		printf("Path Blocked\n");
		isValid=false;
	}
	//pathblocked() end def
	
	if(abs(toCol-fromCol) > 1){		//THIS NEEDS TO BE FOR A CAPTURE OR ENPESSANT, so add an && attack()==false conditional to validate the move
		printf("moving too much sideways\n");
		isValid = false;
	}//moving too much to the side.
	if(abs(fromRow-toRow)==2&&fromCol==toCol){
		if(fromRow+direction == 2 || fromRow+direction == 5){ //First Double Movement

		}
		else{	
			printf("Can only move 2 squares on first pawn movement\n");
			isValid = false;
		}
	}
	if(isValid == true){
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}
}

void rookLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	bool isValid=true;
	int horizontalDirection=0,verticalDirection=0;//1 is positive movement, -1 is negative movement, 0 is stationary

	if(fromRow > toRow)verticalDirection=-1;//moving down
	if(fromRow < toRow)verticalDirection=1;//moving up
	if(fromCol > toCol)horizontalDirection=-1;//moving left
	if(fromCol < toCol)horizontalDirection=1;//moving right
	printf("\n\nhorizontal: %d     vertical:%d\n\n\n",horizontalDirection,verticalDirection);

	if(verticalDirection == 0){//Horizontal Movement	
		switch(horizontalDirection){
			case(1): {	
				for (int i=fromCol;i<toCol;i++){
					if(i==fromCol)continue;
					if(board[fromRow][i].color != 0){
						isValid=false;
						break;
					}				
			}break;}
			case(-1):{ 				
				for (int i=toCol;i<fromCol;i++){
					if(i==toCol)continue;
					if(board[fromRow][i].color != 0){
						isValid=false;
						break;
					}
			}break;}
		}	
	}
	
	if(horizontalDirection == 0){//vertical Movement	
		switch(verticalDirection){
			case(1): {	
				for (int i=fromRow;i<toRow;i++){
					if(i==fromRow)continue;
					if(board[i][fromCol].color != 0){
						isValid=false;
						break;
					}				
			}break;}
			case(-1):{ 				
				for (int i=toRow;i<fromRow;i++){//check above the target cell
					if(i==toRow)continue;
					if(board[i][fromCol].color != 0){
						isValid=false;
						break;
					}
			}break;}
		}	
	}
	if(horizontalDirection !=0 && verticalDirection!=0){isValid=false;}
	if(isValid == true){
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}	
}


//void bishopLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){

//}

//void knightLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){

//}
/*
bool isBlocked(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	int horizontalDirection=0,verticalDirection=0;//1 is positive movement, -1 is negative movement, 0 is stationary
	char piece=board[fromRow][fromCol].piece;
	if(fromRow > toRow)verticalDirection=-1;//moving down
	if(fromRow < toRow)verticalDirection=1;//moving up
	if(fromCol > toCol)horizontalDirection=-1;//moving left
	if(fromCol < toCol)horizontalDirection=1;//moving right1
	
	if(piece=='r' && horizontalDirection !=0)
	
	
}*/
void queenLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	bool isValid=false;
	int horizontalDirection=0,verticalDirection=0;//1 is positive movement, -1 is negative movement, 0 is stationary

	if(fromRow > toRow)verticalDirection=-1;//moving down
	if(fromRow < toRow)verticalDirection=1;//moving up
	if(fromCol > toCol)horizontalDirection=-1;//moving left
	if(fromCol < toCol)horizontalDirection=1;//moving right
	printf("\n\nhorizontal: %d     vertical:%d\n\n\n",horizontalDirection,verticalDirection);
	if(verticalDirection != 0 && horizontalDirection !=0){
		if(abs(fromRow-toRow) == abs(fromCol-toCol)){
			isValid=isPathBlocked(board,fromRow,fromCol,toRow,toCol);
		}
	}
	else{
		if(verticalDirection == 0){//Horizontal Movement
		printf("horizontal hit\n");	
			isValid=isPathBlocked(board,fromRow,fromCol,toRow,toCol);
		}
		
		if(horizontalDirection == 0){//vertical Movement	
			printf("vertical hit\n");	
			isValid=isPathBlocked(board,fromRow,fromCol,toRow,toCol);
		}
		if(horizontalDirection !=0 && verticalDirection!=0){ //This needs to be removed and this else section just done better
			isValid=false;
		}
	}
		if(isValid == true){
			movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
		}	
}

//void kingLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){

//}

