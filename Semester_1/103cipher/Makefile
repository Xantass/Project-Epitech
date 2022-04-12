##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bistro-matic
##

SRC	=	boostrap.c	\
		calc_encrypted.c	\
		cipher.c	\
		print.c	\
		main.c

NAME	=	103cipher

OBJ	=	$(SRC:.c=.o)

NAME_TESTS	=	unit_tests

SRC_TESTS	=	./tests/test_unitaire.c	\
			boostrap.c	\
			calc_encrypted.c	\
			cipher.c	\
			print.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CPPFLAGS) -L./lib -lmy

debug:	CFLAGS	+= -g3
debug:	all

tests_run: CPPFLAGS	+= --coverage
tests_run: $(OBJ_TESTS)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) $(CPPFLAGS) -lm -L./lib -lmy -lcriterion
	./unit_tests
	gcovr

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TESTS)
	rm -f *.gcno
	rm -f *.gcda
	rm -f vgcore.*
	rm -f *~
	$(MAKE) clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)
	rm -f *.gcno
	rm -f vgcore.*
	rm -f *~
	$(MAKE) fclean -C ./lib/my/
re:	fclean all

redebug:  debug clean
