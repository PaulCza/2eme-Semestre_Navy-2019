/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** display.c
*/

#include "../include/navy.h"

void display_map(char **map)
{
    int y;
    int x;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    y = 0;
    while (y++ < 8) {
        x = 0;
        my_putnbr(y);
        my_putchar('|');
        while (x++ < 8) {
            my_putchar(map[y - 1][x - 1]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}