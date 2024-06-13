/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sgt
*/

#include "zappy_server.h"

void command_sgt(UNUSED char **args, client_t *client)
{
    char *str = NULL;
    UNUSED int _;

    if (tab_len(args) != 1) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    _ = asprintf(&str, "sgt %d", get_server()->game->freq);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}
