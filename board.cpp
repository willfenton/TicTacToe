#include "board.h"

Board::Board() {
    depth = 0;
    current_turn = 'X';
    state = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

Board::~Board() = default;

void Board::next_turn() {
    if (current_turn == 'X') {
        current_turn = 'O';
    } else {
        current_turn = 'X';
    }
}

void Board::print() {
    printf("\n");
    for (int i = 0; i <= 6; i += 3) {
        printf("    -------------\n");
//        printf("| %d | %d | %d |\n", i + 1, i + 2, i + 3);
        printf("    | %c | %c | %c |\n", state[i], state[i + 1], state[i + 2]);
    }
    printf("    -------------\n\n");
}

bool Board::game_over(){
    return (check_draw() || check_win('X') || check_win('O'));
}

bool Board::check_draw() {
    if (check_win('X') || check_win('O')) {
        return false;
    } else {
        for (int i = 0; i < 9; i++) {
            if (state[i] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool Board::check_win(char player) {
    for (int i = 0; i < 3; i++) {
        if (state[(3 * i)] == player && state[(3 * i) + 1] == player && state[(3 * i) + 2] == player) {
            return true;
        } else if (state[i] == player && state[i + 3] == player && state[i + 6] == player) {
            return true;
        }
    }

    if (state[2] == player && state[4] == player && state[6] == player) {
        return true;
    }

    return (state[0] == player && state[4] == player && state[8] == player);
}

int Board::get_depth() {
    return depth;
}

char Board::get_current_turn() {
    return current_turn;
}

void Board::set_depth(int new_depth) {
    depth = new_depth;
}

void Board::set_state(std::vector<char> new_state) {
    state = new_state;
}

void Board::set_current_turn(char new_turn) {
    current_turn = new_turn;
}

Board Board::copy() {
    Board new_board;
    new_board.set_state(state);
    new_board.set_current_turn(current_turn);
    new_board.set_depth(depth);
    return new_board;

}

std::vector<int> Board::get_possible_moves() {
    std::vector<int> moves;
    for (int i = 0; i < 9; i++) {
        if (state[i] == ' ') {
            moves.push_back(i + 1);
        }
    }
    return moves;
}

void Board::move(int move) {
    state[move - 1] = current_turn;
    depth++;
    next_turn();
}

Board Board::get_new_state(int move) {
    Board new_board = copy();
    new_board.move(move);
    return new_board;
}