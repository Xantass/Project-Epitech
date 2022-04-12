##
## EPITECH PROJECT, 2020
## makefile
## File description:
## fonction
##

SRC 	=	pong.c	\
		main.c	\
		error_management.c

OBJ 	=	$(SRC:.c=.o)	

NAME	=	libmy.a

NAMEMY	=	pong.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	mkdir -p ../../include
	cp $(NAMEMY) ../../include
clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
