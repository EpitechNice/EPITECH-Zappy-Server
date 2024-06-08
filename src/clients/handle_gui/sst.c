/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sst
*/

#include "zappy_server.h"

void command_sst(UNUSED char **args, client_t *client)
{
    char *str = NULL;

    if (tab_len(args) != 2) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    get_server()->game->freq = atoi(args[1]);
    asprintf(&str, "sst %d", get_server()->game->freq);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}