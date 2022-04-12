##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Corewar
##

MAKE	=		make

MAKE_REDEBUG	=	make redebug

MAKE_FLCEAN	=	make fclean

MAKE_TESTS_RUN	=	make tests_run

MAKE_RE	=		fclean all

all:
			$(MAKE) -C ./vm/
			$(MAKE) -C ./asm/

redebug:
			$(MAKE_REDEBUG) -C ./vm/
			$(MAKE_REDEBUG) -C ./asm/

fclean:
			rm -f *~
			rm -f ./corewar_binaries/*~
			$(MAKE_FLCEAN) -C ./vm/
			$(MAKE_FLCEAN) -C ./asm/

tests_run:
			$(MAKE_TESTS_RUN) -C ./vm/
			$(MAKE_TESTS_RUN) -C ./asm/

re: fclean all

