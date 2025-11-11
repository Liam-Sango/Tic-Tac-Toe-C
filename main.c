#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

int Win_status = 0;
char gameboard[3][3] = 
{ {' ', ' ', ' '}, 
  {' ', ' ', ' '}, 
  {' ', ' ', ' '} };

/// Main function
int main () {
 return 0;
}

void display_gameboard (char gameboard[3][3]) {
    int c, r;
    printf("Current Game Board:\n");
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            printf("%c ", gameboard[r][c]);
        }
        printf("\n");
    }
}

void reset_game_board (char game_board[3][3]) {
    int c, r;
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            game_board[r][c] = ' ';
        }
    }
}

void make_game_move (char game_board [3][3], int target[2], int player_number) {
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
    }  
}

int check_winner (char game_board[3][3]) {
char Player1_symbol = 'X', Player2_symbol = 'O';
int c, r;
//check for Horizontal wins
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

//check for verticle wins
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


int player1_count = 0, player2_count = 0;
//Check for wins on the primary diagonal
for (c = 0; c < 3; c++) {
  r = c;
  if (game_board[c][r] == Player1_symbol) {
    player1_count++;
  } else if ( game_board [c][r] == Player2_symbol) {
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


//Check for wins on the Secondary diagonal
player1_count = 0, player2_count = 0;
for (c = 0; c < 3; c++) {
    r = 3 - c - 1;
    if (game_board[c][r] == Player1_symbol) {
    player1_count++;
  } else if ( game_board [c][r] == Player2_symbol) {
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
