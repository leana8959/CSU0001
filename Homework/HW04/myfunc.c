#include "myfunc.h"
#include <stdio.h>
#include <math.h>

double cal_n_derivatives(int32_t n, double a, int32_t size, int32_t coefficients[], int32_t powers[]){
    double output = 0;
    int32_t lostDigits = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<size; j++){
            coefficients[j] *= powers[j];
            if(powers[j]>0){
                powers[j]-=1;
            }
            else if(powers[j]==0){
                coefficients[j] = 0;
            }
        }
/*        printf("The %dth Derivatives:", i+1);
        for(int k=0; k<size; k++){
            printf("%dx", coefficients[k]);
            printf("^%d + ", powers[k]);
        }
        printf("\n");*/
    }
    for(int k=0; k<size; k++){
        if(powers[k]>0){
            output += coefficients[k] * pow(a, powers[k]);
        }
        else{
            output += coefficients[k];
        }
    }
    return output;
}