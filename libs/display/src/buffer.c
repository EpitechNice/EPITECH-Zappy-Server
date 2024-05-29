/*
** EPITECH PROJECT, 2024
** Server
** File description:
** buffer
*/

#include "display.h"

static char *buffer;

static void init_buffer()
{
    if (buffer)
        free(buffer);
    buffer = (char *)malloc(MAX_COMMAND_SIZE + 1);
}

void display_buffer()
{
    printf("\r> %s", buffer);
    fflush(stdout);
}