##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## function
##

SRC	=	source/radar.c	\
		source/draw.c	\
		source/shape.c	\
		source/chain_list.c	\
		source/print.c	\
		source/error_man.c	\
		source/colision.c	\
		source/alea.c	\
		source/script.c

NAME	=	my_radar

SRC_TESTS	=	sfml_test.c
OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	test_run

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra -lm

all:	$(OBJ)
	$(MAKE) -C lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CSFML) $(CPPFLAGS) -L./lib/my/ -lmy -lm

debug:	CFLAGS	+= -g3
debug:	all
	rm -f $(OBJ) $(OBJ_TESTS)

tests_run: $(OBJ_TESTS)
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) $(CPPFLAGS) --coverage -lcriterion -lm

clean:
	$(MAKE) clean -C lib/my/
	rm -f $(OBJ) $(OBJ_TESTS)
	rm -f vgcore*
	rm -f *~

fclean: clean
	$(MAKE) fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all

redebug: debug clean
