#include "../include/attack_controller.h"

void attack_controller(){
    //take map of the board, use the queen move on the before move to find which piece were affected by the move
    //update their attackusing the collision_controller to generate their new bit_map.
    //every collision returned is then used to reupdate that positions attacking table (the board points to the whole table, the piece point to their own table) double linked list
    //now perform the same queen collision check to find the piece affected by the new move and recalcluate that.
    //update both colors board attack_maps.
}