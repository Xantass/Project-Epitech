##
## EPITECH PROJECT, 2020
## 
## File description:
## 
##

SRC	=	infin_add2.c	\
		negative.c	\

NAME	=	infin_add

OBJ	=	$(SRC:.c=.o)

MAKE	=	make

CPPFLAGS	=	-I./include/

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -L./lib -lmy -g3

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	rm -r include/

re:	fclean all
