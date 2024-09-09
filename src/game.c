/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game.c
*/

#include "../include/navy.h"

int game(Ship *ship, int ac, int start)
{
    while (1) {
        signal(SIGUSR1, user1);
        signal(SIGUSR2, user2);
        while (!start || global == 1);
        if (ac == 3) {
            my_putstr("my positions:\n");
            display_map(ship->map_enemy);
            my_putstr("enemy's positions:\n");
            display_map(ship->cpmap_enemy);
        }
        if (ac == 2) {
            my_putstr("my positions:\n");
            display_map(ship->map);
            my_putstr("enemy’s positions:\n");
            display_map(ship->cpmap);
        }
        pause();
    }
    return 0;
}