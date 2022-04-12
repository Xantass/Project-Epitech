/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#define SWAP_ENDIAN(x) ((x>>24)&0xff) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) |\
((x<<24)&0xff000000)

#define R 1
#define D 2
#define RD 3
#define I 4
#define DI 6
#define RDI 7
#define REG 'r'

#define OK NULL

#include <stdbool.h>
#include "op.h"

typedef struct file_t {
    char **file;
    char *filename;
    int nb;
}file_t;

typedef struct verif_t {
    int j;
    int i;
    int c;
}verif_t;

typedef struct inst {
    char **args;
    int op_code;
    int coding_byte;
    int byte;
    int line;
    int *size;
    int *hex;
    bool is_label;
    struct inst *next;
}inst_t;

typedef struct lbl {
    char *label;
    int byte;
    int line;
    struct lbl *next;
}lbl_t;

typedef struct info_t {
    char *filename;
    file_t file;
    header_t head;
    inst_t *ins;
    lbl_t *label;
}info_t;

#endif /* !STRUCT_H_ */
