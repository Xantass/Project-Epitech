/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_player_bis
*/

#include "lib.h"
#include "struct.h"

sfRectangleShape **create_spell(void);

static char **path(void)
{
    char **str = my_calloc(sizeof(char *), (12) + 1);

    for (unsigned int i = 0; i < 12; i++)
        str[i] = my_calloc(sizeof(char), (50) + 1);
    str[0] = my_strdup("sprites/Character/perso (1).png");
    str[1] = my_strdup("sprites/Character/perso (2).png");
    str[2] = my_strdup("sprites/Character/perso (3).png");
    str[3] = my_strdup("sprites/Character/perso (4).png");
    str[4] = my_strdup("sprites/Character/perso (5).png");
    str[5] = my_strdup("sprites/Character/perso (6).png");
    str[6] = my_strdup("sprites/Character/perso (7).png");
    str[7] = my_strdup("sprites/Character/perso (8).png");
    str[8] = my_strdup("sprites/Character/perso (9).png");
    str[9] = my_strdup("sprites/Character/perso (10).png");
    str[10] = my_strdup("sprites/Character/perso (11).png");
    str[11] = my_strdup("sprites/Character/perso (12).png");
    return str;
}

static sfTexture **create_texture(char **str)
{
    sfTexture **textures = {0};

    textures = malloc(sizeof(sfTexture *) * 14);
    for (int i = 0; i < 12; ++i)
        textures[i] = sfTexture_createFromFile(str[i], NULL);
    return textures;
}

static sfRectangleShape *init_player(sfTexture *texture)
{
    sfRectangleShape *player = sfRectangleShape_create();
    sfVector2f position = {990, 590};
    sfVector2f size = {50, 50};

    sfRectangleShape_setPosition(player, position);
    sfRectangleShape_setSize(player, size);
    sfRectangleShape_setTexture(player, texture, sfFalse);
    return player;
}

sfRectangleShape ***create_player_bis(void)
{
    char **str = path();
    sfRectangleShape ***player = {0};
    sfTexture **texture = create_texture(str);
    int k = 0;

    player = malloc(sizeof(sfRectangleShape **) * 5);
    for (int i = 0; i < 4; i++)
        player[i] = malloc(sizeof(sfRectangleShape *) * 3);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            player[i][j] = init_player(texture[k]);
            k++;
        }
    }
    player[4] = create_spell();
    return player;
}
