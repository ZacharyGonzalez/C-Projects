#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/board.h"
#include "../include/piece_validation.h"
#include "../include/move_controller.h"
#include "../include/attack_controller.h"
#include "../include/helper_functions.h"

void greetings();
void start_game(square *board, board_state *state);

#include <stdio.h>


int main()
{

    greetings();
    square *board = malloc(sizeof(square) * 64); // 64 squares to a board, 0 being the start. 63 being the last square.
    board_state *state = malloc(sizeof(board_state));
    if (state == NULL || board == NULL)
        exit(1);
    initialtize_board(board);
    initialize_state(state,board);
    start_game(board, state);
}
void print_state(board_state *state){
    for (int i=0;i<32;i++){
        printf("pos %hu, piece %hu, team %hu \n",state->game_board[i][0],state->game_board[i][1],state->game_board[i][2]);
    }

}
void print_full_game(square *board, board_state *state){
    for (int i=0;i<32;i++){
        board[state->game_board[i][0]].value=state->game_board[i][1];
        board[state->game_board[i][0]].color=state->game_board[i][2];
    }
    print_board(board);
}

void start_game(square *board, board_state *state)
{
    int current_player = 1;
    int from_row, from_col, to_row, to_col;
    while (true)
    {
        print_board(board);
        print_state(state);
        print_full_game(board,state);
        printf("Player %d's turn. Enter your move (fromRow fromCol toRow toCol):\n", current_player);
        if (scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col) != 4)
        {
            printf("Invalid input. Try again: ");
            while (getchar() != '\n') // Clear input buffer
                continue;
        }

        int from_position = from_row * 8 + from_col;
        int to_position = to_row * 8 + to_col;

        if (!is_within_bounds(from_position, to_position))
            continue;

        if(!correct_player_moving(state,from_position,current_player))
            continue;

        if (!piece_validation(state, from_position, to_position))
            continue;
        // check flag for special conditions (promotion or castling)

        move_controller(board, state, from_position, to_position);
        // update players turn if successful

        current_player ^= 1;
        // repeat
    }
}

void greetings()
{
    printf("Hello, this game of chess in hosted as a CLI game\n");
    printf("You are player 1 and will be WHITE, please input your moves as 'A1 A3'  'from - to' \n");
}
