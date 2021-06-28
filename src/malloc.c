/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-malloc-antony.fantapie
** File description:
** Created by antonyftp
*/

#include <stdio.h>
#include "malloc.h"

block_t *block = NULL;

block_t *find_smallest_block(size_t const size)
{
    block_t *i = block;
    block_t *smallest = NULL;

    if (!block) return (NULL);
    for (; i; i = i->next) {
        if (i->free && i->size >= size) {
            smallest = i;
            break;
        }
    }
    if (!smallest || smallest->size == size) return (smallest);
    for (; i; i = i->next) {
        if (i->free && i->size >= size && i->size < smallest->size) {
            smallest = i;
            if (smallest->size == size)
                return (smallest);
        }
    }
    return (smallest);
}

void split_block(block_t *i, size_t const size)
{
    void *new_chunk_address = i->data + size;
    block_t *new = new_chunk_address;

    new->data = sizeof(block_t) + new_chunk_address;
    new->size = abs(i->size - size) - sizeof(block_t);
    new->free = true;
    new->next = i->next;
    new->prev = i;
    i->size = size;
    i->next = new;
    if (new->next)
        new->next->prev = new;
    else if (block)
        block->prev = new;
}

void push_block(block_t **node)
{
    if (!block) {
        (*node)->prev = NULL;
    } else {
        if (block->prev) {
            block->prev->next = *node;
            (*node)->prev = block->prev;
        }
        block->prev = *node;
    }
}

void *init_heap(size_t const size)
{
    block_t *ptr = extend_heap(size);

    if (!ptr)
        return (NULL);
    block = ptr;
    return (ptr);
}

void *malloc(size_t const size_)
{
    size_t const size = align(size_);
    block_t *ptr = !size_ ? NULL : block ? allocate(size) : init_heap(size);

    return (ptr ? ptr->data : NULL);
}