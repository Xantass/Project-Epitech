##
## EPITECH PROJECT, 2020
## makefile
## File description:
## bistro makefile
##

##MAKEFLAGS	+=	--silent

RM	=	-rm -rf

## @->que la ligne de commmande ne s'écrive pas dans le terminaladdprefix
## add_prefix-> pour eviter d'écrire le début dans src (lib/my par exemple)
# -r -> recurivse (chercher tous les dossiers)
# - ->si la commande rate par exemple si il y a deja des .o et qu on veut make, ca continue

# Source files
## Lib
LIB_SRC	=	\

## Project
SRC = \
	game_loop.c	\
	funcs_global.c	\
	create_from_f.c	\
	set_texture.c	\
	create_sprite.c	\
	draw.c	\
	pos.c	\
	hitbox_buttons.c	\
	norm_drawing.c	\
	hit_norm.c	\

## Unit Tests
UNIT_TEST_SRC  =   \
	unit_tests.c   \

## Main
MAIN_SRC    =   main.c

## Sources required by any rule
COMMON_SRC	=							\
	$(addprefix src/, $(SRC))			\
	$(addprefix lib/my/, $(LIB_SRC))

## Sources for the binary
BIN_SRC	=			\
	$(COMMON_SRC)	\
	$(MAIN_SRC)

## Sources for the unit tests
UT_SRC	=									\
	$(addprefix	tests/, $(UNIT_TEST_SRC))	\
	$(COMMON_SRC)

## Object files for binary
BIN_OBJ	=	$(BIN_SRC:.c=.o)

# Compilation flag
CPPFLAGS	=	-Iinclude
CFLAGS		=	-Wall -Wextra

# Binaries' names
NAME	=	my_rpg
TEST	=	unit_tests

# Compilation Rules
## Binary
all:    $(NAME)
$(NAME):    $(BIN_OBJ)
			gcc $(BIN_OBJ) -o $(NAME) $(CPPFLAGS) $(CFLAGS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

## Unit tests
tests_run: LDFLAGS	+= -lcriterion
tests_run: CFLAGS	+= --coverage
tests_run:
	gcc $(UT_SRC) -o $(TEST) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)
	./$(TEST)
	-@mkdir .tmp &> /dev/null
	-@mv test_*.gc* .tmp
	gcovr -r . --exclude-directories .tmp
	gcovr -r . -b --exclude-directories .tmp

## Debug
debug:	CFLAGS	+= -g3
debug:	all

## Rebuild all
re: fclean all
redbg: fclean debug

# Clean Rules
clean:
	$(RM) $(BIN_OBJ)
	$(RM) *.gc*
	$(RM) .tmp

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST)

# Misc
.PHONY: $(NAME) tests_run debug re redbg clean fclean