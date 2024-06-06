/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** msz
*/

#include "zappy_server.h"

void command_msz(char **args, client_t *client)
{
    char *response = NULL;

    if (tab_len(args) != 1) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    asprintf(&response, "msz %d %d", get_server()->game->width,
    get_server()->game->height);
    dl_push_back(&client->to_send, response);
}
