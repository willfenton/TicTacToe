#pragma once

#include <vector>

// Board class
class Board
{
public:
    // Constructor and destructor for Board class (both trivial)
    Board();
    ~Board();

    // Switches the current turn (X->O or O->X)
    void next_turn();

    // Prints a representation of the board state to stdio
    void print();

    // functions for checking whether the game has ended, and if so, which player won
    bool game_over();   // returns true if the game is over (draw or win), and false otherwise
    bool check_draw();  // returns true if the game ended in a draw, false otherwise
    bool check_win(char player);    // returns true if the player won the game, false otherwise

    // Returns the depth (number of moves made so far in the game)
    int get_depth();

    // Returns the current player (char 'X' or 'O')
    char get_current_turn();

    // Functions for setting member variables (used in the copy function)
    void set_depth(int new_depth);
    void set_state(std::vector<char> new_state);
    void set_current_turn(char new_turn);

    // Returns a copy of the board
    Board copy();

    // Returns a vector containing all unoccupied squares (1,2,...,9)
    std::vector<int> get_possible_moves();

    // Returns a new Board with move "move" executed
    Board get_new_state(int move);

    // Executes a move, setting the desired tile to the current player character ('X' or 'O')
    void move(int move);

private:
    // Board state containing 9 characters, ' ', 'O' or 'X' (all initialized to ' ')
    std::vector<char> state;

    // Character of current player ('X' or 'O')
    char current_turn;

    // Number of moves made so far in the game (non-blank squares)
    int depth;
};