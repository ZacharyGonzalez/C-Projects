#include "../include/ValidCheck.h"
#include <stdio.h>
bool isWithinBounds(int row, int col){
	return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

bool isSameColor(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	return (board[fromRow][fromCol].color == board[toRow][toCol].color && board[fromRow][fromCol].color);
}

bool isPathClear(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){ 
	int steppingCol=fromCol;
	int steppingRow=fromRow;

	/*
	these stepping variables dont need to know the direction they are moving too, the previous piecelogic checks should guarantee that any
	entry to this function is already validated beyond what this function is checking for.
	 */
	while((steppingCol != toCol || steppingRow != toRow)){
		printf("current Col: %d\n",steppingCol);
		if(steppingCol-toCol < 0) steppingCol++;
		else if(steppingCol-toCol>0)steppingCol--;
		printf("current Row: %d\n",steppingRow);
		if(steppingRow-toRow < 0) steppingRow++;
		else if(steppingRow-toRow > 0) steppingRow--;
		
		if(board[steppingRow][steppingCol].color!=0){
			break;
		}
	}
	if (steppingCol+steppingRow==toRow+toCol){ // this works because of the previous if statements going till the rows and cols are equivalent. An early break means a blocked path.
		return true;
	}
	return false;
}
//TODO a singular runthrough the array should be able to pass this function the kings position while accomplishing other tasks, this is currently inefficient
bool isKingInCheck(square board[8][8], int kingColor){
	int kingRow = -1,kingCol = -1;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
		    if (board[row][col].piece == 'k' && board[row][col].color == kingColor) {
		        kingRow = row;
		        kingCol = col;
		        break;
		    }
		}
	if (kingRow != -1) break;
	}
	
    return board[kingRow][kingCol].threatened == board[kingRow][kingCol].color * -1;//not equal doesnt work cause 0 case
}

bool isSafeMove(square board[8][8], int toRow, int toCol, int kingColor) { //SPECIFICALLY FOR THE KING

    if (board[toRow][toCol].threatened ==0  || 
        (board[toRow][toCol].threatened == kingColor)) {
        return true;
    }

    return false;
}

int isMoveSafe(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, int playerColor) {
	square tempBoard[8][8];
	CloneBoard(board, tempBoard);
	movePiece(tempBoard, fromRow, fromCol, toRow, toCol);
	threatUpdate(tempBoard);  
	return !isKingInCheck(tempBoard, playerColor); // Check if king remains safe
}

//gameLogic continues to evaluvate if the move is legal for the specific piece
bool isMoveLegal(square board[8][8],int fromRow,int fromCol,int toRow, int toCol,int turnCounter){

	int pieceColor=board[fromRow][fromCol].color;
	int playerColor = getCurrentPlayerColor(turnCounter);
	
	if (playerColor!=pieceColor){
		printf("%d moving a %d piece\n",playerColor,pieceColor);
		return false;
	}
	if (!isWithinBounds(fromRow,fromCol) || !isWithinBounds(toRow,toCol)){
		printf("Move is out of bounds\n");
		return false;
	}
	
	if(isSameColor(board,fromRow,fromCol,toRow,toCol)){
		printf("Move is on own piece\n");
		return false;
	}
	

	if (!isMoveSafe(board, fromRow, fromCol, toRow, toCol, playerColor)) {
	        printf("Move leaves the king in check\n");
	        return false;
	}

	return 	gameLogic(board,fromRow,fromCol,toRow,toCol);
}

int getCurrentPlayerColor(int turnCounter) {
    return (turnCounter % 2 == 0) ? 1 : -1; // 1 for white(even), -1 for black(odd) //if i feel the need to comment what it does for others to understand, should i even code like that
}

