#include "../include/board.h"
void initialtize_board(square *board)
{
    // specialUnits()

    board->value = 4; // rook
    board->color = 1;
    board++;    

    board->value = 5; // knight
    board->color = 1;
    board++;

    board->value = 3; // bishop
    board->color = 1;
    board++;

    board->value = 6; // queen
    board->color = 1;
    board++;

    board->value = 9; // king
    board->color = 1;
    board++;

    board->value = 3; // bishop
    board->color = 1;
    board++;

    board->value = 5; // knight
    board->color = 1;
    board++;

    board->value = 4; // rook
    board->color = 1;
    board++;

    // pawnUnits()
    for (int i = 0; i < 8; i++)
    {
        board->value = 1;
        board->color = 1;
        board++;
    }
    for (int i = 0; i < 32; i++)
    {
        board->value = 0;
        board++;
    }
    // pawnUnits()
    for (int i = 0; i < 8; i++)
    {
        board->value = 1;
        board->color = 0;
        board++;
    }
    board->value = 4; // rook
    board->color = 0;

    board++;

    board->value = 5; // knight
    board->color = 0;

    board++;

    board->value = 3; // bishop
    board->color = 0;

    board++;

    board->value = 6; // queen
    board->color = 0;

    board++;

    board->value = 9; // king
    board->color = 0;

    board++;

    board->value = 3; // bishop
    board->color = 0;

    board++;

    board->value = 5; // knight
    board->color = 0;

    board++;

    board->value = 4; // rook
    board->color = 0;
}

char get_piece_symbol(uint8_t value) {
    switch (value) {
        case 1: return 'P'; // Pawn
        case 3: return 'B'; // Bishop
        case 4: return 'R'; // Rook
        case 5: return 'N'; // Knight
        case 6: return 'Q'; // Queen
        case 9: return 'K'; // King
        default: return '.'; // Empty
    }
}

void print_board(square *board) {
    for (int row = 7; row >= 0; row--) {
        for (int col = 0; col < 8; col++) {
            int index = row * 8 + col;
            char symbol = get_piece_symbol(board[index].value);
            printf(" %c ", symbol);
        }
        printf("\n");
    }
}

void initialize_state(board_state *state, square *board)
{
    for (int i = 0; i < 64; i++)
    {   
        state->position_index[i]= -1;
    }
    for (int i=0; i<32; i++){
        int position = i<16 ? i: i+32;
        state->game_board[i][0]=position;
        state->game_board[i][1]=board[position].value;
        state->game_board[i][2]=board[position].color;  
        state->position_index[position] = i;
        if(i<16) state->white_pieces |= (1ULL <<(position));
        else state->black_pieces |= (1ULL <<(position));
    }
    state->all_pieces |= state->white_pieces & state->black_pieces;
}

void printBitsGrid(uint64_t num)
{
    for (int row = 7; row >= 0; row--) // start from the bottom row
    {
        for (int col = 0; col < 8; col++)
        {
            int index = row * 8 + col; 
            int bit = (num >> index) & 1;

            printf(" %d ", bit);
        }
        printf("\n");
    }
}
