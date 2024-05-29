/*
** EPITECH PROJECT, 2024
** Server
** File description:
** buffer
*/

#include "display.h"

static char *buffer;

static void init_buffer(void)
{
    if (buffer)
        free(buffer);
    buffer = (char *)malloc(MAX_COMMAND_SIZE + 1);
}

void display_buffer(void)
{
    printf("\r> %s", buffer);
    fflush(stdout);
}
