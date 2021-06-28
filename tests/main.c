/*
** EPITECH PROJECT, 2024
** B_PSU_400_STG_4_1_malloc_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "malloc.h"
#include <string.h>

int main(void)
{
    char *hello = malloc(sizeof(char) * strlen("Hello aaaaaaa") + 1);
    free(hello);
    hello = malloc(sizeof(char) * strlen("Hello ") + 1);

    char *world = malloc(sizeof(char) * strlen("World !") + 1);
    char *bitch = malloc(sizeof(char) * strlen("bitch") + 1);
    strcpy(hello, "Hello aaaaaaa");
    strcpy(world, "World !");
    strcpy(bitch, "bitch");
    write(1, "--- Print ---\n", 14);
    puts(hello);
    puts(world);
    puts(bitch);
    world = realloc(world, strlen("World !!!!") + 1);
    strcpy(world, "World !!!!");
    puts(world);
    world = reallocarray(world, strlen("World !!!!!!!") + 1, sizeof(char));
    strcpy(world, "World !!!!!!!");
    puts(world);
    write(1, "Free 2\n", 7);
    free(hello);
    write(1, "Free 3\n", 7);
    free(world);
    write(1, "Free 4\n", 7);
    free(bitch);
    printf("%s - %d", "Hello World", 913);
}