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
	these stepping variables dont need to know the direction they are moving too, they just check if the move is within bounds and the previous piecelogic checks should guarantee that any
	entry to this function is already validated beyond what his function is checking for.
	 */
	while((steppingCol != toCol || steppingRow != toRow)){
	
		if(steppingCol-toCol < 0) steppingCol++;
		else if(steppingCol-toCol>0)steppingCol--;
		
		if(steppingRow-toRow < 0) steppingRow++;
		else if(steppingRow-toRow > 0) steppingRow--;
		
		if(board[steppingRow][steppingCol].color!=0){
			return false;
		}
	}
	return true;
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

bool isSafeMove(square board[8][8], int toRow, int toCol, int kingColor) {

    if (board[toRow][toCol].threatened ==0  || 
        (board[toRow][toCol].threatened == kingColor)) {
        return true;
    }

    return false;
}

