##
## EPITECH PROJECT, 2020
## MakefileEvalExpr
## File description:
## fmewiofnei
##

LIBDIR  = ./lib/my

CC      = gcc
CCFLAGS = -lmy

SRC     = ./infinadd/elses.c ./infinadd/infinadd.c ./infinadd/infinsub.c  ./infinadd/init_infinsub.c\
		  ./infindiv/divelses.c ./infindiv/infindiv.c ./infindiv/init_infindiv.c\
		  ./infinmod/infinmod.c ./infinmod/infinmodbis.c	\
		  ./infinmult/infinmult.c ./infinmult/init_infinmult.c\
		  ./init_infin.c\
		  bistro.c my_compute_errors.c my_usage.c add_nums_to_array.c
BIN     = calc

LIB     = ./lib
INCL    = ./include

all:
	make -C $(LIBDIR)
	$(CC) -o $(BIN) -I$(INCL) -L$(LIB) $(SRC) $(CCFLAGS)

clean:
	make clean -C $(LIBDIR)
	rm -f $(BIN)

fclean:
	make fclean -C $(LIBDIR)
	rm -f $(BIN)

re: fclean all

test:
	make -C tests/
