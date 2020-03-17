#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

// Makes a random valid move
void random_player(Board &board);

// Allows input for a move
void human_player(Board &board, char player);

// Uses minimax algorithm to make optimal move
void minimax_player(Board &board, char maximizing_player);

#endif