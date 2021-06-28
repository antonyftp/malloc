/*
** EPITECH PROJECT, 2024
** B_PSU_400_STG_4_1_malloc_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "malloc.h"

size_t align(size_t const a)
{
    return ((a + sizeof(void *) - 1) & ~(sizeof(void *) - 1));
}

void *allocate(size_t const size)
{
    block_t *ptr = find_smallest_block(size);

    if (ptr) {
        if (abs(ptr->size - size) >= sizeof(block_t) + 4)
            split_block(ptr, size);
        ptr->free = false;
    } else if (!(ptr = extend_heap(size)))
        return (NULL);
    return (ptr);
}

block_t *extend_heap(size_t const size)
{
    size_t const page_size = getpagesize();
    block_t *b = sbrk(0);
    void *data = NULL;
    size_t mem_size = (2 + ((sizeof(block_t) + size) / page_size)) * page_size;

    data = sbrk(mem_size);
    if (data == (void *)-1)
        return (NULL);
    b->next = NULL;
    b->size = mem_size - sizeof(block_t);
    b->data = sizeof(block_t) + data;
    b->free = false;
    push_block(&b);
    if (abs(b->size - size) >= sizeof(block_t) + 8) split_block(b, size);
    return (b);
}