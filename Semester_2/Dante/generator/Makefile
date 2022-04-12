##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Generator
##

SRC	=	./source/main.c	\
		./source/error_handling.c	\
		./source/alloc_tab.c	\
		./source/core.c	\
		./source/print_map.c	\
		./source/algo.c	\
		./source/get_rand.c	\
		./source/build_perfect_maze.c	\
		./source/build_exit.c	\
		./source/set_perfect_maze.c

NAME	=	generator

SRC_TESTS	=	./tests/test.c	\
					./source/error_handling.c	\
			./source/alloc_tab.c	\
			./source/core.c	\
			./source/print_map.c	\
			./source/algo.c	\
			./source/get_rand.c	\
			./source/build_perfect_maze.c	\
			./source/build_exit.c	\
			./source/set_perfect_maze.c


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
	rm -f ./lib/libmy.a
	rm -f ./lib/my/libmy.a

re:	fclean all

redebug: fclean debug
