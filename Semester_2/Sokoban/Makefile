##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	./source/boostrap.c	\
		./source/chain_list.c	\
		./source/check.c	\
		./source/check_bis.c	\
		./source/init.c	\
		./source/script.c

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
