##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## hi
##
SRC	=	./lib/my/convert_base_p.c	\
		./lib/my/convert_binaire_p.c	\
		./lib/my/convert_hexa_p.c	\
		./lib/my/convert_hexaup_p.c	\
		./lib/my/convert_octa_p.c	\
		./lib/my/my_getnbr.c	\
		./lib/my/my_printf.c	\
		./lib/my/my_putchar.c	\
		./lib/my/my_putchar_p.c	\
		./lib/my/my_put_nbr.c	\
		./lib/my/my_putnbr_p.c	\
		./lib/my/my_putstr.c	\
		./lib/my/my_putstr_p.c	\
		./lib/my/my_revstr.c	\
		./lib/my/my_strlen.c	\
		./lib/my/none_assigned.c	\
		./lib/my/none_printable.c	\
		./lib/my/pass_one.c	\
		./lib/my/pass_two.c	\
		./lib/my/pass_three.c	\
		./lib/my/pourcen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	printf

NAMETEST	=	test_run

TEST	=	./test/test_unitaire.c	\
		./lib/my/my_printf.c	\
		./lib/my/pass_three.c	\
		./lib/my/pass_two.c	\
		./lib/my/pass_one.c	

OBJTEST	=	$(TEST:.c=.o)

NAMENY	=	libmy.a

CC	=	gcc

MAKE	=	make

CFLAGS	=	-I./include/ -Wall -Wextra -g3

LDFLAGS	=	-lm -lc

all:	$(OBJ)
	@ar rc $(NAMENY) $(OBJ)

$(NAME):	$(OBJ)
	@ar rc $(NAMENY) $(OBJ)

test_run: CFLAGS += --coverage

test_run: $(OBJTEST)
	@$(MAKE) -C ./lib/my/
	@$(CC) -o $(NAMETEST) $(OBJTEST) -L./lib/my -lmy -lcriterion -lgcov

clean:
	@$(MAKE) clean -C ./lib/my/
	@rm -f vgcore*
	@rm -f *~
	@rm -f $(OBJTEST)

fclean: clean
	@$(MAKE) fclean -C ./lib/my/
	@rm -f $(NAME)
	@rm -f $(NAMETEST)
	@rm -f $(NAMENY)

re: fclean all

debug: 		$(OBJ)
	@$(MAKE) -C ./lib/my/
	@$(CC) -o $(NAME) -L./lib/my -lmy
	@$(MAKE) clean -C ./lib/my/
	@$(MAKE) fclean -C ./lib/my
	@rm -f vgcore*
	@rm -f *~
