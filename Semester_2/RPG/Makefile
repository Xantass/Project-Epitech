##
## EPITECH PROJECT, 2020
## makefile
## File description:
## bistro makefile
##

MAKEFLAGS	+=	--silent

RM	=	-rm -rf

## @->que la ligne de commmande ne s'écrive pas dans le terminaladdprefix
## add_prefix-> pour eviter d'écrire le début dans src (lib/my par exemple)
# -r -> recurivse (chercher tous les dossiers)
# - ->si la commande rate par exemple si il y a deja des .o et qu on veut make, ca continue

# Source files
## Lib
LIB_SRC	=	my_char_isnum.c	\
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
		my_strcat.c\

## Project
SRC = \
	display.c	\
	init_window.c	\
	event.c	\
	linked_lists.c	\
	create_map.c	\
	init_map.c	\
	create_player.c	\
	moves.c	\
	map_event_bis.c 	\
	map_event.c	\
	create_music.c	\
	modif.c	\
	check_move_part_one.c	\
	check_move_part_two.c	\
	check_move_part_three.c	\
	init.c	\
	load_hero_status.c	\
	handle_clock.c	\
	handle_inventory.c	\
	init_inventory.c	\
	create_elem_natu.c	\
	display_particule.c	\
	init_struct_anim.c	\
	load_items.c	\
	create_player_bis.c	\
	moves_bis.c	\
	display_pnj.c	\
	create_pnj.c	\
	handle_status_bar.c	\
	load_hero_info.c	\
	move_sprites.c	\
	load_equiped_stuff.c	\
	load_avatar.c	\
	create_quest.c	\
	create_dialog.c	\
	handle_drag_and_drop.c	\
	print_stats.c	\
	load_stats_value.c	\
	display_diag_bis.c	\
	print_stats_bis.c	\
	free_hero.c	\
	create_box.c	\
	free_info.c	\
	handle_skills_tree.c	\
	load_locked_sprites.c	\
	up_items.c	\
	up_items_bis.c	\
	load_xp_slot.c	\
	handle_xp.c	\
	quests_reward.c	\
	create_spell.c	\
	spell.c	\
	display_sound_effects.c	\
	create_orque.c	\
	read_cfg.c	\
	create_dragon.c	\
	create_boss.c	\
	alea.c	\
	create_fight.c	\
	menu_particules.c	\
	bestiaire.c	\
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
	display_min_map_ext.c	\
	display_int_map.c

## Unit Tests
UNIT_TEST_SRC  =   \
	unit_tests.c   \

## Main
MAIN_SRC    =   main.c

## Sources required by any rule
COMMON_SRC	=							\
	$(addprefix source/, $(SRC))			\
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
NAME	=	myrpg
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
