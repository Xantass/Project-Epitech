##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Mini-Shell_1
##

SRC	=	./source/asm_.c	\
		./source/check_type.c	\
		./source/create_linked_list.c	\
		./source/error.c	\
		./source/free.c	\
		./source/get_file.c	\
		./source/get.c	\
		./source/is_functions.c	\
		./source/label.c	\
		./source/main.c	\
		./source/my_str_to_word_array.c	\
		./source/op.c	\
		./source/parser_bis.c	\
		./source/parser.c	\
		./source/set_header.c	\
		./source/set_instruction.c	\
		./source/usage.c	\
		./source/write.c

NAME	=	asm

SRC_TESTS	=	./tests/tests.c	\
			./source/asm_.c	\
			./source/check_type.c	\
			./source/create_linked_list.c	\
			./source/error.c	\
			./source/free.c	\
			./source/get_file.c	\
			./source/get.c	\
			./source/is_functions.c	\
			./source/label.c	\
			./source/my_str_to_word_array.c	\
			./source/op.c	\
			./source/parser_bis.c	\
			./source/parser.c	\
			./source/set_header.c	\
			./source/set_instruction.c	\
			./source/usage.c	\
			./source/write.c

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	tests_run

MAKE	=	make

CPPFLAGS	=	-iquote ./include/

CFLAGS	=	-Wall -Wextra -Wshift-overflow=0

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CPPFLAGS) -L./lib -lmy

debug:	CFLAGS	+= -g3
debug:	all

tests_run: CFLAGS += --coverage
tests_run: $(OBJ_TESTS)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME_TESTS) $(OBJ_TESTS) -L./lib -lmy -lcriterion -lgcov
	./tests_run

clean:
	rm -f $(OBJ) $(OBJ_TESTS)
	make clean -C ./lib/my

fclean: clean
	rm -f ./include/*~
	rm -f ./tests/*~
	rm -f ./tests/*.gcno
	rm -f ./tests/*.gcda
	rm -f ./source/*.gcno
	rm -f ./source/*.gcda
	rm -f ./source/*~
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~
	rm -f tests_run
	rm -f $(NAME)
	rm -f ./lib/libmy.a
	rm -f ./lib/my/libmy.a

re:	fclean all

redebug: fclean debug
