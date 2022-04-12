/*
** EPITECH PROJECT, 2020
** boostrap.c
** File description:
** function
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"
#include "proto.h"

int sphere(point_p p, vecteur_t v, double r)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double temp = 0;
    double t = 0;
    double dis = 0;

    if (r <= 0)
        exit(84);
    printf("Sphere of radius %.0f\n", r);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", p.x, p.y, p.z, v.x, v.y, v.z);
    a = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
    b = 2 * ((p.x * v.x) + (p.y * v.y) + (p.z * v.z));
    c = pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2) - pow(r, 2);
    dis = discriminant(a, b, c);
    if (a == 0)
        exit(84);
    if ((nb_soluce(a, b, c)) == 2) {
        printf("2 intersection points:\n");
        t = (-b + sqrt(dis)) / (2 * a);
        calc_point_l(p, v, t);
        t = (-b - sqrt(dis)) / (2 * a);
        calc_point_l(p, v, t);
        return 0;
    }
    if ((nb_soluce(a, b, c)) == 1) {
        printf("1 intersection point:\n");
        temp = 2 * a;
        t = (-b / temp);
        calc_point_l(p, v, t);
        return 0;
    }
    if ((nb_soluce(a, b, c)) == 0) {
        printf("No intersection point.\n");
        return 0;
    }
    return 0;
}

int cylinder(point_p p, vecteur_t v, double r)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double temp = 0;
    double t = 0;
    double dis = 0;

    if (r <= 0)
        exit(84);
    printf("Cylinder of radius %.0f\n", r);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", p.x, p.y, p.z, v.x, v.y, v.z);
    a = pow(v.x, 2) + pow(v.y, 2);
    b = 2 * ((p.x * v.x) + (p.y * v.y));
    c = pow(p.x, 2) + pow(p.y, 2) - pow(r, 2);
    dis = discriminant(a, b, c);
    if (c == 0) {
        printf("There is an infinite number of intersection points.\n");
        return 0;
    }
    if (a == 0)
        exit(84);
    if ((nb_soluce(a, b, c)) == 2) {
        printf("2 intersection points:\n");
        t = (-b + sqrt(dis)) / (2 * a);
        calc_point_l(p, v, t);
        t = (-b - sqrt(dis)) / (2 * a);
        calc_point_l(p, v, t);
        return 0;
    }
    if ((nb_soluce(a, b, c)) == 1) {
        printf("1 intersection point:\n");
        temp = 2 * a;
        t = (-b / temp);
        calc_point_l(p, v, t);
        return 0;
    }
    if ((nb_soluce(a, b, c)) == 0) {
        printf("No intersection point.\n");
        return 0;
    }
    return 0;
}

int cone(point_p p, vecteur_t v, double A)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double temp = 2;
    double t = 0;
    double dis = 0;
    double pi = (3.14159265358979323846);

    printf("Cone with a %.0f degree angle\n", A);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", p.x, p.y, p.z, v.x, v.y, v.z);
    if (A == 90 || A < 0 || A > 360)
        exit(84);
    a = pow(v.x, 2) + pow(v.y, 2) - (pow(v.z, 2) * pow(tan(A * pi / 180), 2));
    b = 2 * ((p.x * v.x) + (p.y * v.y) - (p.z * v.z * pow(tan(A * pi / 180), 2)));
    c = pow(p.x, 2) + pow(p.y, 2) - (pow(p.z, 2) * pow(tan(A * pi / 180), 2));
    if (a == 0)
        exit(84);
    dis = discriminant(a, b, c);
    if ((nb_soluce(a, b, c)) == 2) {
        printf("2 intersection points:\n");
        t = (-b + sqrt(dis)) / (temp * a);
        calc_point_l(p, v, t);
        t = (-b - sqrt(dis)) / (temp * a);
        calc_point_l(p, v, t);
        return 0;
    }
    if ((nb_soluce(a, b, c)) == 1) {
        printf("1 intersection point:\n");
        temp = 2 * a;
        t = (-b / temp);
        calc_point_l(p, v, t);
        return 0;
    }
    if ((nb_soluce(a, b, c)) == 0) {
        printf("No intersection point.\n");
        return 0;
    }
    return 0;
}
