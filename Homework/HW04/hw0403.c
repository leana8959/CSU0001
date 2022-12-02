#include <stdio.h>
#include "rubik.h"



int main(){
    int input = -1;
    printf("Start: \n");
    rubikInitialize();
    rubikDisplay();
    while(input!=0){
        printf("Input [0-6]: ");
        scanf("%d", &input);
        rubikOperation(input);
    }
    return 0;
}
