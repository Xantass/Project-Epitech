##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CC	=	gcc

MAKE	=	make

CFLAGS	=	-I./include/ -Wall -Wextra

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

debug:		$(OBJ)
	@$(MAKE) -C lib/my/
	@gcc -o $(NAME) $(OBJ) -L./lib/my/ -lmy -g3 $(CPPFLAG)
	@$(MAKE) fclean -C lib/my
	@rm -f $(OBJ)
	@rm -f vgcore*
	@rm -f *~
