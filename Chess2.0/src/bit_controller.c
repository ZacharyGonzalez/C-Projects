#include "../include/bit_controller.h"

bool collision_controller(uint64_t move_mask, uint64_t piece_bitmap)
{
    return (move_mask & piece_bitmap) != 0;
}

uint64_t generate_threat_map(square *board, int color)
{
    uint64_t threat_map = 0;
    for (int i = 0; i < 64; i++)
    {
        if (board[i].color == color)
        {
            switch (board[i].value)
            {
            case 1: // pawn
                pawn_moves(i, color);
                break;
            case 4: // rook
                rook_moves(i);
                break;
            case 3: // bishop
                bishop_moves(i);
                break;
            case 5: // knight
                knight_moves(i);
                break;
            case 6: // queen
                knight_moves(i);
                break;
            case 9: // king
                king_moves(i);
                break;
            }
        }
    }
    return threat_map;
}

uint64_t bishop_moves(int position)
{
    uint64_t moves = 0;
    int row = position / 8;
    int col = position % 8;
    // bottomleft
    for (int i = 1; row - i >= 0 && col - i >= 0; i++)
    {
        moves |= (1ULL << ((row - i) * 8 + (col - i)));
    } // bottom right
    for (int i = 1; row - i >= 0 && col + i < 8; i++)
    {
        moves |= (1ULL << ((row - i) * 8 + (col + i)));
    } // top left
    for (int i = 1; row + i < 8 && col - i >= 0; i++)
    {
        moves |= (1ULL << ((row + i) * 8 + (col - i)));
    } // topright
    for (int i = 1; row + i < 8 && col + i < 8; i++)
    {
        moves |= (1ULL << ((row + i) * 8 + (col + i)));
    }
    return moves;
}
uint64_t rook_moves(int position)
{
    uint64_t moves = 0;
    int row = position / 8;
    int col = position % 8;
    // down
    for (int i = row - 1; i >= 0; i--)
    {
        moves |= (1ULL << (i * 8 + col));
    } // up
    for (int i = row + 1; i < 8; i++)
    {
        moves |= (1ULL << (i * 8 + col));
    } // left
    for (int i = col - 1; i >= 0; i--)
    {
        moves |= (1ULL << (row * 8 + i));
    } // right
    for (int i = col + 1; i < 8; i++)
    {
        moves |= (1ULL << (row * 8 + i));
    }
    return moves;
}
uint64_t pawn_moves(int position, int color)
{
    uint64_t moves = 0;
    if (color == 1)
    {
        if (position + 8 < 64)
        {
            if (position % 8 != 0)
                moves |= (1ULL << (position + 7));
            if (position % 8 != 7)
                moves |= (1ULL << (position + 9));
        }
    }
    else
    {
        if (position - 8 > 0)
        {
            if (position % 8 != 0)
                moves |= (1ULL << (position - 7));
            if (position % 8 != 7)
                moves |= (1ULL << (position - 9));
        }
    }
    return moves;
}
uint64_t queen_moves(int position)
{
    uint64_t moves = 0;
    uint64_t diagonal = 0;
    uint64_t linear = 0;
    linear = rook_moves(position);
    diagonal = bishop_moves(position);
    moves = diagonal & linear;
    return moves;
}
uint64_t king_moves(int position)
{
    uint64_t moves = 0;
    if (position + 8 < 64)
    {
        moves |= (1ULL << (position + 8));
        if (position % 8 != 7) // upleft
            moves |= (1ULL << (position - 1));
        moves |= (1ULL << (position + 7));
        if (position % 8 != 0) // upright
            moves |= (1ULL << (position + 9));
        moves |= (1ULL << (position + 1));
    }
    if (position - 8 > 0)
    {
        moves |= (1ULL << (position - 8));
        if (position % 8 != 7) // downleft
            moves |= (1ULL << (position - 9));
        if (position % 8 != 0) // downright
            moves |= (1ULL << (position - 7));
    }

    return moves;
}
uint64_t knight_moves(int position) {
    uint64_t moves=0;
    return moves;
}
