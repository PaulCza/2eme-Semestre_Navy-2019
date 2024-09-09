/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "../include/navy.h"

extern int global = 0;

void help(void)
{
    write(1, "./navy -h\n\
    USAGE\n\
    ./navy [first_player_pid] navy_positions\n\
    DESCRIPTION\n\
    first_player_pid:  only for the 2nd player.  pid of the first player.\n\
    navy_positions:  file representing the positions of the ships.\n", 222);
}

int rigor(int argc, const char **argv)
{
    if (argc == 3) {
        for (int i = 0; argv[1][i]; i++)
        {
            for (; argv[1][i] > '9' && argv[1][i] < '0';)
                return (84);
        }
    }
    if (argc != 2 && argc != 3)
        return (84);
    return (0);
}

int main(int argc, char const *argv[])
{
    pid_t pid = getpid();
    int win;

    if (win = navy(argc, argv, pid) == 84)
        return (84);
    return win;
}