/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "navy.h"

void receive(int sig, struct siginfo_t *infos, void *context)
{
    if (sig == SIGUSR1);
}

char get_action(void)
{
    struct sigaction act;

    act.sa_sigaction = &receive;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, 0);
    sigaction(SIGUSR2, &act, 0);
    return (0);
}

void handler(int sig, struct siginfo_t *siginfo, void *context)
{
    int i = 0;
    int *act = NULL;

    for (; 1; i++) {
        sigaction(SIGUSR1, user1, 0);
        sigaction(SIGUSR2, user2, 0);
        while (!act);
    }
}

int navy(int argc, const char **argv, pid_t pid)
{
    ship = (Ship *)malloc(sizeof(*ship));
    int fd;
    int start = NULL;

    if (create_map(argc, argv, ship) == 84)
        return (84);
    if (argc == 3) {
        if ((fd = open(argv[2], O_RDONLY)) == 0)
            return (84);
        kill(SIGUSR1, user1);
        my_putstr("my_pid: ");
        my_putnbr(pid);
        my_putstr("\nsuccessfully connected\n\n");
        start = 1;
        setmap_enemy(ship);
    } else {
        if ((fd = open(argv[1], O_RDONLY)) == -1)
            return (84);
        my_putstr("my_pid: ");
        my_putnbr(pid);
        global = pid;
        my_putstr("\nwaiting for enemy connection...\n\n");
        setmap(ship);
    } game(ship, argc, start);
    return (ship->winner);
}