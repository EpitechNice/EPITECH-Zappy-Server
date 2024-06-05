/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** msz
*/

#include "zappy_server.h"

char *command_msz(char **args)
{
    char *response = NULL;

    if (tab_len(args) != 1)
        return strdup("sbp");
    asprintf(&response, "msz %d %d", get_server()->game->width,
    get_server()->game->height);
    return response;
}
