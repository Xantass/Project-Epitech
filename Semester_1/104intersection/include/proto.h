/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** header
*/

#ifndef PROTO_H
#define PROTO_H

int check(char **argv);
int init(point_p *p, vecteur_t *v, double *r, char **argv);
int choose(char **argv);
int sphere(point_p p, vecteur_t v, double r);
int cylinder(point_p p, vecteur_t v, double r);
int cone(point_p p, vecteur_t v, double A);
double discriminant(double a, double b, double c);
int nb_soluce(double a, double b, double c);
void calc_point_l(point_p p, vecteur_t v, double t);
void print_usage(void);
#endif
