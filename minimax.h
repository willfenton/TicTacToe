#ifndef MINIMAX_H
#define MINIMAX_H

#include "board.h"

// Returns the score of the game from the perspective of the maximizing player
// 10 - depth if the maximizing player wins (subtracting depth to maximize win speed)
// depth - 10 if the maximizing player loses (draws out its losses, also vs a human player more time for a potential mistake)
// 0 if the game ends in a draw
int score_game(Board board, char max_player);

// Function that returns the optimal move to make for player specifiec given the game state in the board passed
// Recursively checks all possible future game states, assigning scores to each end state
// For each turn, the maximizing player will pick the move with the highest score
// The minimizing player will pick the move with the lowest score
// Should always be passed with true as first_call (necessary to return the optimal move instead of score
int minimax(Board board, char max_player, bool first_call);

#endif