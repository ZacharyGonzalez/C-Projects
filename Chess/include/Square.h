#ifndef SQUARE_H
#define SQUARE_H

typedef struct {
	char piece; //p,r,k,b for pawn,rook,king,bishop, etc
	int color; //-1 for back, 0 for empty, 1 for white
	int value; //For learning Algorithm
	int lastMove;
	char lastPiece;
	int threatened;
}square;

#endif
