#include "checker.h"
#include <stdio.h>

int winning = 0;
int board[17][25];
int boardNum[17] = {1, 2, 3, 4, 13, 12, 11, 10, 9,
                    10, 11, 12, 13, 4, 3, 2, 1};

void checkerInitialize(){
    int left[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                    5, 6, 7, 8, 0, 0, 0, 0};
    int right[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                     19, 18, 17, 16, 0, 0, 0, 0};

    //Initial: All blank
    for(int a = 0; a < 17; a++){
        for(int b = 0; b < 25; b++){
            board[a][b] = -1;
        }
    }

    //Print out the star shape
    for(int i = 0; i < 17; i++){
        //Left part of the star shape
        int temp = 0;
        for(int j = 12; j <= 11 + boardNum[i]; j++){
            if(i % 2 == 0 || i == 0){
                if(j % 2 == 0){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = -1;
                }
            }
            else{
                if(j % 2 == 0){
                    board[i][j] = -1;
                }
                else{
                    board[i][j] = 0;
                }
            }
            //yellow
            if(i < 4){
                if(board[i][j] == 0){
                    board[i][j] = 3;
                }
            }
            //red
            else if(i > 8 && i < 13){
                for(int k = 24; k > right[i]; k--){
                    if(board[i][k] == 0){
                        board[i][k] = 1;
                    }
                }
            }
        }
        //Right part of the star shape
        temp = 0;
        for(int j = 12; j >= 13 - boardNum[i]; j--){
            if(i % 2 == 0 || i == 0){
                if(j % 2 == 0){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = -1;
                }
            }
            else{
                if(j % 2 == 0){
                    board[i][j] = -1;
                }
                else{
                    board[i][j] = 0;
                }
            }
            //yellow
            if(i < 4){
                if(board[i][j] == 0){
                    board[i][j] = 3;
                }
            }
            //green
            else if(i > 8 && i < 13){
                for(int k = 0; k < left[i]; k++){
                    if(board[i][k] == 0){
                        board[i][k] = 2;
                    }
                }
            }
        }
    }
}

void checkerDisplay(){
    //-1 = Gap, 0 = Space, 1 = Red, 2 = Green, 3 = Yellow
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 25; j++){
            if(board[i][j] == -1){
                printf(" ");
            }
            else if(board[i][j] == 0){
                printf("*");
            }
            else if(board[i][j] == 1){
                printf("\e[31m*\e[m");
            }
            else if(board[i][j] == 2){
                printf("\e[32m*\e[m");
            }
            else if(board[i][j] == 3){
                printf("\e[93m*\e[m");
            }
        }
        printf("\n");
    }
}

void checkerGame(){
    winning = 1;
}
