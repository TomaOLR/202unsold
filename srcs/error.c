/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error.c
*/

#include <stdlib.h>

int check_num(char *av)
{
    for (int i = 0; av[i] != '\0'; i += 1)
        if (av[i] < '0' || av[i] > '9')
            return (84);
    return (0);
}

int error(int ac, char **av)
{
    if (ac < 3 || ac > 3)
        return (84);
    if (check_num(av[1]) == 84 || check_num(av[2]) == 84)
        return (84);
    if (atoi(av[1]) <= 50 || atoi(av[2]) <= 50)
        return (84);
    return (0);
}
