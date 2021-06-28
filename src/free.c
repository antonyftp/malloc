/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-malloc-antony.fantapie
** File description:
** Created by antonyftp
*/

#include "malloc.h"

extern block_t *block;

static block_t *exist(void const *ptr)
{
    for (block_t * i = block; i; i = i->next)
        if (i->data == ptr)
            return (i);
    return (NULL);
}

static void check_block_sides(block_t **to_connect,
    block_t **ptr_, size_t *size)
{
    if (*to_connect && (*to_connect)->free) {
        *size += sizeof(block_t) + ((*to_connect)->size);
        *to_connect = (*to_connect)->next;
    }
    if ((*ptr_)->prev && *ptr_ != block && (*ptr_)->prev->free) {
        *ptr_ = (*ptr_)->prev;
        *size += (*ptr_)->size;
    }
}

void free(void *ptr)
{
    block_t * ptr_ = NULL;
    block_t * to_connect = NULL;
    size_t size = 0;

    if (!block || !ptr) return;
    ptr_ = exist(ptr);
    if (!ptr_ || ptr_->free) return;
    size = ptr_->size;
    to_connect = ptr_->next;
    check_block_sides(&to_connect, &ptr_, &size);
    ptr_->free = true;
    ptr_->size = size;
    ptr_->next = to_connect;
    if (to_connect)
        to_connect->prev = ptr_;
    if (!ptr_->next)
        block->prev = ptr_;
}