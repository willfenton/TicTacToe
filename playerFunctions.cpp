#include <cstdio>
#include <ctime>
#include <algorithm>
#include "playerFunctions.h"
#include "minimax.h"

void random_player(Board &board) {
//    board.print();
    std::vector<int> moves = board.get_possible_moves();
    unsigned long size = moves.size();
    srand(time(nullptr));   // seed random function
    unsigned long random_index = rand() % size;
    board.move(moves[random_index]);
}

void human_player(Board &board, char player) {
    board.print();
    int move;
    std::vector<int> moves = board.get_possible_moves();

    do {
        printf("%c enter move (1-9): ", player);
        scanf("%d", &move);
    } while (!(std::find(moves.begin(), moves.end(), move) != moves.end()));

    board.move(move);
}

void minimax_player(Board &board, char maximizing_player) {
//    board.print();
    int move = minimax(board, maximizing_player, true);
    board.move(move);
}
