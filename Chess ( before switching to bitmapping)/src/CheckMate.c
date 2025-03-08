#include "../include/CheckMate.h"

bool checkMate(square board[8][8], int kingTeamColor)
{
    if(!isKingInCheck(board,kingTeamColor))return false;
    int kingRow = -1, kingCol = -1, newRow = 0, newCol = 0;

    // get king position
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char piece = board[i][j].piece;
            int color = board[i][j].color;
            if (piece == 'k' && color == kingTeamColor)
            {
                kingRow = i, kingCol = j;
                break;
            }
        }
    }

    // can king move to safety
    int directions[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    for (int i = 0; i < 8; i++)
    {
        int dRow = directions[i][0], dCol = directions[i][1];
        newRow = kingRow + dRow;
        newCol = kingCol + dCol;
        if (!isWithinBounds(newRow, newCol))
            continue;
        if (isSafeKingMove(board, newRow, newCol, kingTeamColor))
            return false;
    }

    // if no piece can intercept, return true
    if (findThreat(board, kingRow, kingCol))
    {
        return true;
    }
    return false;
}
bool findThreat(square board[8][8], int row, int col){

    int threatRow = board[row][col].threateningPiecePosition[0];
    int threatCol = board[row][col].threateningPiecePosition[1];
        printf("Threat Piece: %d %d\n",threatRow,threatCol);


    if (board[threatRow][threatCol].threatened != board[threatRow][threatCol].color)
    {
        return false;
    }
    return true;
}
