/*


** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int parser(char *str, int i, int j, int k, char **result);
int is_alphanum(char c);
int count_my_par(char *str, int i);
int count_my_result(int nb_1, int nb_2, char op);
int my_operator(char *str);
char *count_op(char *str);
int do_op_expert(char *op, char **tab);
char **get_nbr_expert(char *str, char  **tab_res);
char *trans(int nb);
char *final_count_op(char *str);

char **my_arraycpy(char **result, char *str)
{
    int k = 0;
    char **array_cpy = malloc(sizeof(char*) * (my_operator(str) + 1));

    while (k <= my_operator(str)) {
        array_cpy[k] = my_calloc(sizeof(char), (my_strlen(str) + 1));
        if (array_cpy[k] == NULL) {
            k = 0;
            return (0);
        }
        k = k + 1;
    }
    return (array_cpy);
}

int my_operator(char *str)
{
    int res = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (my_char_isoperator(str[i]) == 1)
            res = res + 1;
        i = i + 1;
    }
    return (res);
}

int eval_expr(char *str)
{
    int i = 0;
    int res = 0;
    int j = 0;
    int k = 0;
    my_putchar('0');
    my_putchar('\n');
    return (0);
    char **result = malloc(sizeof(char*) * (my_operator(str) + 1));

    printf("my_operator(str) = %d\n", my_operator(str));
    result[my_operator(str)] = NULL;
    if (my_operator(str) == 0)
        result[0] = my_calloc(sizeof(char), (my_strlen(str) + 1));
    while (j <= my_operator(str)) {
        result[j] = my_calloc(sizeof(char), (my_strlen(str) + 1));
        if (result[j] == NULL) {
            j = 0;
            return (0);
        }
        j = j + 1;
    }
    j = 0;
    res = parser(str, i, j, k, result);
    return (res);
}

int check_sub_add(char *str, int i, char **result, int j, int k)
{
    int o = i;
    char *op = count_op(&str[i + 1]);
    char **tab_res = my_arraycpy(result, str);
    int res_do_op = 0;

     while (str[i] != '+' && str[i] != '-' && str[i] != '\0') {
        if (str[i] == '*' || str[i] == '/' || str[i] == '%') {
            i = o;
    res_do_op = do_op_expert(op, get_nbr_expert(&str[i + 1], tab_res));
    result[j] = trans(res_do_op);
    return parser(str, i + 1, j + 1, k, result);
        }
        i = i + 1;
    }
    i = o;
    while (str[i] != '+' && str[i] != '-' && str[i] != '\0') {
        result[j][k] = str[i];
        result[j][k + 1] = '\0';
        i = i + 1;
    }
    return parser(str, i + 1, j + 1, k, result);
}

int parser(char *str, int i, int j, int k, char **result)
{
    if (is_alphanum(str[i]) == 1)
        return (84);
    switch (str[i]) {
    case ' ':
        return parser(str, i + 1, j, k, result);
        break;
    case '+':
        check_sub_add(str, i, result, j, k);
        break;
    case '-':
        check_sub_add(str, i, result, j, k);
        break;
    case '\0':
        break;
    default :
        result[j][k] = str[i];
        result[j][k + 1] = '\0';
        return parser(str, i + 1, j, k + 1, result);
    }
    my_put_number(do_op_expert(final_count_op(str), result));
    // printf("do op = %d\n", do_op_expert(final_count_op(str), result));
    printf("do_op = %s\n", trans(do_op_expert(final_count_op(str), result)));
    my_putchar('\n');
    return (84);
}
