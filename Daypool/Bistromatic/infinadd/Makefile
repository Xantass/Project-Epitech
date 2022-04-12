EXECNAME = infin_add
SUBNAME = infin_sub

CC = gcc

INCL = ../include/

LIB = ../lib/my/

SRC = infinadd.c ../init_infin.c elses.c main.c

SUBSRC = infinadd.c infinsub.c ../init_infin.c elses.c init_infinsub.c submain.c

all:
	make -C $(LIB)
	$(CC) -o $(EXECNAME) -I$(INCL) -L$(LIB) $(SRC) -lmy
sub:
	make -C $(LIB)
	$(CC) -o $(SUBNAME) -I$(INCL) -L$(LIB) $(SUBSRC) -lmy
clean:
	make clean -C $(LIB)
	rm -f $(EXECNAME) $(SUBNAME)
fclean: clean
	make clean -C $(LIB)
	rm -f $(EXECNAME)
re:
	make clean -C $(LIB)
	rm -f $(EXECNAME)
	make -C $(LIB)
	$(CC) -o $(EXECNAME) -I$(INCL) -L$(LIB) $(SRC) -lmy
