#include "hanoi.h"
#include <stdio.h>
#include <math.h>

//recursive codes
void recursive(int32_t diskNum, int origin, int destination, int aux){
    if(diskNum == 1){
        printf("move disk 1 to rod %d\n", destination);
        return;
    }
    else{
        recursive(diskNum - 1, origin, aux, destination);
        printf("move disk %d to rod %d\n", diskNum, destination);
        recursive(diskNum - 1, aux, destination, origin);
    }
}

//iterative codes
int sourceTop = -1;
int auxTop = -1;
int destTop = -1;

void push(int32_t stack[], int top, int data, int identifier){
    top += 1;
    stack[top] = data;
    if(identifier == 1){
        sourceTop = top;
    }
    else if(identifier == 3){
        auxTop = top;
    }
    else if(identifier == 2){
        destTop = top;
    }
}

int pop(int32_t stack[], int top, int identifier){
    int data = stack[top];
    if(identifier == 1){
        top--;
        sourceTop = top;
    }
    else if(identifier == 3){
        top--;
        auxTop = top;
    }
    else if(identifier == 2){
        top--;
        destTop = top;
    }
    return data;
}

int peek(int stack[], int top){
    int x = stack[top];
    return x;
}

void moveDisks(int sourceStack[], int destStack[], int sTop, int dTop, int sIdentifier, int dIdentifier){
    int peekSource = peek(sourceStack, sTop);
    int peekDest = peek(destStack, dTop);

    if(sTop == -1){
        int x = pop(destStack, dTop, dIdentifier);
        push(sourceStack, sTop, x, sIdentifier);
        printf("move disk %d to rod %d\n", x, sIdentifier);
    }
    else if(dTop == -1){
        int x = pop(sourceStack, sTop, sIdentifier);
        push(destStack, dTop, x, dIdentifier);
        printf("move disk %d to rod %d\n", x, dIdentifier);
    }
    else if(peekSource<peekDest){
        int x = pop(sourceStack, sTop, sIdentifier);
        push(destStack, dTop, x,  dIdentifier);
        printf("move disk %d to rod %d\n", x, dIdentifier);
    }
    else if(peekDest<peekSource){
        int x = pop(destStack, dTop, dIdentifier);
        push(sourceStack, sTop, x, sIdentifier);
        printf("move disk %d to rod %d\n", x, sIdentifier);
    }
}

void iterative(int32_t diskNum, int origin, int destination, int aux){

    int sourceArr[diskNum], destArr[diskNum], auxArr[diskNum];

    for(int i = diskNum; i >= 1; i--){
        push(sourceArr, sourceTop, i, origin);
    }


    int totalMoves = pow(2, diskNum) - 1;

    for(int i = 1; i <= totalMoves; i++){
        if(i%3==1){
            if(diskNum%2!=0){
                moveDisks(sourceArr, destArr, sourceTop, destTop, origin, destination);
            }
            else{
                moveDisks(sourceArr, auxArr, sourceTop, auxTop, origin, aux);
            }
        }
        else if(i%3==2){
            if(diskNum%2!=0){
                moveDisks(sourceArr, auxArr, sourceTop, auxTop, origin, aux);
            }
            else{
                moveDisks(sourceArr, destArr, sourceTop, destTop, origin, destination);
            }
        }
        else if(i%3==0){
            if(diskNum%2!=0){
                moveDisks(auxArr, destArr, auxTop, destTop, aux, destination);
            }
            else{
                moveDisks(destArr, auxArr, destTop, auxTop, destination, aux);
            }
        }
    }
}
