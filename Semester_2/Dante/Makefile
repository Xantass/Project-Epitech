##
## EPITECH PROJECT, 2021
## Root-Makefile
## File description:
## Makefile
##

MAKE	=		make

MAKE_REDEBUG	=	make redebug

MAKE_FCLEAN	=	make fclean

MAKE_TESTS_RUN	=	make tests_run

MAKE_RE	=	fclean all

all:
	$(MAKE) -C ./generator/
	$(MAKE) -C ./solver/

redebug:
	$(MAKE_REDEBUG) -C ./generator/
	$(MAKE_REDEBUG) -C ./solver/

fclean:
	rm -f *~
	rm -f ./tests/*~
	$(MAKE_FCLEAN) -C ./generator/
	$(MAKE_FCLEAN) -C ./solver/

tests_run:
	$(MAKE_TESTS_RUN) -C ./generator/
	$(MAKE_TESTS_RUN) -C ./solver/

re:	fclean all
