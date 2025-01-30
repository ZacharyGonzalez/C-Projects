#include "../include/piece_validation.h"
#include "../include/helper_functions.h"
bool piece_validation(board_state *state, int from_position, int to_position)
{
    bool valid = false;

    // would this move put own king in check(take the moving piece, use the queen collision but this time pretend this piece is invisible, if the enemy teams attack map can now hit our king, return false)

    // determing piece being moved by going either to the baord position in the array or by looking at the board table.
    int moving_piece=state->game_board[find_piece_index(state,from_position)][1];

    // navigate to piece logic
    switch (moving_piece)
    {
    case (4):
        valid = rook_logic(from_position, to_position);
        break;
    case (5):
        valid = knight_logic(from_position, to_position);
        break;

    case (3):
        valid = bishop_logic(from_position, to_position);
        break;

    case (6):
        valid = queen_logic(from_position, to_position);
        break;

    case (9):
        valid = king_logic(from_position, to_position);
        break;

    case (1):
        valid = pawn_logic(state, from_position, to_position);
        break;
    }

    // if successful, navigate the move to the move_controller(pass the board, start,position, end position)
    return valid;
}

bool rook_logic(int from_position, int to_position)
{
    bool valid = false;
    int difference = from_position - to_position;

    // a vertical move
    if (difference % 8 == 0)
    {
        valid = true;
    }
    // same row
    if (from_position / 8 == to_position / 8)
    {
        valid = true;
    }
    return valid;
}
bool knight_logic(int from_position, int to_position)
{
    int from_row = from_position / 8;
    int from_col = from_position % 8;
    int to_row = to_position / 8;
    int to_col = to_position % 8;

    int row_diff = abs(to_row - from_row);
    int col_diff = abs(to_col - from_col);

    // A valid knight move is either:
    // - Two rows and one column
    // - One row and two columns
    return (row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2);
}
bool bishop_logic(int from_position, int to_position)
{
    bool valid = false;
    int from_row = from_position / 8;
    int from_col = from_position % 8;
    int to_row = to_position / 8;
    int to_col = to_position % 8;

    int row_diff = abs(to_row - from_row);
    int col_diff = abs(to_col - from_col);

    if (row_diff == col_diff)
    {
        valid = true;
    }
    return valid;
}
bool queen_logic(int from_position, int to_position)
{

    return (bishop_logic(from_position, to_position) || rook_logic(from_position, to_position));
}
bool king_logic(int from_position, int to_position)
{
    bool valid = false;
    int from_row = from_position / 8;
    int from_col = from_position % 8;
    int to_row = to_position / 8;
    int to_col = to_position % 8;

    int row_diff = abs(to_row - from_row);
    int col_diff = abs(to_col - from_col);

    if (row_diff <= 1 && col_diff <= 1)
    {
        valid = true;
    }
    return valid;
}
bool pawn_logic(board_state *state, int from_position, int to_position) //TODO diagonal threshold and only for capture
{
    printf("%d %d\n", from_position, to_position);
    bool valid = false;
    int direction = state->game_board[from_position][2];

    int from_row = from_position / 8;
   // int from_col = from_position % 8;
    int to_row = to_position / 8;
   // int to_col = to_position % 8;

   // int row_diff = to_row - from_row;
    //int col_diff = to_col - from_col;

    if (direction == 1)
    {
        if (to_row - from_row == 2 && from_row == 1)
        {
            valid = true;
        }
        else if (to_row - from_row == 1)
        {
            valid = true;
        }
    }
    if (direction == 0)
    {
        if (from_row - to_row == 2 && from_row == 6)
        {
            valid = true;
        }
        else if (from_row - to_row == 1)
        {
            valid = true;
        }
    }
    return valid;
}