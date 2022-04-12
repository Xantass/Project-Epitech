##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_char_isnum.c	\
		my_memset.c	\
		my_calloc.c	\
		my_char_isalpha.c	\
		my_strncpy.c	\
		int_to_char.c	\
		my_char_isoperator.c	\
		my_str_islower.c	\
		my_strlen.c	\
		my_str_isnum.c	\
		my_str_isalpha.c	\
		my_sort_int_array.c	\
		my_get_number.c	\
		my_strncmp.c	\
		my_isneg.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_putchar.c	\
		my_put_number.c	\
		my_swap.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strdup.c	\
		my_strcat.c	\
		twa.c	\
		print_tab.c	\
		free_tab.c	\
		calloc_tab.c	\
		clean_str.c	\
		fill_tab_with_char.c	\
		read_from_file.c	\
		switch_char_in_tab.c	\
		twa_bis.c	\
		unsigned_strlen.c	\
		throw_error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAMEMY	=	lib.h

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
