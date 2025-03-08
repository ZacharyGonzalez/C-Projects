#include "../include/move_controller.h"
#include "../include/bit_controller.h"
#include "../include/helper_functions.h"

void move_controller(square *board, board_state *state, int from_position, int to_position)
{
    square *piece = &board[from_position];
    uint64_t move_mask = 1ULL << to_position;

    if (collision_controller(move_mask, state->all_pieces)) //can be capture or something
    {
        printf("collision detected\n");
    }

    uint64_t threat_map = generate_threat_map(board, piece->color);
    if (move_mask & threat_map)
    {
        printf("moving to a threatened square");
    }
    state->all_pieces ^= (1ULL << from_position) | (1ULL << to_position);
    //printBitsGrid(state->all_pieces);
    printf("\n\n\n COLOR %d\n\n",piece->color);
    if (piece->color == 1)
    {
        state->white_pieces ^= (1ULL << from_position) | (1ULL << to_position);
    }
    else if(piece->color == 0)
    {
        state->black_pieces ^= (1ULL << from_position) | (1ULL << to_position);    
    }
    move_piece(state, from_position, to_position);

    printf("move_mask: %ld \n", move_mask);

}


void move_piece(board_state *state, int from_position, int to_position)
{
    uint8_t index = find_piece_index(state, from_position);
    state->game_board[index][0]=to_position;
    state->position_index[from_position]=-1;
    state->position_index[to_position]=index;
}
