#include "../include/Main.h"

int main()
{
	square board[8][8];
	initializeBoard(board);

	printWelcomeMessage();
	playGame(board);
}

void printWelcomeMessage()
{
	printf("Welcome to Chess!\n");
	printf("Players take turns to move pieces.\n");//NO AI YET
	printf("Enter your moves in the format: fromRow fromCol toRow toCol\n");
}

void playGame(square board[8][8])
{
	int currentPlayer = 1;
	bool gameRunning = true;

	while (gameRunning)
	{
		printBoard(board);

		if (isGameOver(board, currentPlayer))
		{
			printf("Player %d wins!\n", currentPlayer);
			gameRunning = false;
		}
		else
		{
			playerTurn(board, currentPlayer);
			currentPlayer *= -1;
		}
	}
}

void playerTurn(square board[8][8], int currentPlayer)
{
	int fromRow, fromCol, toRow, toCol;

	printf("Player %d's turn. Enter your move (fromRow fromCol toRow toCol):\n", currentPlayer);
	while (true)
	{
		if (scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol) != 4)
		{
			printf("Invalid input. Try again: ");
			while (getchar() != '\n')
				; // Clear input buffer
			continue;
		}

		if (isMoveLegal(board, fromRow, fromCol, toRow, toCol, currentPlayer))
		{
			movePiece(board, fromRow, fromCol, toRow, toCol);
			break;
		}
		else
		{
			printf("Invalid move. Try again: ");
		}
	}
}

bool isGameOver(square board[8][8], int currentPlayer)
{	
	if(checkMate(board,currentPlayer))return true;
	printf("Game end on %d turn\n",1);

	return false;
}