##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## My_World
##

SRC	=		./source/main.c	\
			./source/window/display_window.c	\
			./source/window/init_window.c	\
			./source/calculs/compute_map.c	\
			./source/window/core.c	\
			./source/calculs/calc_translation.c	\
			./source/window/event.c	\
			./source/calculs/translation.c	\
			./source/window/button_texture.c	\
			./source/window/buttons.c	\
			./source/window/buttons_bis.c	\
			./source/window/handle_click.c	\
			./source/window/set_font.c	\
			./source/window/print_info.c	\
			./source/window/get_input.c	\
			./source/calculs/init_map.c	\
			./source/calculs/convex.c	\
			./source/calculs/resize_map.c	\
			./source/calculs/rotation.c 	\
			./source/calculs/calc_rotation.c	\
			./source/window/set_cadre.c	\
			./source/map/modif_point.c 	\
			./source/window/get_selected_zone.c	\
			./source/window/mouse_hitbox.c
NAME	=	my_world

SRC_TESTS	=	./source/exec.c	\
			./source/load_arg.c	\
			./source/get_cmd.c	\
			./source/core.c	\
			./source/cd.c	\
			./source/exit.c	\
			./source/setenv.c	\
			./source/unsetenv.c	\
			./source/get_path.c	\
			./source/inspect_paths.c	\
			./source/setenv_bis.c	\
			./source/get_paths_bis.c	\
			./source/update_pwd.c	\
			./source/setenv_ter.c	\
			./tests/units_tests.c


OBJ	=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	tests_run

CSFML	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

MAKE	=	make

CPPFLAGS	=	-I./include/

CFLAGS	=	-Wall -Wextra

all:	$(OBJ)
	$(MAKE) -C ./lib/my/
	gcc -o $(NAME) -lm $(OBJ) $(CSFML) $(CPPFLAGS) -L./lib -lmy

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

re:	fclean all

redebug: fclean debug
