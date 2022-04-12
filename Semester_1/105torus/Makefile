##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 105-Torus
##

SRC	=	./source/torus.c	\
		./source/calc.c	\
		./source/main.c

NAME	=	105torus

OBJ	=	$(SRC:.c=.o)

NAME_TESTS	=	unit_tests

SRC_TESTS	=	boostrap.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

all:	$(OBJ)
	gcc -o $(NAME) -lm $(OBJ) $(CPPFLAGS)

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

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)
	rm -f *.gcno
	rm -f vgcore.*
	rm -f *~
	rm -f ./source/*~
	rm -f ./source/*.o
re:	fclean all

redebug:  debug clean
