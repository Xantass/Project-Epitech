##
## EPITECH PROJECT, 2020
## 
## File description:
## 
##

SRC	=	main.c	\
		p1.bootstrap_evalxpr.c	\
		calculs.c	\
		do_operation.c	\
		my_get_number_expert.c	\
		int_to_char.c	\
		do_op_expert.c	\
		count_do_op.c
NAME	=	eval_expr

OBJ	=	$(SRC:.c=.o)

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -L./lib -lmy

debug:	CFLAGS	+= -g3 -g
debug:	all

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)

re:	fclean all

redebug: fclean debug
