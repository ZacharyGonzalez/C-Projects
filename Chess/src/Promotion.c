#include "Promotion.h"

void PromotePawn(square board[8][8],fromRow,fromCol){
	char choice;
	printf("Please select n,r,b, or q for Knight, Rook, Bishop, or Queen Respectively\n");
	if(scanf("%c",&choice) == 1){
		switch(choice){
			case('n'):board[fromRow][fromCol].piece='n';break;
			case('r'):board[fromRow][fromCol].piece='r';break;	
			case('b'):board[fromRow][fromCol].piece='b';break;
			case('q'):board[fromRow][fromCol].piece='q';break;
			default:printf("You must make a choice\n");PromotePawn(board,fromRow,fromCol);
		}
	}
} 
