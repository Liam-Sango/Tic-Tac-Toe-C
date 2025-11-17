#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> 
#include <stdlib.h>


//GLOBAL VARS
int win_status = 0;


// FUNCTION DECLARATIONS (PROTOTYPES)

// Displays GameBoard
void display_gameboard(char gameboard[3][3]);

// Resets Gameboard
void reset_game_board(char game_board[3][3]);

// Makes a move on the gameboard
void make_game_move(char game_board[3][3], int target[2], int player_number);

// Checks for a winner or a tie.
int check_game_status(char game_board[3][3]);

#endif // MAIN_H