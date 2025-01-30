#include "../include/PieceAttack.h"
#include <stdint.h>
// TODO flip a flag to enable check and check for checkmate

void calculateAttackRange(square board[8][8], int row, int col, int moveCount, int dRow, int dCol)
{
	char color = board[row][col].color;
	
	for (int steps = 1; steps < moveCount; steps++)
	{
		int newRow = row + steps * dRow, newCol = col + steps * dCol;
		uint8_t bitPosition=8*newRow+newCol;
		printf("%hu\n",bitPosition);
		if (!isWithinBounds(newRow, newCol))
			continue;
		if (board[newRow][newCol].piece != ' ')
		{
			if (board[newRow][newCol].color != color)

			{	
				board[newRow][newCol].threatened = color;
				board[newRow][newCol].threateningPiecePosition[0]=row;
				board[newRow][newCol].threateningPiecePosition[1]=col;
			}
			break; // Stop if a piece is encountered.
		}
		board[newRow][newCol].threatened = color;
	}
}

void attackRange(square board[8][8], int row, int col)
{
	char attackingPiece = board[row][col].piece;
	char color = board[row][col].color;

	// Horizontal & Vertical Attack Range
	if (attackingPiece == 'r' || attackingPiece == 'q')
	{
		int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int d = 0; d < 4; d++)
		{
			int dRow = directions[d][0], dCol = directions[d][1];
			calculateAttackRange(board, row, col, 4, dRow, dCol);
		}
	}

	// Diagonal Attack Range
	if (attackingPiece == 'b' || attackingPiece == 'q')
	{
		int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
		for (int d = 0; d < 4; d++)
		{
			int dRow = directions[d][0], dCol = directions[d][1];
			calculateAttackRange(board, row, col, 4, dRow, dCol);
		}
	}
	// Knight attacks; yes its a repeat of the calculateAttackRange, i unfortunately dont see how to make a universal function for them.. TODO
	if (attackingPiece == 'n')
	{
		int directions[8][2] = {{2, -1}, {2, 1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
		for (int d = 0; d < 8; d++)
		{
			int dRow = directions[d][0], dCol = directions[d][1];
			int newRow = row + dRow, newCol = col + dCol;
			if (!isWithinBounds(newRow, newCol))
				continue;
			board[newRow][newCol].threatened = color;
		}
	}
	if (attackingPiece == 'p')
	{
		int directions[2][2];
		if (color == 1)
		{
			directions[0][0] = 1;
			directions[0][1] = -1;
			directions[1][0] = 1;
			directions[1][1] = 1;
		}
		else
		{
			directions[0][0] = -1;
			directions[0][1] = -1;
			directions[1][0] = -1;
			directions[1][1] = 1;
		}
		for (int d = 0; d < 2; d++)
		{
			int dRow = directions[d][0], dCol = directions[d][1];
			calculateAttackRange(board, row, col, 2, dRow, dCol);
		}
	}
}

void threatUpdate(square board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].threatened = 0; // reset current board
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j].piece != ' ')
			{
				attackRange(board, i, j);
			}
		}
	}
}
