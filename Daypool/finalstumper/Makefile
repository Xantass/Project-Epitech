##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	*.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
