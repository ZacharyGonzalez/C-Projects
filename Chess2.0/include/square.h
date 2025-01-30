#ifndef SQUARE_H
#define SQUARE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t all_pieces;    // bitmap of all pieces, for collisions when moving

    uint64_t white_pieces;  // bitmap of white pieces, for black capture 
    uint64_t black_pieces;  // bitmap of black pieces, for white capture

    uint64_t white_attack_map;    // bitmap of white attacking threats
    uint64_t black_attack_map;    // bitmap of black attacking threats

    uint64_t check_attack_map; //if piece puts king in check, and no piece can land on this mapping, it would be checkmate (a line from the piece to the king)
    uint8_t game_board [32][3]; //[0]=position, [1]= piece, [2]=team
    uint8_t position_index[64];

} board_state;

typedef enum { WHITE = 1, BLACK = 0 } Color;
typedef struct{
    uint8_t value; // determines the piece and value of tha piece
    Color color;
}square;


#endif