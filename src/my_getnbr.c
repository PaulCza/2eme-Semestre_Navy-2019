/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}