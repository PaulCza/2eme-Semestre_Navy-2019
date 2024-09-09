/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print.c
*/

#include "../include/navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    while (*str != 0) {
    my_putchar(*str);
    str++;
    }
}