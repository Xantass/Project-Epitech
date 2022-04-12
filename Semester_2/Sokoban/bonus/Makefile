##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	boostrap.c	\
		chain_list.c	\
		check.c	\
		check_bis.c	\
		init.c	\
		game_interface.c	\
		script.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CC	=	gcc

MAKE	=	make

CFLAGS	=	-I./include/ -Wall -Wextra -g3

LDFLAGS	=	-lncurses	

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -C lib/my/
	@$(CC) -o $(NAME) $(OBJ) -L./lib/my/ -lmy $(LDFLAGS)
clean:
	@$(MAKE) clean -C lib/my
	@rm -f $(OBJ)
	@rm -f vgcore*
	@rm -f *~

fclean: clean
	@$(MAKE) fclean -C lib/my
	@rm -f $(NAME)

re: fclean all

debug: 		$(OBJ)
	@$(MAKE) -C lib/my/
	@gcc -o $(NAME) $(OBJ) -L./lib/my/ -lmy -g3 $(LDFLAGS)
	@$(MAKE) fclean -C lib/my
	@rm -f $(OBJ)
	@rm -f vgcore*
	@rm -f *~
