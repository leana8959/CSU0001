#include <stdio.h>

int main() {
    double pointAx, pointAy, pointBx, pointBy, pointCx, pointCy;
    printf("Please enter the point A (x,y): ");
    scanf("%lf, %lf", &pointAx, &pointAy);
    printf("Please enter the point B (x,y): ");
    scanf("%lf, %lf", &pointBx, &pointBy);
    printf("Please enter the point C (x,y): ");
    scanf("%lf, %lf", &pointCx, &pointCy);

    if(pointAx==pointBx && pointAy==pointBy){
        printf("Error! A and B are not two distinct point!");
        return 1;
    }

    double slope = -1*((pointAy-pointBy)/(pointAx-pointBx));
    double b = pointCy - slope*pointCx;
    printf("The line: y = %lf * x + %lf", slope, b);
    return 0;
}
