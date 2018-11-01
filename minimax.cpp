#include "minimax.h"

int score_game(Board board, char max_player) {
    char min_player;
    if (max_player == 'X') {
        min_player = 'O';
    } else {
        min_player = 'X';
    }

    int depth = board.get_depth();
    if (board.check_win(max_player)) {
        return (10 - depth);
    } else if (board.check_win(min_player)) {
        return(depth - 10);
    } else {
        return 0;
    }
}

int minimax(Board board, char max_player, bool first_call) {
    if (board.game_over()) {
        return score_game(board, max_player);
    }

    std::vector<int> scores;
    std::vector<int> moves = board.get_possible_moves();

    int size = moves.size();

    for (int i = 0; i < size; i++) {
        Board possible_game = board.get_new_state(moves[i]);
        scores.push_back(minimax(possible_game, max_player, false));
    }

    if (board.get_current_turn() == max_player) {
        int max_index = 0;
        for (int i = 0; i < size; i++) {
            if (scores[i] > scores[max_index]) {
                max_index = i;
            }
        }
        if (first_call) {
            return moves[max_index];
        } else {
            return scores[max_index];
        }
    } else {
        int min_index = 0;
        for (int i = 0; i < size; i++) {
            if (scores[i] < scores[min_index]) {
                min_index = i;
            }
        }
        return scores[min_index];
    }
}

