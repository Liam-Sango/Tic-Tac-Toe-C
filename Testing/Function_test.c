#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Win_status = 0;
char gameboard[3][3] = 
{ {'O', 'O', 'O'}, 
  {' ', 'X', ' '}, 
  {' ', ' ', 'O'} };

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
    for (r = 0; r < 3; r++) {
        if (game_board[c] == game_board[r] && game_board[c][r] == Player1_symbol) {
            player1_count++;
            if (player1_count >= 3) {
                Win_status = 1; // Player 1 wins
                return Win_status;
             }
        } else if (game_board[c] == game_board[r] && game_board[c][r] == Player2_symbol) {
            player2_count++;
            if (player2_count >= 3) {
                Win_status = 2; // Player 2 wins
                return Win_status;
            }
        }
    }
}
return Win_status;
}


int main () {
    int result = check_winner(gameboard);
    if (result == 1) {
        printf("Player 1 wins!\n");
    } else if (result == 2) {
        printf("Player 2 wins!\n");
    } else {
        printf("No winner yet.\n");
    }
    return 0;
return 0;
}

