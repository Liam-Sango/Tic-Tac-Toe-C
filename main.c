#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

int Win_status = 0;
int board_fill_status = 0;
char gameboard[3][3] = 
{ 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '} 
};

/// Main function
int main () {
    //Variables
    bool player_1_Active;
    bool player_2_Active;
    int move_target[1];
    int player_number;

    //Greets the players.
    printf("\nWelcome to Norts and Crosses.\n\n");


    //Main_Loop
    while (true) {
    }

    //PLAYER 1
    if (player_1_Active == true) {
    move_target[0] = 0, move_target[1] = 0;
    player_number = 1;
    //Gathers the row where player 1 wishes to place a peice.
    printf("\n\n##Player 1##\n\nPlease enter The row number of the space where you want to place your piece.\n");
    scanf("%d", &move_target[0]);
    if (move_target[0] > 3 || move_target[0] < 1) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }
    
    //Gathers the collum where player 1 wishes to place a peice.
    printf("\n\n##Player 1##\n\nPlease enter The Collum number of the space where you want to place your piece.\n");
    scanf("%d", &move_target[1]);
    if (move_target[1] > 3 || move_target[1] < 1) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }

    check_board_fill(gameboard);
    make_game_move(gameboard,move_target, player_number);
    }

    //PLAYER 2
    
    if (player_2_Active == true) {
    move_target[0] = 0, move_target[1] = 0;
    player_number = 2;
    //Gathers the row where player 2 wishes to place a peice.
    printf("\n\nPlayer 2\nPlease enter The row number of the space where you want to place your piece.\n");
    scanf("%d", &move_target[0]);
    if (move_target[0] > 3 || move_target[0] < 1) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }
    
    //Gathers the collum where player 2 wishes to place a peice.
    printf("\n\nPlayer 2\nPlease enter The Collum number of the space where you want to place your piece.\n");
    scanf("%d", &move_target[1]);
    if (move_target[1] > 3 || move_target[1] < 1) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }
    
    check_board_fill(gameboard);
    make_game_move(gameboard,move_target, player_number);
    }
    

    return 0;
}

int check_board_fill(char game_board[3][3]) {
    int c, r;
    int space_counter = 0;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            if (game_board[c][r] != ' ') {
                space_counter++;
            }
        }
    }
    if (space_counter >= 9) {
        Win_status = 3;
    } else {
        Win_status = 0;
    }
    return Win_status;
}

void display_gameboard(char gameboard[3][3]) {
    int c, r;
    printf("Current Game Board:\n");
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            printf("%c ", gameboard[r][c]);
        }
        printf("\n");
    }
}

void reset_game_board(char game_board[3][3]) {
    int c, r;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            game_board[r][c] = ' ';
        }
    }
}

void make_game_move(char game_board[3][3], int target[2], int player_number) {
    int c, r;
    int row = target[0], col = target[1];
    char player_symbol;
    if (player_number == 1) {
        player_symbol = 'X';
    } else {
        player_symbol = 'O';
    }
    if (game_board[row][col] == ' ') {
        game_board[row][col] = player_symbol;
    } else {
        printf("Invalid move! Cell already occupied.\n");
        exit(0);
    }
}

int check_winner(char game_board[3][3]) {
    char Player1_symbol = 'X', Player2_symbol = 'O';
    int c, r;

    // Check for Horizontal wins
    for (c = 0; c < 3; c++) {
        int player1_count = 0, player2_count = 0;
        for (r = 0; r < 3; r++) {
            if (game_board[c][r] == Player1_symbol) {
                player1_count++;
                if (player1_count >= 3) {
                    Win_status = 1; // Player 1 wins
                    return Win_status;
                }
            } else if (game_board[c][r] == Player2_symbol) {
                player2_count++;
                if (player2_count >= 3) {
                    Win_status = 2; // Player 2 wins
                    return Win_status;
                }
            }
        }
    }

    // Check for Vertical wins
    for (c = 0; c < 3; c++) {
        int player1_count = 0, player2_count = 0;
        for (r = 0; r < 3; r++) {
            if (game_board[r][c] == Player1_symbol) {
                player1_count++;
                if (player1_count >= 3) {
                    Win_status = 1; // Player 1 wins
                    return Win_status;
                }
            } else if (game_board[r][c] == Player2_symbol) {
                player2_count++;
                if (player2_count >= 3) {
                    Win_status = 2; // Player 2 wins
                    return Win_status;
                }
            }
        }
    }

    // Check for wins on the primary diagonal
    int player1_count = 0, player2_count = 0;
    for (c = 0; c < 3; c++) {
        r = c;
        if (game_board[c][r] == Player1_symbol) {
            player1_count++;
        } else if (game_board[c][r] == Player2_symbol) {
            player2_count++;
        }
    }
    if (player1_count == 3) {
        Win_status = 1; // Player 1 wins
        return Win_status;
    } else if (player2_count == 3) {
        Win_status = 2; // Player 2 wins
        return Win_status;
    }

    // Check for wins on the secondary diagonal
    player1_count = 0, player2_count = 0;
    for (c = 0; c < 3; c++) {
        r = 3 - c - 1;
        if (game_board[c][r] == Player1_symbol) {
            player1_count++;
        } else if (game_board[c][r] == Player2_symbol) {
            player2_count++;
        }
    }
    if (player1_count == 3) {
        Win_status = 1; // Player 1 wins
        return Win_status;
    } else if (player2_count == 3) {
        Win_status = 2; // Player 2 wins
        return Win_status;
    }

    return Win_status;
}
