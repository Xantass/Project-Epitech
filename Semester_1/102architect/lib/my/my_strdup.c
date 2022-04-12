/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *c);

char *my_str_dup(char const *src)
{
	int j = 0;
	int i = 0;

	while(src[j] != '\0') {
		j = j + 1;
	}
	
	char *memoire = malloc(sizeof(char) + (j + 1));
	
	while (src[i] != '\0') {
		memoire[i] = src[i];
		i = i + 1;
	}
	memoire [i] = '\0';
	return (memoire);
}
