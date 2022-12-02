#include "rubik.h"
#include <stdio.h>

int cube[6][3][3];
int temp[1][3][3];

void rubikInitialize(){
    //0 = Red, 1 = Green, 2 = White, 3 = Blue, 4 = Yellow, 5 = Orange;
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                cube[i][j][k] = i;
            }
        }
    }
}

void rubikDisplay(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(cube[0][i][j]==0){
                printf("\e[31m*\e[m ");
            }
            else if(cube[0][i][j]==1){
                printf("\e[32m*\e[m ");
            }
            else if(cube[0][i][j]==2){
                printf("* ");
            }
            else if(cube[0][i][j]==3){
                printf("\e[34m*\e[m ");
            }
            else if(cube[0][i][j]==4){
                printf("\e[93m*\e[m ");
            }
            else if(cube[0][i][j]==5){
                printf("\e[38:5:208m*\e[m ");
            }
        }
        printf("\n");
    }
}


void rubikOperation(int input){
    switch(input){
        case 0:
            return;

        case 1:
            for(int i=0; i<3; i++){
                    temp[0][0][i] = cube[5][0][i];
            }
            for(int i=0; i<3; i++){
                    cube[5][0][i] = cube[3][0][i];
            }
            for(int i=0; i<3; i++){
                    cube[3][0][i] = cube[0][0][i];
            }
            for(int i=0; i<3; i++){
                    cube[0][0][i] = cube[1][0][i];
            }
            for(int i=0; i<3; i++){
                    cube[1][0][i] = temp[0][0][i];
            }
            rubikDisplay();
            break;

        case 2:
            for(int i=0; i<3; i++){
                temp[0][1][i] = cube[5][1][i];
            }
            for(int i=0; i<3; i++){
                cube[5][1][i] = cube[3][1][i];
            }
            for(int i=0; i<3; i++){
                cube[3][1][i] = cube[0][1][i];
            }
            for(int i=0; i<3; i++){
                cube[0][1][i] = cube[1][1][i];
            }
            for(int i=0; i<3; i++){
                cube[1][1][i] = temp[0][1][i];
            }
            rubikDisplay();
            break;

        case 3:
            for(int i=0; i<3; i++){
                temp[0][2][i] = cube[5][2][i];
            }
            for(int i=0; i<3; i++){
                cube[5][2][i] = cube[3][2][i];
            }
            for(int i=0; i<3; i++){
                cube[3][2][i] = cube[0][2][i];
            }
            for(int i=0; i<3; i++){
                cube[0][2][i] = cube[1][2][i];
            }
            for(int i=0; i<3; i++){
                cube[1][2][i] = temp[0][2][i];
            }
            rubikDisplay();
            break;

        case 4:
            for(int i=0; i<3; i++){
                temp[0][i][0] = cube[2][i][0];
            }
            for(int i=0; i<3; i++){
                cube[2][i][0] = cube[5][i][0];
            }
            for(int i=0; i<3; i++){
                cube[5][i][0] = cube[4][i][0];
            }
            for(int i=0; i<3; i++){
                cube[4][i][0] = cube[0][i][0];
            }
            for(int i=0; i<3; i++){
                cube[0][i][0] = temp[0][i][0];
            }
            rubikDisplay();
            break;

        case 5:
            for(int i=0; i<3; i++){
                temp[0][i][1] = cube[2][i][1];
            }
            for(int i=0; i<3; i++){
                cube[2][i][1] = cube[5][i][1];
            }
            for(int i=0; i<3; i++){
                cube[5][i][1] = cube[4][i][1];
            }
            for(int i=0; i<3; i++){
                cube[4][i][1] = cube[0][i][1];
            }
            for(int i=0; i<3; i++){
                cube[0][i][1] = temp[0][i][1];
            }
            rubikDisplay();
            break;

        case 6:
            for(int i=0; i<3; i++){
                temp[0][i][2] = cube[2][i][2];
            }
            for(int i=0; i<3; i++){
                cube[2][i][2] = cube[5][i][2];
            }
            for(int i=0; i<3; i++){
                cube[5][i][2] = cube[4][i][2];
            }
            for(int i=0; i<3; i++){
                cube[4][i][2] = cube[0][i][2];
            }
            for(int i=0; i<3; i++){
                cube[0][i][2] = temp[0][i][2];
            }
            rubikDisplay();
            break;

        default:
            printf("Invalid input! Please try again.\n");
            break;
    }
}