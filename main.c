//PREPROCESSING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

//FUNCTION DECLERATIONS

//displays the game board
void display_gameboard (char gameboard[3][3]);
//Resets the game board
void reset_game_board(char game_board[3][3]);
//Adds a move to the game board
void make_game_move (char game_board [3][3], int target[2], int player_number);
//checks for a winner   
int check_winner (char game_board[3][3]);



///GLOBAL VARIABLES
int move_target[2];
int player_number;

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