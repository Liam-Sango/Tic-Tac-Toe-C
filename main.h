#ifndef MAIN_H
#define MAIN_H

// Function declarations

//displays the game board
void display_gameboard (char gameboard[3][3]);
//Resets the game board
void reset_game_board(char game_board[3][3]);
//Adds a move to the game board
void make_game_move (char game_board [3][3], int target[2], int player_number);
//checks for a winner   
int check_winner (char game_board[3][3]);

// Global variables declaration
extern char gameboard[3][3];

#endif /* MAIN_H */
