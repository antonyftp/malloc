/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** Display a character (return nb of char displayed)
*/

#include <unistd.h>

int my_putchar(char *c)
{
    write(1, &c, 1);
    return (1);
}