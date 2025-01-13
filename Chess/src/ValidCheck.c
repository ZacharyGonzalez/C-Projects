#include "../include/ValidCheck.h"
#include <stdio.h>
bool isWithinBounds(int row, int col){
	return (row >= 0 && row < 8 && col >= 0 && col < 8);
}
bool isSameColor(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){
	return (board[fromRow][fromCol].color == board[toRow][toCol].color && board[fromRow][fromCol].color);
}
bool isPathBlocked(square board[8][8],int fromRow,int fromCol,int toRow, int toCol){

	int adaptiveCol=fromCol;
	int adaptiveRow=fromRow;
	int duration=((abs(fromRow-toRow)+abs(fromCol-toCol))/2)-1;
	printf("currRow:%d currCol:%d, duration:%d\n",adaptiveRow,adaptiveCol,duration);
	for(int i=0;i<duration;i++){
	printf("currRow:%d currCol:%d, toRow:%d toCol:%d\n",adaptiveRow,adaptiveCol,toRow,toCol);
		if(adaptiveCol-toCol < 0) adaptiveCol++;
		else if(adaptiveCol-toCol>0)adaptiveCol--;
		if(adaptiveRow-toRow < 0) adaptiveRow++;
		else if(adaptiveRow-toRow > 0) adaptiveRow--;
		if(board[adaptiveRow][adaptiveCol].color!=0){
		printf("adaptiveRow & Col before false: %d %d",adaptiveRow,adaptiveCol);
			return false;
		}
	}
	return true;
}

/*
Explanation of duration:
	we have already checked that either the row does change and the column does, or the 
*/
