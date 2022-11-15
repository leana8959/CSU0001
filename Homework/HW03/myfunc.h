#pragma once

#include <stdint.h>

// Setup a quadratic function.
// This function must be called before all other functions.
// If a == 0, return -1; otherwise , return 0.
int32_t setup( int32_t a, int32_t b, int32_t c);

// Return f(x)
double value( double x );

// Return the minimum value of f(x) between m and n
// m may be greater than/equal to/smaller than n
double min( double m, double n );

// Return the maximum value of f(x) between m and n
// m may be greater than/equal to/smaller than n
double max( double m, double n );

// Return slope of the tangent line of f(x) at x=t
double slope( double t );