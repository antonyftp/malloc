/*
** EPITECH PROJECT, 2024
** B_PSU_400_STG_4_1_malloc_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "malloc.h"

extern block_t *block;

void *reallocarray(void *ptr, size_t const nb, size_t const size)
{
    size_t const total = align(nb * size);
    block_t *ptr_ = NULL;
    void *new = NULL;

    if (!size) {
        free(ptr);
        return (NULL);
    }
    if (!ptr) return (malloc(total));
    ptr_ = ((struct block_s *)(ptr - sizeof(block_t)));
    if (ptr_->free) return (NULL);
    else if (total <= ptr_->size) return (ptr);
    new = malloc(total);
    if (new)
        memcpy(new, ptr, ptr_->size);
    free(ptr);
    return (new);
}