##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	./sources/main.c	\
		./sources/error_handling.c	\
		./sources/init.c	\
		./sources/map.c	\
		./sources/get_line.c 	\
		./sources/game.c 	\
		./sources/check_get_line.c	\
		./sources/map_modif.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

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
