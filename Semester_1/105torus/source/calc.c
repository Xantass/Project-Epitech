/*
** EPITECH PROJECT, 2021
** calc.c
** File description:
** function
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "proto.h"

double f_x(function f, double x)
{
    double result = 0;

    result = (f.a_4 * pow(x, 4)) + (f.a_3 * pow(x, 3)) + (f.a_2 * pow(x, 2)) + (f.a_1 * x) + f.a_0;
    return result;
}

double d_x(function f, double x)
{
    double result = 0;

    result = (4 * f.a_4 *pow(x, 3)) + (3 * f.a_3 * pow(x, 2)) + (2 * f.a_2 * x) + f.a_1;
    return result;
}

double bisection(function f, double a, double b)
{
    double c = (a + b) / 2;
    double res_a = f_x(f, a);
    double res_c = f_x(f, c);
    static int i = 1;

    printf("x = %.*f\n", i, c);
    if (fabs(res_c) <= pow(10, -f.prec))
        return 0;
    if (i < f.prec)
        i++;
    if (res_a * res_c < 0)
        return bisection(f, a, c);
    else
        return bisection(f, c, b);
    return 0;
}

double newton(function f, double x)
{
    double fx = f_x(f, x);
    double dx = d_x(f, x);
    double res = 0;
    static int i = 0;

    if (i == 0) {
        printf("x = %.1f\n", x);
    }
    else 
        printf("x = %.*f\n", f.prec, x);
    if (dx == 0)
        return 84;
    res = x - (fx / dx);
    if (round(x * pow(10, f.prec)) ==
        round(res * pow(10, f.prec)))
        return 0;
    i++;
    return newton(f, res);
}

double secant(function f, double a, double b)
{
    double fx = f_x(f, b);
    double fxs = f_x(f, a);
    double res = 0;
    static int i = 0;

    if ((fx - fxs) == 0)
        return 84;
    res = b - ((fx * (b - a)) / (fx - fxs));
    if (i == 0) {
        printf("x = %.1f\n", res);
    }
    else 
        printf("x = %.*f\n", f.prec, res);
    if (fabs(f_x(f, res)) <= pow(10, -f.prec))
        return 0;
    i++;
    return secant(f, b, res);
}
