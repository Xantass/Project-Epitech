##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## antman
##

SRC	=	./source/main.c	\
		./source/error_handling.c	\
		./source/clean_up.c	\
		./source/load_arg.c	\
		./source/write_bit.c

NAME	=	antman

SRC_TESTS	=	./tests/tests_algo.c	\
			./source/algo.c	\
			./source/linked_lists.c	\
			./source/operations.c	\
			./source/operations_bis.c	\
			./source/operations_ter.c	\
			./source/algo_bis.c
OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	tests_run

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CPPFLAGS) -L./lib -lmy

debug:	CFLAGS	+= -g3
debug:	all

tests_run: CFLAGS += --coverage
tests_run: $(OBJ_TESTS)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) -L./lib -lmy -lcriterion -lgcov
	./tests_run

clean:
	rm -f $(OBJ) $(OBJ_TESTS)
	make clean -C ./lib/my

fclean: clean
	rm -f ./include/*~
	rm -f ./tests/*~
	rm -f ./tests/*.gcno
	rm -f ./tests/*.gcda
	rm -f ./source/*.gcno
	rm -f ./source/*.gcda
	rm -f ./source/*~
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~
	rm -f tests_run
	rm -f $(NAME)

re:	fclean all

redebug: fclean debug
