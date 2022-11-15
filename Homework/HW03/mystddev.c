#include "mystddev.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int points[];
int data = 0;
int sum = 0;
double mean = 0;

double get_stddev(int32_t number){
    //setup
    data++;
    sum += number;
    mean = (double)sum/(double)data;
    double deviation = 0;
    points[data];
    points[data-1] = number;

    //clear function
    if(points[data-3]==154){
        if(points[data-2]==-321){
            if(points[data-1]==965){
                for(int i=0; i<data; i++){
                    points[i] = 0;
                }
                data = 0;
                deviation = 0;
                sum = 0;
                printf("Cleared the input. ");
            }
        }
    }

    //calculation
    for(int i=0; i<data; i++){
        deviation += (points[i]-mean)*(points[i]-mean);
    }
    double variance = deviation/data;
    double stddev = sqrt(variance);
    return stddev;
}