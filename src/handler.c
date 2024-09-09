/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** handler.c
*/

#include "navy.h"

void user1(int signal, int *act)
{
    my_putstr("user 1\nglobal = ");
    global += 1;
    my_putnbr(global);
    my_putchar('\n');
}

void user2(int signal, int * act)
{
    my_putstr("user 2\nglobal = ");
    global += 1;
    my_putnbr(global);
    my_putchar('\n');
}

int comp(char l, char *str)
{
    for (int i = 0;str[i] != '\0'; i++)
        if (str[i] == l)
            return (i);
    return (-1);
}