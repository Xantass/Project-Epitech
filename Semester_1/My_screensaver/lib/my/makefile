##
## EPITECH PROJECT, 2020
## makefile
## File description:
## fonction
##

SRC 	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_showstr.c	\
		my_strcmp.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_swap.c	\
		my_compute_power_rec.c	\
		my_isneg.c 	\
		my_putstr.c	\
		my_sort_int_array.c	\
		my_strcpy.c	\
		my_str_isnum.c	\
		my_strlowcase.c	\
		my_strstr.c	\
		my_compute_square_root.c	\
		my_is_prime.c	\
		my_revstr.c	\
		my_strcapitalize.c	\
		my_strdup.c 	\
		my_str_isprintable.c	\
		my_strncat.c	\
		my_str_to_word_array.c	\
		my_find_prime_sup.c	\
		my_putchar.c	\
		my_showmem.c	\
		my_strcat.c	\
		my_str_isalpha.c	\
		my_str_isupper.c	\
		my_strncmp.c	\
		my_strupcase.c	\
		get_char.c	\
		my_calloc_bis.c	\
		my_calloc.c	

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

re: fclean all
