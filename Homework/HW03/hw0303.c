#include <stdio.h>
#include <stdint.h>
#include "resistance.h"

int main(){
    int32_t r=0, n=0;
    printf("Please enter the resistance (1-100): ");
    scanf("%d", &r);
    printf("Please enter n (1-100): ");
    scanf("%d", &n);
    printf("Ans: %lf\n", equivalent(r, n));
    return 0;
}
