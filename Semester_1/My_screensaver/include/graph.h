/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** function
*/

#ifndef MY_H
#define MY_H

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct framebuffer {
    unsigned int width;  
    unsigned int height;
    sfUint8 *pixels;
}framebuffer_t;

typedef struct shape_t {
    framebuffer_t *framebuffer;
    framebuffer_t *framebuffers;
    sfSprite *line_s;
    sfSprite *circle_s;
    sfTexture *circle_t;
    sfTexture *line_t;
}shape;
#endif
