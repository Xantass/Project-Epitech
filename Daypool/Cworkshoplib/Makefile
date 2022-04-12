##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	test_unitaire.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	test_run

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(SRC) -Llib/my/ -lmy -g3 -Wall -Wextra
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
