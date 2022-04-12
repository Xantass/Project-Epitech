##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## function
##

SRC	=	drawn_line.c	\
		shape.c	\
		usages.c	\
		create.c

NAME	=	my_screensaver

SRC_TESTS	=	sfml_test.c
OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	test_run

CSFML	=	-lcsfml-graphics -lcsfml-window

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra -lm

all:	$(OBJ)
	$(MAKE) -C lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CSFML) $(CPPFLAGS) -L./lib/my/ -lmy

debug:	CFLAGS	+= -g3
debug:	all
	rm -f $(OBJ) $(OBJ_TESTS)

tests_run: $(OBJ_TESTS)
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) $(CPPFLAGS) --coverage -lcriterion

clean:
	$(MAKE) clean -C lib/my
	rm -f $(OBJ) $(OBJ_TESTS)

fclean: clean
	$(MAKE) fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

redebug: fclean debug
