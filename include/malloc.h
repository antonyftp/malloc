/*
** EPITECH PROJECT, 2024
** B-PSU-400-STG-4-1-malloc-antony.fantapie
** File description:
** Created by antonyftp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#ifndef B_PSU_400_STG_4_1_MALLOC_ANTONY_FANTAPIE_MALLOC_H
#define B_PSU_400_STG_4_1_MALLOC_ANTONY_FANTAPIE_MALLOC_H

typedef struct block_s {
    size_t size;
    struct block_s *next;
    struct block_s *prev;
    bool free;
    void *data;
} block_t;

void *realloc(void *ptr, size_t size);
void *calloc(size_t size, size_t nb);
void *reallocarray(void *ptr, size_t const nb, size_t const size);
void *malloc(size_t const size);
void show_alloc_mem();
void free(void *ptr);

block_t * extend_heap(size_t const size);
void *allocate(size_t const size);
block_t * find_smallest_block(size_t const size);
void split_block(block_t * i, size_t const size);
void push_block(block_t * *node);

size_t align(size_t const a);

#endif //B_PSU_400_STG_4_1_MALLOC_ANTONY_FANTAPIE_MALLOC_H
