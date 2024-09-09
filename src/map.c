/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** map.c
*/

#include "navy.h"

int getPosiLetre(char c)
{
    char *str = "ABCDEFGH";

    for (int i = 0; *str; str++, i++)
        if (*str == c)
            return i;
    return (-1);
}

void setmap_enemy(Ship *ship)
{
    ship->map_enemy = malloc(sizeof(char *) * 9);
    ship->cpmap = malloc(sizeof(char *) * 9);
    ship->cpmap_enemy = malloc(sizeof(char *) * 9);
    for (size_t y = 0; y++ < 8;) {
        ship->map_enemy[y - 1] = malloc(sizeof(char) * 9);
        ship->cpmap[y - 1] = malloc(sizeof(char) * 9);
        ship->cpmap_enemy[y - 1] = malloc(sizeof(char) * 9);
        for (size_t x = 0; x++ < 8;) {
            ship->map_enemy[y - 1][x - 1] = '.';
            ship->map_enemy[y - 1][x] = 0;
            ship->cpmap[y - 1][x - 1] = '.';
            ship->cpmap[y - 1][x] = 0;
            ship->cpmap_enemy[y - 1][x - 1] = '.';
            ship->cpmap_enemy[y - 1][x] = 0;
        }
        ship->map_enemy[y] = 0;
        ship->cpmap[y] = 0;
        ship->cpmap_enemy[y] = 0;
    } for (size_t i = 0; i < 4; i++) {
        if (ship->Lship[i][0] == ship->Lship[i][1])
            for (size_t j = 0; ship->Pship[i][0] + j <= ship->Pship[i][1]; j++)
                ship->map_enemy[ship->Pship[i][0] + j - 1]\
                [getPosiLetre(ship->Lship[i][0])] = (char)(i + 2 + '0');
        else
            for (size_t j = 0; ship->Lship[i][0] + j <= ship->Lship[i][1]; j++)
                ship->map_enemy[ship->Pship[i][0] - 1]\
                [getPosiLetre(ship->Lship[i][0]) + j] = (char)(i + 2 + '0');
    }
}

void setmap(Ship *ship)
{
    ship->map = malloc(sizeof(char *) * 9);
    ship->cpmap = malloc(sizeof(char *) * 9);
    ship->cpmap_enemy = malloc(sizeof(char *) * 9);
    for (size_t y = 0; y++ < 8;) {
        ship->map[y - 1] = malloc(sizeof(char) * 9);
        ship->cpmap[y - 1] = malloc(sizeof(char) * 9);
        ship->cpmap_enemy[y - 1] = malloc(sizeof(char) * 9);
        for (size_t x = 0; x++ < 8;) {
            ship->map[y - 1][x - 1] = '.';
            ship->map[y - 1][x] = 0;
            ship->cpmap[y - 1][x - 1] = '.';
            ship->cpmap[y - 1][x] = 0;
            ship->cpmap_enemy[y - 1][x - 1] = '.';
            ship->cpmap_enemy[y - 1][x] = 0;
        }
        ship->map[y] = 0;
        ship->cpmap[y] = 0;
        ship->cpmap_enemy[y] = 0;
    }
    for (size_t i = 0; i < 4; i++) {
        if (ship->Lship[i][0] == ship->Lship[i][1])
            for (size_t j = 0; ship->Pship[i][0] + j <= ship->Pship[i][1]; j++)
                ship->map[ship->Pship[i][0] + j - 1]\
                [getPosiLetre(ship->Lship[i][0])] = (char)(i + 2 + '0');
        else
            for (size_t j = 0; ship->Lship[i][0]\
            + j <= ship->Lship[i][1]; j++) {
                ship->map[ship->Pship[i][0] - 1]\
                [getPosiLetre(ship->Lship[i][0]) + j] = (char)(i + 2 + '0');
            }
    }
}

void chekship(char c, char add_c, Ship *ship)
{
    static int i = 0;
    static int j = 0;

    if (c >= 'A' && c <= 'H') {
        ship->Lship[j][i] = c;
        ship->Pship[j][i] = add_c - '0';
        i++;
    }
    if (i == 2) {
        j++;
        i = 0;
    }
}

int create_map(int argc, char const **argv, Ship *ship)
{
    int fd;
    char *line;
    char **file = (char **)malloc(sizeof(char *[8]) * 5);

    if (argc == 3) {
        if ((fd = open(argv[2], O_RDONLY)) == -1)
            return (84);
    }
    else {
        if ((fd = open(argv[1], O_RDONLY)) == -1)
            return (84);
    }
    for (int i = 0; (line = get_next_line(fd)); i++) {
        file[i] = line;
        for (; *line; line++)
            chekship(*(line), line[1], ship);
    }
    close(fd);
    return (0);
}