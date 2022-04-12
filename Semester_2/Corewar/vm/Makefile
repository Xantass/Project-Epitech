##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Mini-Shell_1
##

SRC	=	./source/main.c	\
		./source/op.c 	\
		./source/handle_args.c	\
		./source/handle_prog_numbers.c	\
		./source/swap_prog_info_node.c	\
		./source/read_champions.c	\
		./source/error_handling.c	\
		./source/core.c	\
		./source/calc.c	\
		./source/decode_instructions.c	\
		./source/operation/add.c	\
		./source/operation/exec_t_add.c	  \
		./source/operation/exec_t_aff.c	 \
		./source/operation/exec_t_and.c	 \
		./source/operation/exec_t_fork.c	 \
		./source/operation/exec_t_ld.c	 \
		./source/operation/exec_t_ldi.c	 \
		./source/operation/exec_t_lfork.c	 \
		./source/operation/exec_t_live.c	 \
		./source/operation/exec_t_lld.c	 \
		./source/operation/exec_t_lldi.c	 \
		./source/operation/exec_t_or.c	 \
		./source/operation/exec_t_st.c	 \
		./source/operation/exec_t_sti.c	 \
		./source/operation/exec_t_sub.c	 \
		./source/operation/exec_t_xor.c	 \
		./source/operation/exec_t_zjmp.c	 \
		./source/operation/and.c	\
		./source/operation/ld.c	\
		./source/operation/lfork.c	\
		./source/operation/lld.c	\
		./source/operation/or.c	\
		./source/operation/sti.c	\
		./source/operation/xor.c	\
		./source/operation/aff.c	\
		./source/operation/fork.c	\
		./source/operation/ldi.c	\
		./source/operation/live.c	\
		./source/operation/lldi.c	\
		./source/operation/st.c	\
		./source/operation/sub.c	\
		./source/operation/zjmp.c	\
		./source/init_info.c	\
		./source/winner.c	\
		./source/is_available.c	\
		./source/bool_op.c 	\
		./source/coding_byte.c 	\
		./source/get_args.c	\
		./source/set_arena.c	\
		./source/dump_arena.c	\
		./source/free_info.c

NAME	=	corewar

SRC_TESTS	=

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
