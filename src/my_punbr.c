/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_punbr.c
*/

#include "../include/navy.h"

int my_putnbr(int n)
{
    if (n == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_putnbr(147483648);
    } else if (n < 0) {
        my_putchar('-');
        my_putnbr(-n);
    }
    if (n > 9) {
        my_putnbr(n / 10);
        my_putchar(n % 10 + 48);
    } else if (n >= 0) {
        my_putchar(n + 48);
    }
    return (0);
}