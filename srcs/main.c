/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unsold.h"

int help()
{
    printf("USAGE\n    ./202 unsold a b\n");
    printf("DESCRIPTION\n");
    printf("    a\t constant computed from past results\n");
    printf("    b\t constant computed from past results");
    exit(0);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp("-h", av[1]) == 0)
        help();
    if (error(ac, av) == 84)
        return (84);
    else
        unsold(av);
    return (0);
}
