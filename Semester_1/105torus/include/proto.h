/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** header
*/

#ifndef PROTO_H
#define PROTO_H
#include "matrix.h"

int check_bis(char c);
int check_bisss(char c);
int check(char **argv);
function init(char **argv);
int choose(char **argv);
int main(int argc, char **argv);
double f_x(function f, double x);
double d_x(function f, double x);
double bisection(function f, double a, double b);
double newton(function f, double x);
double secant(function f, double a, double b);
#endif
