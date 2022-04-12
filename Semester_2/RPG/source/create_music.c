/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** create_music
*/

#include "graph.h"

sfMusic **create_music(void)
{
    sfMusic **music = {0};

    music = malloc(sizeof(sfMusic *) * 4);
    music[0] = sfMusic_createFromFile("Music/forest.ogg");
    sfMusic_setLoop(music[0], sfTrue);
    music[1] = sfMusic_createFromFile("Music/launch.ogg");
    sfMusic_setLoop(music[1], sfTrue);
    music[2] = sfMusic_createFromFile("Music/dungeon.ogg");
    sfMusic_setLoop(music[2], sfTrue);
    music[3] = sfMusic_createFromFile("Music/boss.ogg");
    sfMusic_setLoop(music[3], sfTrue);
    return music;
}