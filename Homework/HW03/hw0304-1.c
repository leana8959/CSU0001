#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"

int main(){
    //recursive
    int32_t diskNum;
    printf("Please enter the disk number (2-20): ");
    scanf("%d", &diskNum);
    recursive(diskNum, 1, 2, 3);
    return 0;

/*
    //iterative
    int32_t diskNum;
    printf("Please enter the disk number (2-20): ");
    scanf("%d", &diskNum);
    iterative(diskNum, 1, 2, 3);
    return 0;
*/
}
