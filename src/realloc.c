/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-malloc-antony.fantapie
** File description:
** Created by antonyftp
*/

#include "malloc.h"

extern block_t *block;

void *realloc(void *ptr, size_t size)
{
    block_t *ptr_ = NULL;
    void *new = NULL;

    if (!size) {
        free(ptr);
        return (NULL);
    }
    if (!ptr) return (malloc(size));
    ptr_ = ((struct block_s *)(ptr - sizeof(block_t)));
    if (ptr_->free) return (NULL);
    if (align(size) <= ptr_->size) return (ptr);
    new = malloc(size);
    if (new) memcpy(new, ptr, ptr_->size);
    free(ptr);
    return (new);
}