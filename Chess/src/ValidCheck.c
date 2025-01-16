#include "../include/ValidCheck.h"
bool isWithinBounds(int row, int col){
	return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

bool isSameColor(square board[8][8], int fromRow, int fromCol, int toRow, int toCol){
	return (board[fromRow][fromCol].color == board[toRow][toCol].color);
}

bool isPathClear(square board[8][8], int fromRow, int fromCol, int toRow, int toCol){ 
	int steppingCol=fromCol;
	int steppingRow=fromRow;

	while((steppingCol != toCol || steppingRow != toRow)){

		if(steppingCol-toCol < 0) steppingCol++;
		else if(steppingCol-toCol>0)steppingCol--;
		
		if(steppingRow-toRow < 0) steppingRow++;
		else if(steppingRow-toRow > 0) steppingRow--;
		
		if(board[steppingRow][steppingCol].color!=0){
			break;
		}
	}
	if (steppingCol+steppingRow == toRow+toCol){ 
		return true;
	}
	return false;
}

//is the king standing on a bad tile
bool isKingInCheck(square board[8][8], int kingColor){
	threatUpdate(board);
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
	
    return (board[kingRow][kingCol].threatened == board[kingRow][kingCol].color * -1);
}

//if the king moves, is it to a safe square
bool isSafeKingMove(square board[8][8], int toRow, int toCol, int kingTeamColor) { 

	int squareThreat = board[toRow][toCol].threatened;

	if (squareThreat == 0  || (squareThreat == kingTeamColor)) {
		return true;
	}
	
	return false;
}
 
int isMoveSafe(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, int playerColor) { //TODO this should be a bool func
	square tempBoard[8][8];
	CloneBoard(board, tempBoard);
	movePiece(tempBoard, fromRow, fromCol, toRow, toCol);
	threatUpdate(tempBoard);  
	return !isKingInCheck(tempBoard, playerColor); //Check if king remains safe
}

bool isMoveLegal(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, int playerColor){

	int pieceColor = board[fromRow][fromCol].color;

	if (playerColor != pieceColor){
		printf("%d moving a %d piece\n",playerColor,pieceColor);
		return false;
	}
	
	if (!isWithinBounds(fromRow,fromCol) || !isWithinBounds(toRow,toCol)){
		printf("Move is out of bounds\n");
		return false;
	}
	
	if(isSameColor(board,fromRow,fromCol,toRow,toCol)){ //TODO This prevents Castling
		printf("Move is on own piece\n");
		return false;
	}
	
	if (!isMoveSafe(board, fromRow, fromCol, toRow, toCol, playerColor)) { //Branches out into many other functions
	        printf("Move leaves the king in check\n");
	        return false;
	}

	return 	gameLogic(board,fromRow,fromCol,toRow,toCol);
}
bool findThreat(square board[8][8],int kingRow,int kingCol,threatPiece){
	switch(threatPiece){
	case('n'):findKnight(board,row,col);break;
	case('b'):findBishop(board,row,col);break;
	case('q'):findQueen(board,row,col);break;
	case('r'):findRook(board,row,col);break;
	case('p'):findPawn(board,row,col);break;
	default: break;
	}
}
bool isCheckMate(square board[8][8],int kingTeamColor){
	int kingRow=-1,kingCol=-1,newRow=0,newCol=0;
	//get king position
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			char piece = board[i][j].piece;
			int color = board[i][j].color;
			if (piece == 'k' && color == kingTeamColor){
				kingRow=i, kingCol=j;
				break;
			}
		}
	}
	//can king move to safety
	int directions[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
	for(int i=0;i<8;i++){
		int dRow = directions[i][0], dCol = directions[i][1];
		newRow = kingRow + dRow;
		newCol = kingCol + dCol;
		if (!isWithinBounds(newRow, newCol)) continue;
		if(isSafeKingMove(board,newRow,newCol,kingTeamColor))return false;
	}
	
	//if no piece can intercept, return true
	threateningPiece=board[kingRow][kingCol].threateningPiece;
	findThreat(board,row,col,threateningPiece);
	return true;

}

int getCurrentPlayerColor(int turnCounter) {
    return (turnCounter % 2 == 0) ? 1 : -1; // 1 for white(even), -1 for black(odd)
}


