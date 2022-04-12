##
## EPITECH PROJECT, 2020
## makefile
## File description:
## fonction
##

SRC 	=	my_putchar.c	\
		my_putchar_p.c	\
		my_putnbr_p.c	\
		convert_base_p.c	\
		my_getnbr.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strlen.c	\
		convert_octa_p.c	\
		none_assigned.c	\
		convert_hexa_p.c	\
		convert_hexaup_p.c	\
		none_printable.c	\
		convert_binaire_p.c	\
		pourcen.c	\
		pass_one.c	\
		pass_two.c	\
		pass_three.c	\
		my_printf.c	\
		my_putstr_p.c	

OBJ 	=	$(SRC:.c=.o)	

NAME	=	libmy.a

NAMEMY	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	mkdir -p ../../include
	cp $(NAMEMY) ../../include
clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~

re: fclean all
