##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##

SRC	=	main.c	\
		my_ls.c	\
		flag_r.c	\
		flag_d.c	\
		flag_l.c	\
		flag_l_bis.c	\
		flag_t.c	\
		filepath.c	\
		alpha_tri.c	\
		print.c	

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

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
