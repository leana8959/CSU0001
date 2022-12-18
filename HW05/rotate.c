#include "rotate.h"
#include <math.h>
#include <stdio.h>

void rotate( double *x, double *y, double theta ){
    double radians = theta / 180.0 * M_PI;
    double modify_x = cos(radians) * (*x) - sin(radians) * (*y);
    double modify_y = sin(radians) * (*x) + cos(radians) * (*y);
    *x = modify_x;
    *y = modify_y;
}