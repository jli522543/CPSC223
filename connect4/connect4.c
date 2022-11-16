#include <stdio.h>
#include <stdlib.h>

#include "connect4.h"

void connect4(){
    int currentplayer = 1;
    char piece;
    while(1){
        //Determine piece
        switch(currentplayer){
            case 1:
                piece ='x';
                break;
            case 2:
                piece = 'o';
                break;
        }

        //Display board
        displayBoard();

        //Ask current player to make a move
        printf("Player %d make a move: ",currentplayer);
        int success = makeMove(piece);

        //If move is not valid, let player try again
        while(success != 0){
            displayBoard();
            printf("Invalid Selection. Try again.\n");
            printf("Player %d make a move: ",currentplayer);
            success = makeMove(piece);
        }

        //Check for win
        int win = checkForWin(piece);
        if(win == 0){
            displayBoard();
            printf("Player %d wins!\n", currentplayer);
            break;
        }

        //Change players
        if(currentplayer == 1)
            currentplayer = 2;
        else
            currentplayer = 1;
    }   
}

int checkForWin(char piece){
    //Check horizontals
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j <= (COLUMNS - 4); j++){
            if(board[i][j] == piece && board[i][j+1] == piece && board[i][j+2] == piece && board[i][j+3] == piece){
                 return 0;
            }
        }
    }

    //Check verticals
    for(int i = 0; i < COLUMNS; i++){
        for(int j = 0; j <= (ROWS - 4); j++){
            if(board[j][i] == piece && board[j+1][i] == piece && board[j+2][i] == piece && board[j+3][i] == piece){
                return 0;
            }
        }
    }

    //Check for diagnals
    for(int i = 0; i < (ROWS - 3); i++){
        for(int j = 0; j < (COLUMNS - 3); j++){
            if(board[i][j] == piece && board[i+1][j+1] == piece && board[i+2][j+2] == piece && board[i+3][j+3] == piece){
                return 0;
            }
        }
    }

    for(int i = 0; i < (ROWS - 3); i++){
        for(int j = COLUMNS - 1; j > 2; j--){
            if(board[i][j] == piece && board[i+1][j-1] == piece && board[i+2][j-2] == piece && board[i+3][j-3] == piece){
                return 0;
            }
        }
    }

    return 1;
}

//Clears stdin buffer
//Should not be used if buffer is empty
void flushstdin(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int dropPiece(int column,char currentPlayer){
    //Drop piece to bottom of selected column
    for(int i = ROWS-1; i>=0; i--){
        if(board[i][column] == 0){
            board[i][column] = currentPlayer;
            return 0;
        }
    }
    return 1;
}

int makeMove(char player){
    int col;

    //Get column choice from player
    if(scanf("%d", &col) == EOF){
        exit(EXIT_FAILURE);
    }
    flushstdin();

    //Check if column is within scope of current board
    if(col >=1 && col <=COLUMNS){
        if(dropPiece(col-1,player)!=0){ //If column is full
            return 1;
        }
        else 
            return 0;
    }   
    else {//If column does not exist
        return 1;
    }
}

void displayBoard(){ 
    
    //Display Column Numbers
    for(int i = 0; i < COLUMNS; i++){
        printf("  %d ", i+1);
    }
    printf("\n");

    //Print board
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < (COLUMNS * 4)+1; j++){
            printf("-");
        }
        printf("\n");
        for(int k = 0; k < COLUMNS; k++){
            printf("| ");
            if(board[i][k] != 0){
                printf("%c ",board[i][k]);
            }
            else
                printf("  ");
        }
        printf("|");
        printf("\n");
    }
    for(int j = 0; j < (COLUMNS * 4)+1; j++){
        printf("-");
    }
    printf("\n");
}