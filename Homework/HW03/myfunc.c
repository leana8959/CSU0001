#include "myfunc.h"

#include <stdio.h>
#include <stdint.h>

int32_t func_a = 0, func_b = 0, func_c = 0;

int32_t setup( int32_t a, int32_t b, int32_t c){
    if(a==0){
        return -1;
    }
    else{
        func_a = a;
        func_b = b;
        func_c = c;
        return 0;
    }
}

double value( double x ){
    double value = func_a*x*x + func_b*x + func_c;
    return value;
}

double min( double m, double n ){
    double result;
    if(func_a < 0){
        if(m > n){
            result = func_a * m * m + func_b * m + func_c;
        }
        else if(m == n){
            result = func_a * m * m + func_b * m + func_c;
        }
        else{
            result = func_a * n * n + func_b * n + func_c;
        }
    }
    else{
        if(m > n){
            result = func_a * n * n + func_b * n + func_c;
        }
        else if(m == n){
            result = func_a * m * m + func_b * m + func_c;
        }
        else{
            result = func_a * m * m + func_b * m + func_c;
        }
    }
    return result;
}

double max(double m, double n){
    double result;
    double temp;
    if(func_a < 0){
        if(m > n){
            result = func_a * n * n + func_b * n + func_c;
        }
        else if(m == n){
            result = func_a * m * m + func_b * m + func_c;
        }
        else{
            result = func_a * m * m + func_b * m + func_c;
        }
    }
    else{
        if(m > n){
            result = func_a * m * m + func_b * m + func_c;
        }
        else if(m == n){
            result = func_a * m * m + func_b * m + func_c;
        }
        else{
            result = func_a * n * n + func_b * n + func_c;
        }
    }
    return result;
}

double slope(double t){
    double s = 2*func_a*t + func_b;
    return s;
}
