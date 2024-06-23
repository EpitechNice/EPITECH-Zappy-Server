/*
** EPITECH PROJECT, 2024
** Server
** File description:
** str_append
*/

#include "zappy_server.h"

void to_lower(char *str)
{
    for (int i = 0; str[i]; ++i)
        str[i] = (str[i] >= 65 && str[i] <= 90) ? (str[i] + 32) : str[i];
}

void str_append(char **origin, const char *data)
{
    size_t origin_len;
    size_t data_len;
    size_t new_len;
    char *new_str;

    if (!origin || !data || !strlen(data))
        return;
    if (!(*origin)) {
        *origin = strdup(data);
        return;
    }
    origin_len = strlen(*origin);
    data_len = strlen(data);
    new_len = origin_len + data_len + 1;
    new_str = realloc(*origin, new_len);
    if (!new_str)
        return;
    *origin = new_str;
    memcpy(*origin + origin_len, data, data_len);
    (*origin)[new_len - 1] = '\0';
}
