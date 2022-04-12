##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	mini_shell.c	\
		init.c	\
		cd.c	\
		set_env.c	\
		found_com_bis.c	\
		unset_env.c	\
		cd_bis.c	\
		found_com_bisss.c	\
		found_com.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CC	=	gcc

MAKE	=	make

CFLAGS	=	-I./include/ -Wall -Wextra -g3

LDFLAGS	=	-lm -lc

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -C lib/my/
	@$(CC) -o $(NAME) $(OBJ) -L./lib/my/ -lmy $(CPPFLAG)
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
	@gcc -o $(NAME) $(OBJ) -L./lib/my/ -lmy -g3 $(CPPFLAG)
	@$(MAKE) fclean -C lib/my
	@rm -f $(OBJ)
	@rm -f vgcore*
	@rm -f *~
