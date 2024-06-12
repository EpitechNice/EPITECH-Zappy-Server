/*
** EPITECH PROJECT, 2024
** Server
** File description:
** str_append
*/

#include "zappy_server.h"

void str_append(char *origin, const char *data)
{
    if (!origin) {
        origin = strdup(data);
        return;
    }
    if (!data || !strlen(data))
        return;
    origin = realloc(origin, (strlen(origin) + strlen(data) + 1));
    strcat(origin, data);
}