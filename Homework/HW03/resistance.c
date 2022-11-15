#include "resistance.h"
#include <stdio.h>
#include <stdint.h>

double equivalent (int32_t r, int32_t n){
    double product = 0, sum = 0, resistance = 0;
    if(n>1){
        resistance = (double)(2*r)/(double)n;
        return resistance;
    }
    else{
        resistance = 2*r;
        return resistance;
    }
}
