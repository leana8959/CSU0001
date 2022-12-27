#include <stdio.h>
#include "rotate.h"

int main(){
    double x, y, theta;
    printf("Please enter the two points (x,y): ");
    scanf("%lf, %lf", &x, &y);
    printf("Please enter the rotate degree:");
    scanf("%lf", &theta);
    rotate(&x, &y, theta);
    printf("Rotated point: %lf, %lf", x, y);
    return 0;
}
