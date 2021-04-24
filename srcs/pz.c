/*
** EPITECH PROJECT, 2021
** pz
** File description:
** functions
*/

#include <stdio.h>
#include <stdlib.h>

void print_z_start()
{
    printf("z       ");
    printf("20");
    for (int i = 30; i < 110; i += 10)
        printf("      %d", i);
    printf("\np(Z=z)  ");
}

void ev_x(float **tab)
{
    float res = 0.0;
    float i = 10.0;
    float moy = 0.0;

    for (int nb = 0; nb < 5; nb++, i += 10.0)
        res += (tab[5][nb] * i);
    printf("expected value of X: \t%.1f\n", res);
    moy = 10.0 * tab[5][0] + 20.0 * tab[5][1] + 30.0 * tab[5][2]
        + 40.0 * tab[5][3] + 50.0 * tab[5][4];
    res = tab[5][0] * (10.0 * 10.0) + tab[5][1] * (20.0 * 20.0) + tab[5][2] * (30.0 * 30.0)
        + tab[5][3] * (40.0 * 40.0) + tab[5][4] * (50.0 * 50.0);
    res -= (moy * moy);
    printf("variance of X: \t\t%.1f\n", res);
}

void ev_y(float **tab)
{
    float res = 0.0;
    float i = 10.0;
    float moy = 0.0;

    for (int nb = 0; nb < 5; nb++, i += 10.0)
        res += (tab[nb][5] * i);
    printf("expected value of Y: \t%.1f\n", res);
    moy = 10.0 * tab[0][5] + 20.0 * tab[1][5] + 30.0 * tab[2][5]
        + 40.0 * tab[3][5] + 50.0 * tab[4][5];
    res = tab[0][5] * (10.0 * 10.0) + tab[1][5] * (20.0 * 20.0) + tab[2][5] * (30.0 * 30.0)
        + tab[3][5] * (40.0 * 40.0) + tab[4][5] * (50.0 * 50.0);
    res -= (moy * moy);
    printf("variance of Y: \t\t%.1f\n", res);
}

void ev_z(float *tab)
{
    float res = 0.0;
    float i = 20.0;
    float moy = 0.0;
    int nb = 0;

    for (int nb = 0; nb < 9; nb++, i += 10.0)
        res += (tab[nb] * i);
    printf("expected value of Z: \t%.1f\n", res);
    for (float nb2 = nb; nb < 9; nb++, nb2 = nb)
        moy += (nb2 * 10.0 + 20.0) * tab[nb];
    nb = 0;
    res = 0.0;
    for (float nb2 = nb; nb < 9; nb++, nb2 = nb)
        res += tab[nb] * ((nb2 * 10.0 + 20.0) * (nb2 * 10.0 + 20.0));
    res -= (moy * moy);
    printf("variance of Z: \t\t%.1f\n", res);
}

void pz(float **tab)
{
    float *res = malloc(sizeof(float) * 9);

    print_z_start();
    res[0] = tab[0][0];
    res[1] = tab[1][0] + tab[0][1];
    res[2] = tab[2][0] + tab[1][1] + tab[0][2];
    res[3] = tab[3][0] + tab[2][1] + tab[1][2] + tab[0][3];
    res[4] = tab[4][0] + tab[3][1] + tab[2][2] + tab[1][3] +tab[0][4];
    res[5] = tab[4][1] + tab[3][2] + tab[2][3] + tab[1][4];
    res[6] = tab[4][2] + tab[3][3] + tab[2][4];
    res[7] = tab[4][3] + tab[3][4];
    res[8] = tab[4][4];
    printf("%.3f   %.3f   %.3f   ", res[0], res[1], res[2]);
    printf("%.3f   %.3f   %.3f   ", res[3], res[4], res[5]);
    printf("%.3f   %.3f   %.3f\n", res[6], res[7], res[8]);
    printf ("--------------------------------------------------------------------------------\n");
    ev_x(tab);
    ev_y(tab);
    ev_z(res);
    printf ("--------------------------------------------------------------------------------\n");
}
