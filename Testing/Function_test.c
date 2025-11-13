#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sym_target[2];
int player_num;
char gameboard[3][3] = 
{ 
    {'X', ' ', ' '}, 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '} 
};

void make_game_move(char game_board[3][3], int target[2], int player_number) {
    int c, r;
    int row = target[0], col = target[1];
    char player_symbol;
    char opponent_symbol;


    if (player_number == 1) {
        player_symbol = 'X';
        opponent_symbol = 'O';
    } else if (player_number == 2 ){
        player_symbol = 'X';
        player_symbol = 'O';
    } else {
        exit(1);
    }

    if (game_board[row][col] == ' ') {
        game_board[row][col] = player_symbol;
    } else if (game_board[row][col] == player_symbol || opponent_symbol) {
        printf("Invalid move! Cell already occupied.\n");
        exit(0);
    }
}

void display_gameboard(char gameboard[3][3]) {
    int c, r, n;
    printf("Current Game Board:\n\n");
    for (r = 0; r < 3; r++) {
        printf ("%d: ", n);
        n++;
        for (c = 0; c < 3; c++) {
            printf("%c ", gameboard[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main () {
    sym_target[0] = 0, sym_target[1] = 0;
    player_num = 1;
    display_gameboard(gameboard);
    make_game_move(gameboard, sym_target, player_num);
    display_gameboard(gameboard);
    
    return 0;
}

