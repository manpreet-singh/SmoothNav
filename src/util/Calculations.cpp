//
// Created by singh on 7/27/2018.
//

#include "Calculations.h"
using namespace util;

/**
 * Get the length of a curve using Simpson's rule
 * @param a Lower limit
 * @param b Upper limit
 * @param resolution the number of points to use between the two limits
 * @param d Function pointer
 * @return Length of a curve
 */
double Calculations::length(double a, double b, int resolution, double (*d)(double))
{
    double step = (b-a)/resolution;
    return step/3 * ((*d)(a) + (*d)(b) + Calculations::recursion(b, a + step, step, *d));
}

/**
 * Recursion Function to help calculate length of a curve
 * @param end Endpoint of curve
 * @param x Starting point of curve
 * @param step Number to increment by
 * @param d Function pointer
 * @param even Helps keep track of things while recursioning (Yeah... don't even touch this value)
 * @return part of the answer we need
 */
double Calculations::recursion(double end, double x, double step, double(*d)(double), bool even)
{
    if(x > end)
        return 0;
    if (even)
        return 2 * (*d)(x) + recursion(end, x + step, step, *d, false);
    else
        return 4 * (*d)(x) + recursion(end, x + step, step, *d, true);
}