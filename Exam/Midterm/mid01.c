#include <stdio.h>
#include <stdint.h>
int main(){
    double x1=0,x2=0,x3=0,x4=0,y1=0,y2=0,y3=0,y4=0;
    double line_x=0, line_y=0;
    printf("P1(x,y): ");
    scanf("%lf, %lf", &x1, &y1);
    printf("P2(x,y): ");
    scanf("%lf, %lf", &x2, &y2);
    printf("P3(x,y): ");
    scanf("%lf, %lf", &x3, &y3);
    printf("P4(x,y): ");
    scanf("%lf, %lf", &x4, &y4);
    printf("P(x,y): ");
    scanf("%lf, %lf", &line_x, &line_y);

    if(y1!=y2 || x2!=x3 || y3!=y4 || x1!=x4){
        printf("Invalid points entered.\n");
        return 1;
    }
    if((x1==x2 && y1==y2) || (x3==x4 && y3==y4) || (y1==y3 && x1==x3) || (y2==y3 && x1==x3)){
        printf("Invalid points entered.\n");
        return 1;
    }
    
    double x_mid = x1 + (double)((x2-x1)/2);
    double y_mid = y4 + (double)((y1-y4)/2);
    
    double slope = (line_y-y_mid)/(line_x-x_mid);
    double b = line_y - slope*line_x;
    if(line_x!=x_mid){
        printf("Line: y = %.2lf * x + %.2lf", slope, b);
    }
    else{
        printf("x = %.2lf", line_x);
    }

    return 0;
}
