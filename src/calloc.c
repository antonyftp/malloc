/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-malloc-antony.fantapie
** File description:
** Created by antonyftp
*/

#include "malloc.h"

extern block_t *block;

void *calloc(size_t size, size_t type_size)
{
    size_t total = type_size * size;
    void *p = NULL;
    unsigned char *i = NULL;

    if (!(p = malloc(total)))
        return (NULL);
    --total;
    for (i = p; total; --total)
        *i++ = 0;
    return (p);
}