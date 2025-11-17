//PREPROCESSING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

///GLOBAL VARIABLES
int move_target[2];
int player_number;
int Win_status = 0;
char gameboard[3][3] = 
{ 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '}, 
    {' ', ' ', ' '} 
};



/// MAIN FUNCTION
int main () {
    printf("\nWelcome to Norts and Crosses.\n");

    while (true) {
    /*#####  PLAYER 1  #####*/
    wait(10);
    printf("\n");
    display_gameboard(gameboard);
    move_target[0] = 0, move_target[1] = 0;
    player_number = 1;
    //Gathers the row where player 1 wishes to place a peice.
    printf("\n##Player 1##\n\nPlease enter The row number of the space where you want to place your piece.\n");
    printf("\nRow Number: ");
    scanf("%d", &move_target[0]);
    if (move_target[0] > 2 || move_target[0] < 0) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }
    
    //Gathers the collum where player 1 wishes to place a peice.
    printf("\nNow enter The Collum number of the space where you want to place your piece.\n");
    printf("\nCollum Number: ");
    scanf("%d", &move_target[1]);
    if (move_target[1] > 2 || move_target[1] < 0) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }

    check_winner(gameboard);
    make_game_move(gameboard, move_target, player_number);
    check_winner(gameboard);

    if (Win_status == 1) {
        printf("\n\n PLAYER 1 WINS\n\n");
        exit(0);
    } else if (Win_status == 2) {
        printf("O WINS");    printf("\n\n");
        exit(0);
        printf("\n\n PLAYER 2 WINS\n\n");
    } else if (Win_status == 3) {
        printf("\n\n ITS A DRAW\n\n");
        exit(0);
        }



    /*#####  PLAYER 2  #####*/

    //Displays the gameboard, resets variables.
    printf("\n\n");
    display_gameboard(gameboard);
    move_target[0] = 0, move_target[1] = 0;
    player_number = 2;
    //Gathers the row where player 1 wishes to place a peice.
    printf("\n\n##Player 2##\n\nPlease enter The row number of the space where you want to place your piece.\n");
    printf("\nRow Number: ");
    scanf("%d", &move_target[0]);
    if (move_target[0] > 2 || move_target[0] < 0) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }
    //Gathers the collum where player 1 wishes to place a peice.
    printf("\n\n##Player 2##\n\nPlease enter The Collum number of the space where you want to place your piece.\n");
    printf("\nCollum Number: ");
    scanf("%d", &move_target[1]);
    if (move_target[1] > 2 || move_target[1] < 0) {
        printf("\nYou entered an invalid Space... Exiting\n");
        exit(0); }

    //Checks for winners, Then Places player 2s move on the board
    check_winner(gameboard);
    make_game_move(gameboard,move_target, player_number);
    check_winner(gameboard);

    //Ends the loop if someone wins
     if (Win_status == 1) {
        printf("\n\n PLAYER 1 WINS\n\n");
        exit(0);
    } else if (Win_status == 2) {
        printf("O WINS");    printf("\n\n");
        exit(0);
        printf("\n\n PLAYER 2 WINS\n\n");
    } else if (Win_status == 3) {
        printf("\n\n ITS A DRAW\n\n");
        exit(0);
        }
}
return 0;
}

//FUNCTIONS

//Displays GameBoard
void display_gameboard(char gameboard[3][3]) {
    int r, c;
    int num = 0;
    printf("Current Game Board:\n\n");
    printf("   0 1 2\n");
    for (r = 0; r < 3; r++) {
         printf ("%d  ", num);
         num++;
        for (c = 0; c < 3; c++) {
        printf("%c ", gameboard[r][c]);
        }
    printf("\n");
    }
printf("\n");
}


//Resets Gameboard
void reset_game_board(char game_board[3][3]) {
    int c, r;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            game_board[r][c] = ' ';
        }
    }
}

//Makes moves on the gameboard
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
    }

    if (game_board[row][col] == ' ') {
        game_board[row][col] = player_symbol;
    } else if (game_board[row][col] != ' ' ){
        printf("Invalid move! Cell already occupied.\n");
        exit(0);
    }
}

//Checks for winners on the gameboard.
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

    //Checks if all spaces are filled.
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
        return Win_status;}

    return Win_status;
}