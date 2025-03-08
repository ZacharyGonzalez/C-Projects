#include "../include/ValidCheck.h"
bool isWithinBounds(int row, int col)
{
	return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

bool isSameColor(square board[8][8], int fromRow, int fromCol, int toRow, int toCol)
{
	return (board[fromRow][fromCol].color == board[toRow][toCol].color);
}

bool isPathClear(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, bool checkMateFlag)
{
	int steppingCol = fromCol;
	int steppingRow = fromRow;
	//add bitmap here?
	while ((steppingCol != toCol || steppingRow != toRow))
	{

		if (steppingCol - toCol < 0)
			steppingCol++;
		else if (steppingCol - toCol > 0)
			steppingCol--;

		if (steppingRow - toRow < 0)
			steppingRow++;
		else if (steppingRow - toRow > 0)
			steppingRow--;

		if (checkMateFlag == true)
		{
			printf("%d %d | %d %d\n",fromRow,fromCol,steppingRow,steppingCol);
			if (board[steppingRow][steppingCol].threatened == board[toRow][toCol].color)
			{
				return false;
			}
		}
		if (board[steppingRow][steppingCol].color != 0)
		{
			break;
		}
	}
	if (steppingCol + steppingRow == toRow + toCol)
	{
		return true;
	}
	return false;
}

// is the king standing on a bad tile
bool isKingInCheck(square board[8][8], int kingColor)
{
	threatUpdate(board);
	int kingRow = -1, kingCol = -1;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (board[row][col].piece == 'k' && board[row][col].color == kingColor)
			{
				kingRow = row;
				kingCol = col;
				break;
			}
		}
		if (kingRow != -1)
			break;
	}

	return (board[kingRow][kingCol].threatened == board[kingRow][kingCol].color * -1);
}

// if the king moves, is it to a safe square
bool isSafeKingMove(square board[8][8], int toRow, int toCol, int kingTeamColor)
{

	int squareThreat = board[toRow][toCol].threatened;
	char piece = board[toRow][toCol].piece;


	if ((squareThreat == 0 || (squareThreat == kingTeamColor)) && piece == ' ')
	{
		return true;
	}

	return false;
}

int isMoveSafe(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, int playerColor)
{ // TODO this should be a bool func
	square tempBoard[8][8];
	CloneBoard(board, tempBoard);
	movePiece(tempBoard, fromRow, fromCol, toRow, toCol);
	threatUpdate(tempBoard);
	return !isKingInCheck(tempBoard, playerColor); // Check if king remains safe
}

bool isMoveLegal(square board[8][8], int fromRow, int fromCol, int toRow, int toCol, int playerColor)
{

	int pieceColor = board[fromRow][fromCol].color;

	if (playerColor != pieceColor)
	{
		printf("%d moving a %d piece\n", playerColor, pieceColor);
		return false;
	}

	if (!isWithinBounds(fromRow, fromCol) || !isWithinBounds(toRow, toCol))
	{
		printf("Move is out of bounds\n");
		return false;
	}

	if (isSameColor(board, fromRow, fromCol, toRow, toCol))
	{ // TODO This prevents Castling
		printf("Move is on own piece\n");
		return false;
	}

	if (!isMoveSafe(board, fromRow, fromCol, toRow, toCol, playerColor))
	{ // Branches out into many other functions
		printf("Move leaves the king in check\n");
		return false;
	}

	return gameLogic(board, fromRow, fromCol, toRow, toCol);
}

int getCurrentPlayerColor(int turnCounter)
{
	return (turnCounter % 2 == 0) ? 1 : -1; // 1 for white(even), -1 for black(odd)
}
