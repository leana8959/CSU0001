#include "triangle.h"

#include <stdio.h>
#include <math.h>

double firstX,firstY;
double secondX,secondY;
double thirdX,thirdY;
double firstSide,secondSide,thirdSide, perimeter;
double firstAngle,secondAngle,thirdAngle,area;
int validity;

int set_point_1( double x, double y){
    firstX = x;
    firstY = y;
    return 1;
}

int set_point_2( double x, double y){
    secondX = x;
    secondY = y;
    if(firstX!=x && firstY!=y){
        return 1;
    }
    else{
        return 0;
    }
}

int set_point_3( double x, double y){
    thirdX = x;
    thirdY = y;
    if(secondX!=x && secondY!=y || firstX!=x && firstY!=y){
        return 1;
    }
    else{
        return 0;
    }
}

int check (void){
    if(firstX==secondX && firstY==secondY){
        validity = 0;
    }
    else if(secondX==thirdX && secondY==thirdY || firstX==thirdX && firstY==thirdY){
        validity = 0;
    }
    else if(((secondY-firstY)/(secondX-firstX))==((thirdY-secondY)/(thirdX-secondX))){
        validity = 0;
    }
    else{
        validity = 1;
    }
    return validity;
}

double get_perimeter(void){
    if(validity==0){
        return -1;
    }
    else{
        firstSide = sqrt(pow(firstX-secondX,2)+pow(firstY-secondY,2));
        secondSide = sqrt(pow(secondX-thirdX,2)+pow(secondY-thirdY,2));
        thirdSide = sqrt(pow(thirdX-firstX,2) + pow(thirdY-firstX,2));
        perimeter = firstSide + secondSide + thirdSide;
        return perimeter;
    }
}

double get_area(void){
    if(validity==0){
        return -1;
    }
    else{
        double s = (firstSide + secondSide + thirdSide)/2;
        area = sqrt(s*(s-firstSide)*(s-secondSide)*(s-thirdSide));
        return area;
    }
}

double get_degree_1(void) {
    if (validity == 0) {
        return -1;
    } else {
        firstAngle = acos((pow(secondSide, 2) + pow(thirdSide, 2) - pow(firstSide, 2)) / 2 * secondSide * thirdSide);
        return firstAngle;
    }
}

double get_degree_2(void){
    if(validity==0){
        return -1;
    }
    else{
        secondAngle = acos((pow(firstSide,2)+pow(thirdSide,2)-pow(secondSide,2))/2*firstSide*thirdSide);
        return secondAngle;
    }
}

double get_degree_3(void){
    if(validity==0){
        return -1;
    }
    else{
        thirdAngle = acos((pow(firstSide,2)+pow(secondSide,2)-pow(thirdSide,2))/2*firstSide*secondSide);
        return thirdAngle;
    }
}

double get_incircle_area(void){
    if(validity==0){
        return -1;
    }
    else{
        double inscribedDiameter = 2*area/firstSide+secondSide+thirdSide;
        double inscribedArea = pow(inscribedDiameter,2)*M_PI;
        return inscribedArea;
    }
}

