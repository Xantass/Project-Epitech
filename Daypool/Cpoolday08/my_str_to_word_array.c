/*
** EPITECH PROJECT, 2020
** test_totale_number.
** File description:
** fontion
*/

#include <stdio.h>
#include <stdlib.h>

void *my_calloc(unsigned int size, unsigned int block);

int is_alphanum(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    }
    if (c >= 'A' && c <= 'Z') {
        return (1);
    }
    if (c >= '0' && c <= '9') {
        return (1);
    }
    return (0);
}

int totale_word(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        while (is_alphanum(str[i]) == 0)
            i++;
        j++;
        while (is_alphanum(str[i]) == 1)
            i++;
    }
    return (j);
}

char **alloc_memory(char *str, char **memory_word)
{
    int i = 0;
    int h = 0;
    int count = 0;

    while (str[i] != '\0') {
        while (is_alphanum(str[i]) == 0)
            i++;
        while (is_alphanum(str[i]) == 1) {
            i++;
            count++;
        }
        memory_word[h] = my_calloc(sizeof(char), count + 1);
        memory_word[h][count] = '\0';
        h++;
        count = 0;
    }
    return (memory_word);
}

char **cpy(char *str, char **memory_word)
{
    int i = 0;
    int h = 0;
    int g = 0;

    while (str[i] != '\0') {
        while (is_alphanum(str[i]) == 0)
            i++;
        while (is_alphanum(str[i]) == 1) {
            memory_word[h][g] = str[i];
            i++;
            g++;
        }
        h++;
        g = 0;
    }
    return (memory_word);
}

char **my_str_to_word_array(char *str)
{
    int word = totale_word(str);
    char **memory_word = malloc(sizeof(char *) * (word + 1));

    memory_word[word] = NULL;
    alloc_memory(str, memory_word);
    cpy(str, memory_word);
    return (memory_word);
}

int main(void)
{
    char *str = strdup("      dbejbbbndbedied       je m        ;;::;;;:,   '   7655         appelle      theo");
    int res = totale_word(str);
    char **result = my_str_to_word_array(str);
    int i = 0;

    printf("res = %d\n", res);
    while (result[i] != NULL) {
        printf("result[i] = %s\n", result[i]);
        i++;
    }
    free(result);
    free(str);
    return 0;
}
