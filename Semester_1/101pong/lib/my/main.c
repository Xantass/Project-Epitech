/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pong.h"

void intia_vecvelo(struct conste *velocity, struct conste *one,
                    struct conste *two);
void intia_pos1(char **argv, struct conste *two);
void intia_pos0(char **argv, struct conste *one);
void intia_vecf(struct conste *f, struct conste *one,
                 struct conste *two);
float norm(struct conste *f);
int error(int argc, char **argv);

void calc_coef(char **argv, struct conste *f)
{
    int i = atoi(argv[7]);

    f->x = (f->x * i);
    f->y = (f->y * i);
    f->z = (f->z * i);
}

void cord_at_n(struct conste *f, struct conste *two,
                struct conste *tree)
{   
    tree->x = (f->x) + (two->x);
    tree->y = (f->y) + (two->y);
    tree->z = (f->z) + (two->z);
}

float angle(struct conste *one, struct conste *velocity, struct conste *two)
{
    float res = 0;
    float pi = (3.1415926535);
    float x = 0;
    float norme = norm(velocity);
    float reach_one = velocity->z;
    float reach_two = two->z;

    if (reach_one < res && reach_two > res) {
        if (norme == 0)
            return 84;
        x = (one->y) / (norme);
        res = asin(x);
        res = res *(180 / pi);
        return res;
    }
    else {
        return res;
    }
}


void print(struct conste *velocity, struct conste *tree, float res, char **argv)
{
    int i = atoi(argv[7]);
    
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", velocity->x, velocity->y, velocity->z);
    printf("At time t + %d, ball coordinates will be:\n", i);
    printf("(%.2f, %.2f, %.2f)\n", tree->x, tree->y, tree->z);
    if (res == 0)
        printf("The ball won't reach the paddle.\n");
    else {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", res);
    }
}

int main(int argc, char **argv)
{
    if (argc == 1 || error(argc, argv) == 0)
        return 84;
    else {
    struct conste f = {0,0,0};
    struct conste tree = {0,0,0};
    struct conste two = {0,0,0};
    struct conste one = {0,0,0};
    struct conste velocity = {0,0,0};
    float res = 0;

    intia_pos0(argv, &one);
    intia_pos1(argv, &two);
    intia_vecvelo(&velocity, &one, &two);
    intia_vecf(&f, &one, &two);
    calc_coef(argv, &f);
    cord_at_n(&f, &two, &tree);
    res = angle(&one, &velocity, &two);
    print(&velocity, &tree, res, argv);
    return 0;
    }
}
