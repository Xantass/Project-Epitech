##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Navy
##

SRC	=	./source/main.c	\
		./source/signal.c	\
		./source/game_bis.c	\
		./source/signal_handler.c	\
		./source/get_binary.c	\
		./source/my_get_number_mod.c	\
		./source/my_strcat.c	\
		./source/turn.c	\
		./source/turn_bis.c	\
		./source/turn_ter.c	\
		./source/turn_four.c	\
		./source/game_biss.c	\
		./source/game.c	\
		./source/my_str_to_word_array.c	\
		./source/print.c	\

NAME	=	navy

SRC_TESTS	=	main.c
OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	test_run

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
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) $(CPPFLAGS) -L./lib -lmy --coverage -lcriterion

clean:
	rm -f $(OBJ) $(OBJ_TESTS)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)

re:	fclean all

redebug: fclean debug
