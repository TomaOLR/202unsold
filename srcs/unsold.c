/*
** EPITECH PROJECT, 2021
** unsold.c
** File description:
** unsold.c
*/

#include <stdio.h>
#include <stdlib.h>

void pz(float **tab);

void print_start(void)
{
    printf ("--------------------------------------------------------------------------------\n\t");
    for (int i = 10; i < 60; i += 10)
        printf("X=%d    ", i);
    printf ("Y law\n");
}

float **to_tab_sec(float **tab)
{
    float res = 0.0;

    tab[5][5] = 1.0;
    for (int i = 0; i < 5; i++, res = 0.0)
        for (int j = 0; j < 5; j++) {
            res += tab[j][i];
        tab[5][i] = res;
    }
    for (int j = 0; j < 5; j++, res = 0.0) {
        for (int i = 0; i < 5; i++)
            res += tab[j][i];
        tab[j][5] = res;
    }
    tab[5][5] = 1.0;
    for (int i = 0; i < 5; i++, res = 0.0)
        for (int j = 0; j < 5; j++) {
            res += tab[j][i];
        tab[5][i] = res;
    }
    return (tab);
}

float **to_tab(char **av)
{
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    float res = 0.0;
    float **tab = malloc(sizeof(float *) * 6);

    for (int i = 0; i < 6; i++)
        tab[i] = malloc(sizeof(float) * 6);
    for (int y = 10; y < 60; y += 10) {
        for (int x = 10; x < 60; x += 10) {
            tab[y / 10 - 1][x / 10 - 1] = ((a - x) * (b - y));
            tab[y / 10 - 1][x / 10 - 1] /= ((5 * a) - 150) * ((5 * b) - 150);
        }
    }
    for (int j = 0; j < 5; j++, res = 0.0) {
        for (int i = 0; i < 5; i++)
            res += tab[j][i];
        tab[j][5] = res;
    }
    return (to_tab_sec(tab));
}

void unsold(char **av)
{
    int x = 10;
    int y = 10;
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    float res = 0.0;
    float **tab = to_tab(av);

    print_start();
    for (int j = 0; j < 6; j++, y += 10) {
        j != 5 ? printf ("Y=%d    ", y) : printf("X law   ");
        for (int i = 0; i < 6; i++) {
            if (i == 0)
                printf("%.3f", tab[j][i]);
            else
                printf("   %.3f", tab[j][i]);
        }
        printf("\n");
    }
    printf ("--------------------------------------------------------------------------------\n");
    pz(tab);
}
