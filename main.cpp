
#include "board.h"

int main() {

    Board board;
    char player_X, player_O;  // the type of each player (human, random, minimax)

    // choosing the player type for X
    do {
        printf("Choose player type for X:\nH - Human\nR - Random\nM - Minimax\n");
        scanf("%c", &player_X);
    } while (player_X != 'H' && player_X != 'R' && player_X != 'M');

    printf("\n");
    scanf("%c", &player_O);

    // choosing the player type for O
    do {
        printf("Choose player type for O:\nH - Human\nR - Random\nM - Minimax\n");
        scanf("%c", &player_O);
    } while (player_O != 'H' && player_O != 'R' && player_O != 'M');

    // main game loop
    for (int i = 0; i < 9; i++) {

        // player gets to make a move
        if (board.get_current_turn() == 'X') {
            if (player_X == 'H') {
                human_player(board, 'X');
            } else if (player_X == 'R') {
                random_player(board);
            } else if (player_X == 'M') {
                minimax_player(board, 'X');
            }
        } else {
            if (player_O == 'H') {
                human_player(board, 'O');
            } else if (player_O == 'R') {
                random_player(board);
            } else if (player_O == 'M') {
                minimax_player(board, 'O');
            }
        }

        // checking win / draw conditions
        if (board.check_win('X')) {
            board.print();
            printf("X Wins!\n\n");
            break;
        } else if (board.check_win('O')) {
            board.print();
            printf("O Wins!\n\n");
            break;
        } else if (board.check_draw()) {
            board.print();
            printf("Draw!\n\n");
            break;
        }
    }
    return 0;
}

