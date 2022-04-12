##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

NAME	=	101pong

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(SRC) -Llib/my/ -lmy -g3 -Wall -Wextra -lm
clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all
