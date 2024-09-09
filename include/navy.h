/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#if !defined(NAVY_)
#define NAVY_
#define READ_SIZE (80)

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct Ship Ship;
struct Ship
{
    char Lship[4][2];
    size_t Pship[4][2];
    char **map;
    char **cpmap;
    char **map_enemy;
    char **cpmap_enemy;
    int winner;
} *ship;

int global;
int my_getnbr(char *str);
void setmap(Ship *ship);
void setmap_enemy(Ship *ship);
void chekship(char c, char add_c, Ship *ship);
int create_map(int argc, char const **argv, Ship *ship);
char *get_next_line(int fd);
//void handler(int sig, struct siginfo_t *siginfo, void *context);
int rigor(int argc, const char **argv);
int comp(char l, char *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_strlen(char *str);
int my_putnbr(int n);
void user1(int signal, int *act);
void user2(int signal, int *act);
void display_map(char **map);
int game(Ship *ship, int ac, int start);
char get_action(void);

#endif //NAVY_
