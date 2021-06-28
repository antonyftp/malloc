/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include "malloc.h"

int my_put_nbr(int nb)
{
    int displayed_number;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        displayed_number = nb % 10;
        nb = (nb - displayed_number) / 10;
        my_put_nbr(nb);
        my_putchar(displayed_number + 48);
    }
    else
        my_putchar(nb + 48);
    return (0);
}