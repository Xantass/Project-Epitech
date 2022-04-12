/*
** EPITECH PROJECT, 2021
** quests_reward.c
** File description:
** functions
*/

#include <stdio.h>
#include "hero.h"

void quest_one(hero_status_t *hero_status)
{
    static int is_rewarded = -1;

    if (is_rewarded == -1) {
        hero_status->actual_stats[2] += 110;
        is_rewarded *= -1;
    }
}

void quest_two(hero_status_t *hero_status)
{
    static int is_rewarded = -1;

    if (is_rewarded == -1) {
        hero_status->actual_stats[2] += 130;
        is_rewarded *= -1;
    }
}

void quest_three(hero_status_t *hero_status)
{
    static int is_rewarded = -1;

    if (is_rewarded == -1) {
        hero_status->actual_stats[2] += 150;
        is_rewarded *= -1;
    }
}

void quest_four(hero_status_t *hero_status)
{
    static int is_rewarded = -1;

    if (is_rewarded == -1) {
        hero_status->actual_stats[2] += 80;
        is_rewarded *= -1;
    }
}


