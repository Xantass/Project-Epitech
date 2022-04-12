##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bistro-matic
##

SRC	=	main.c	\
		create.c	\
		print.c	\
		matrix.c	\
		usage.c	\
		calc.c

NAME	=	102architect

OBJ	=	$(SRC:.c=.o)

NAME_TESTS	=	unit_tests

SRC_TESTS	=	./tests/tests_pong.c	\
			usage.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CPPFLAGS) -L./lib -lmy

debug:	CFLAGS	+= -g3
debug:	all

tests_run: $(OBJ_TESTS)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) $(CPPFLAGS) -lm -L./lib -lmy --coverage -lcriterion

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f vgcore.*
	rm -f *~
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f vgcore.*
	rm -f *~
re:	fclean all

redebug: fclean debug
