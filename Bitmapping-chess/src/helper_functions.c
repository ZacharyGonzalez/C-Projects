#include "../include/helper_functions.h"
bool is_within_bounds(int from_position, int to_position)
{
    bool valid = true;
    if ((from_position != to_position) && ((from_position >= 64 || to_position >= 64) || (from_position < 0 || to_position < 0)))
    {
        valid = false;
    }
    return valid;
}

bool correct_player_moving(board_state *state, int from_position, int current_player)
{
    int index=find_piece_index(state,from_position);
    return state->game_board[index][2] == current_player;
}


int find_piece_index(board_state *state, int position){
    int index = state->position_index[position];
    if (index== -1) {
        printf("no piece there\n");
    }
    printf("found piece %d (team %d) at position %d",
        state->game_board[index][1],
        state->game_board[index][2],
        state->game_board[index][0]
    );
    return index;
}
