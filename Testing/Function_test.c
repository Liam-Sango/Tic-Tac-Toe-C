#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char gameboard[3][3] = 
{ {' ', ' ', ' '}, 
  {' ', ' ', ' '}, 
  {' ', ' ', ' '} };

int board_status;

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
        board_status = 1;
    } else {
        board_status = 0;
    }
return board_status;
}

int main () {
int status = check_board_fill(gameboard);
if (status == 1) {
    printf("Board is filled");
} else {
    printf("Board is not filled");
}
return 0;
}
