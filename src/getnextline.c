/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** getnextline.c
*/

#include "../include/navy.h"

int my_strlen(char *str)
{
    for (int i = 0; *str; i++, str++)
      if (*str + 1 == 0)
        return (i);
    return 0;
}

char *my_strncpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (n < i)
        dest[i] = '\0';
    return (dest);
}

char *add_line(int *st, char *line, int tr, char *buff)
{
    int oldl = 0;
    char *newl;

    if (line != 0)
        oldl = my_strlen(line);
    newl = malloc((oldl + tr + 1) * sizeof(*newl));
    if (!newl)
        return (NULL);
    if (line != 0)
        my_strncpy(newl, line, oldl);
    else
        my_strncpy(newl, "\0", oldl);
    newl[oldl + tr] = 0;
    my_strncpy(newl + oldl, buff + *st, tr);
    *st = *st + (tr + 1);
    free(line);
    return (newl);
}

char *get_next_line(int fd)
{
    static int st;
    static int nbbuff = 0;
    static char buff[READ_SIZE];
    int tr = 0;
    char *line = 0;

    do {
        if (nbbuff <= st) {
        st = 0;
        if (!(nbbuff = read(fd, buff, READ_SIZE)))
            return (line);
        if (nbbuff == -1)
            return (NULL);
        tr = 0;
        }
        if (buff[st + tr] == '\n')
            return (line = add_line(&st, line, tr, buff));
        else if (st + tr == nbbuff - 1)
            line = add_line(&st, line, tr + 1, buff);
        tr += 1;
    } while (1);
}
