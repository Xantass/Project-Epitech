##
## EPITECH PROJECT, 2020
## 
## File description:
## 
##

SRC	=	my_compute_power_rec.c	\
		my_char_isnum.c	\
		my_showstr.c	\
		my_memset.c	\
		do-op.c	\
		my_calloc.c	\
		my_char_isalpha.c	\
		my_strncpy.c	\
		my_char_isoperator.c	\
		my_str_islower.c	\
		my_strlen.c	\
		my_str_isnum.c	\
		my_compute_square_root.c	\
		my_str_isalpha.c	\
		my_strlowcase.c	\
		my_find_prime_sup.c	\
		my_strcapitalize.c	\
		my_strncat.c	\
		my_sort_int_array.c	\
		my_get_number.c	\
		my_strcat.c	\
		my_strncmp.c	\
		my_isneg.c	\
		my_strcmp.c	\
		my_is_prime.c	\
		my_strcpy.c	\
		my_putchar.c	\
		my_strupcase.c	\
		my_put_number.c	\
		my_swap.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_str_to_word_array.c	\
		my_str_isprintable.c	\
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAMEMY	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir -p ../../include
	cp $(NAMEMY) ../../include
clean:
	rm -f $(OBJ)
debug: CFLAGS += -g3
fclean : clean
	rm -f $(NAME)

re:	fclean all
