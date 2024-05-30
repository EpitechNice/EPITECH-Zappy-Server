/*
** EPITECH PROJECT, 2024
** Server
** File description:
** buffer
*/

#include "input_output.h"

static char *buffer;

static void init_buffer(void)
{
    if (buffer)
        ffree(buffer);
    buffer = (char *)fmalloc(MAX_COMMAND_SIZE + 1);
}

void display_buffer(void)
{
    printf("\r> %s", buffer);
    fflush(stdout);
}
