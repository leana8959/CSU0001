#pragma once
#include <stdint.h>

// Input Arguments:
// n: n-th derivatives
// a: the input value
// size: the size (item numbers) of coefficients[] and powers[]
// coefficients[], powers[]: polynomials

double cal_n_derivatives(int32_t n, double a, int32_t size, int32_t coefficients[], int32_t powers[]);
