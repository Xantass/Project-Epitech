##
## EPITECH PROJECT, 2020
## makefile.c
## File description:
## fonction
##

SRC	=	do-op.c	\
		operation.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	do_op

MAKE	=	make

CPPFLAGS	=	-I./include

all:	$(NAME)
	$(MAKE) -C ../lib/my/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -L./lib -lmy -g3

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)


re:	fclean all
