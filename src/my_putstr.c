/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** Swap the content of two integers
*/

#include "malloc.h"

int my_putstr(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
}
