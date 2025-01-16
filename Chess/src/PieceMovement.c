#include "../include/PieceMovement.h"

/*
TODO i can make helper functions to simplify this all, like isLinearMovement so reduce repetitions

	The functions in this source file are all about validating a pieces move,IE checking diagonal squares for a bishop before accepting the move.

*/

bool gameLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
		char piece = board[fromRow][fromCol].piece;
		bool isValid=false;
		switch(piece){
			case('p'):isValid=pawnLogic(board,fromRow,fromCol,toRow,toCol);break;
			case('n'):isValid=knightLogic(fromRow,fromCol,toRow,toCol);break;
			case('k'):isValid=kingLogic(board,fromRow,fromCol,toRow,toCol);break;
			case('r'):isValid=rookLogic(board,fromRow,fromCol,toRow,toCol);break;
			case('b'):isValid=bishopLogic(board,fromRow,fromCol,toRow,toCol);break;
			case('q'):isValid=queenLogic(board,fromRow,fromCol,toRow,toCol);break;
			default: break;
		}
		return isValid;
}

bool pawnLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
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

	return isValid;
}

bool rookLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	bool isValid=false;

	if(fromRow == toRow && fromCol != toCol){//Horizontal Movement	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);	
	}
	
	if(fromCol == toCol && fromRow != toRow){//vertical Movement	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
	}
	return isValid;	
}


bool bishopLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	bool isValid=false;
	if(fromRow != toRow && fromCol!=toCol){
		if(abs(fromRow-toRow) == abs(fromCol-toCol)){
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	return isValid;		
}

bool knightLogic(int fromRow,int fromCol,int toRow, int toCol){
	bool isValid=false;
	if(( abs(fromCol-toCol) == 2 && abs(fromRow-toRow) == 1) ||
	    (abs(fromRow-toRow) == 2 && abs(fromCol-toCol) == 1)) {
		isValid=true;
	}
	return isValid;
}

bool queenLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	bool isValid=false;

	if(fromRow != toRow && fromCol!=toCol){//diagonal movement
		if(abs(fromRow-toRow) == abs(fromCol-toCol)){
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	else{
		if(fromRow == toRow){//Horizontal Movement
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
		
		if(fromCol == toCol){//vertical Movement	
			isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
		}
	}
	return isValid;
}

bool kingLogic(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	bool isValid=false;
	if ( abs(fromRow-toRow) <= 1 && abs(fromCol-toCol) <= 1 ){
		isValid=isPathClear(board,fromRow,fromCol,toRow,toCol);
	} 
	if(isValid == true && isSafeKingMove(board,toRow,toCol,board[fromRow][fromCol].color)){
		return true;
	}
	return false;
}

