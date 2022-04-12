##
## EPITECH PROJECT, 2021
## Root-Makefile
## File description:
## Makefile
##

MAKE	=		make

MAKE_REDEBUG	=	make redebug

MAKE_FCLEAN	=	make fclean

MAKE_RE	=	fclean all

all:
	$(MAKE) -C ./antman/
	$(MAKE) -C ./giantman/

redebug:
	$(MAKE_REDEBUG) -C ./antman/
	$(MAKE_REDEBUG) -C ./giantman/

fclean:
	rm -f *~
	rm -f ./tests/*~
	$(MAKE_FCLEAN) -C ./antman/
	$(MAKE_FCLEAN) -C ./giantman/

re:	fclean all

