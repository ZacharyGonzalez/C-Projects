#ifndef SQUARE_H
#define SQUARE_H

#include <stdint.h>

typedef struct {
	char piece; //p,r,k,b for pawn,rook,king,bishop, etc
	int color; //-1 for back, 0 for empty, 1 for white
	int value; //For learning Algorithm
	char threateningPiece;
	int threateningPiecePosition[2];
	int threatened;
	__uint64_t attackMap;
}square;

#endif
