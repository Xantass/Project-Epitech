##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	./src/chain_list.c	\
		./src/algo.c	\
		./src/algo_bis.c	\
		./src/main.c	\
		./src/calc_bis.c	\
		./src/calc.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

NAMETEST	=	test_run

TEST	=	./tests/test_unitaire.c	\
		./src/chain_list.c	\
		./src/algo.c	\
		./src/algo_bis.c	\
		./src/calc_bis.c	\
		./src/calc.c

OBJTEST	=	$(TEST:.c=.o)

CC	=	gcc

MAKE	=	make

CFLAGS	=	-I./include/ -Wall -Wextra -g3

LDFLAGS	=	-lm -lc

all:	$(NAME)

tests_run: CFLAGS += --coverage

tests_run: $(OBJTEST)
	@$(MAKE) -C ./lib/my/
	@$(CC) -o $(NAMETEST) $(OBJTEST) -L./lib/my -lmy -lcriterion -lgcov
	@./test_run
	@gcovr

$(NAME):	$(OBJ)
	@$(MAKE) -C lib/my/
	@$(CC) -o $(NAME) $(OBJ) -L./lib/my/ -lmy $(CPPFLAG)
clean:
	@$(MAKE) clean -C lib/my
	@rm -f $(OBJ)
	@rm -f vgcore*
	@rm -f *~
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f ./tests/test_unitaire.gcda
	@rm -f ./tests/test_unitaire.gcno
	@rm -f ./tests/test_unitaire.o

fclean: clean
	@$(MAKE) fclean -C lib/my
	@rm -f $(NAME)
	@rm -f $(NAMETEST)

re: fclean all

debug: 		$(OBJ)
	@$(MAKE) -C lib/my/
	@gcc -o $(NAME) $(OBJ) -L./lib/my/ -lmy -g3 $(CPPFLAG)
	@$(MAKE) fclean -C lib/my
	@rm -f $(OBJ)
	@rm -f vgcore*
	@rm -f *~
