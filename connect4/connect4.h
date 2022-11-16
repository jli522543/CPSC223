#ifndef CONNECT4_H
#define CONNECT4_H

#define ROWS 6
#define COLUMNS 7

static char board[ROWS][COLUMNS];

void connect4();

//Drops a piece at selected column
int dropPiece(int column,char currentPlayer);

//Ask current player to choose a number corresponding to a column to drop a piece and update the board
int makeMove(char player);

//Displays the current board
void displayBoard();

//Returns 0 if currentplayer has 4 in a row
int checkForWin(char currentPlayer);

#endif