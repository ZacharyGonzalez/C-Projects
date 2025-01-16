#include "../include/PieceMovement.h"
#include "../include/ValidCheck.h"
#include <stdbool.h>

/*
TODO i can make helper functions to simplify this all, like isLinearMovement so reduce repetitions

	The functions in this source file are all about validating a pieces move,IE checking diagonal squares for a bishop before accepting the move.
	
	turnCounter is passed from int main all the way through to movePiece, albeit i believe movePiece can just store that value and do a check then and there
*/

void gameLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
		char piece = board[fromRow][fromCol].piece;
		int color = board[fromRow][fromCol].color;
		if((*turnCounter%2 ==0 && color == 1) || (*turnCounter%2 !=0 && color == -1)){//correct player moves their piece
			switch(piece){
				case('p'):pawnLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('n'):knightLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('k'):kingLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('r'):rookLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('b'):bishopLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				case('q'):queenLogic(board,fromRow,fromCol,toRow,toCol,turnCounter);break;
				default:printf("The requested move is illegal gamelogic\n");
			}
		}
}

void pawnLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol, int *turnCounter){
	bool isValid=false;
	int direction = board[fromRow][fromCol].color; //either 1 for white or -1 for black (up or down)

	// forward movement of 1
	if(direction == (toRow-fromRow) || direction == (toRow-fromRow)){
		if(abs(toCol-fromCol) == 1){
			if (board[toRow][toCol].piece != ' ' && board[toRow][toCol].color != board[fromRow][fromCol].color) {
                isValid = true;
            }
		}else if(toCol==fromCol){
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	else if(abs(fromRow-toRow) == 2 && fromCol == toCol){ //First Double Movement Logic
		if(( direction == 1 && fromRow == 1 )|| ( direction == -1 && fromRow == 6) ){ 
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	if(isValid == true){
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}
}

void rookLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	bool isValid=false;

	if(fromRow == toRow && fromCol != toCol){//Horizontal Movement	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);	
	}
	
	if(fromCol == toCol && fromRow != toRow){//vertical Movement	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
	}
	if(isValid == true){
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}	
}


void bishopLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	bool isValid=false;
	if(fromRow != toRow && fromCol!=toCol){
		if(abs(fromRow-toRow) == abs(fromCol-toCol)){
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	if(isValid == true){
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}	
}

void knightLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	if(( abs(fromCol-toCol) == 2 && abs(fromRow-toRow) == 1) ||
	    (abs(fromRow-toRow) == 2 && abs(fromCol-toCol) == 1)) {
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}
}

void queenLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	bool isValid=false;

	if(fromRow != toRow && fromCol!=toCol){//diagonal movement
		if(abs(fromRow-toRow) == abs(fromCol-toCol)){
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	else{
		if(fromRow == toRow){//Horizontal Movement
		printf("horizontal hit\n");	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
		
		if(fromCol == toCol){//vertical Movement	
			printf("vertical hit\n");	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
		if(isValid == true){
			movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
		}	
}

void kingLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int *turnCounter){
	bool isValid=false;
	if ( abs(fromRow-toRow) <= 1 && abs(fromCol-toCol) <= 1 ){
		isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
	} 
	if(isValid == true && isSafeMove(board,toRow,toCol,board[fromRow][fromCol].color)){
		movePiece(board,fromRow,fromCol,toRow,toCol,turnCounter);
	}
}

