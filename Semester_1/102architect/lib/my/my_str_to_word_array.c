/*

** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

int my_char_isalpha(char a);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
void *my_memset(char *s, int n, size_t size);
void *my_calloc(size_t nmemb, size_t size);

int my_char_isalpha_one(char const *str, int *i)
{
    if ((str[*i] >= 'A' && str[*i] <= 'Z') || (str[*i] >= 'a' && str[*i] <= 'z') ||
        (str[*i] >= '0' && str[*i] <= '9') ||
        (str[*i] == 95))
        return (1);
    else
        while (my_char_isalpha(str[*i + 1]) == 0) {
            *i = *i + 1;
        }
    return (0);
}

int count_words(char const *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0')
    {
        if (my_char_isalpha_one(str, &i) == 0)
            result = result + 1;
        i = i + 1;
    }
    return (result);
}

int init_my_array_of_array(char **result, int nb_limit, int size_of_result_i)
{
    int i = 0;

    while (i != nb_limit)
    {
        result[i] = my_calloc(sizeof(char), (size_of_result_i));
        if (result[i] == NULL)
            return 0;
        i = i + 1;
    }
    return (1);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int size_of_result_i = my_strlen(str) + 1;
    int nb_limit = count_words(str);
    char **result = my_calloc(sizeof(char*), (nb_limit) + 1);
    int k = 0;

    if (init_my_array_of_array(result, nb_limit, size_of_result_i) == 0) {
        return NULL;
    }
    while  (str[i] != '\0' )
    {
        if (my_char_isalpha_one(str, &i) == 0) {
            i = i + 1;
        }
        else {
            for (;my_char_isalpha(str[i]) == 1 && str[i] != '\0'; i = i + 1) {
                result[j][k] = str[i];
                k = k + 1;
            }
            j = j + 1;
            k = 0;
        }
    }
    return (result);
}
