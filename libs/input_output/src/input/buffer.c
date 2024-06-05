/*
** EPITECH PROJECT, 2024
** Server
** File description:
** buffer
*/

#include "input_output.h"

static char *buffer;

char *get_buffer(void)
{
    if (!buffer) {
        buffer = (char *)malloc(MAX_COMMAND_SIZE + 1);
        memset((void *)buffer, 0, MAX_COMMAND_SIZE + 1);
    }
    return buffer;
}

void clear_buffer(void)
{
    if (!buffer)
        return;
    free(buffer);
    buffer = NULL;
}

bool add_char(char c)
{
    if (strlen(buffer) >= MAX_COMMAND_SIZE)
        return false;
    strncat(buffer, &c, 1);
    return true;
}

void display_prompt(void)
{
    printf("> %s", buffer);
    fflush(stdout);
}
