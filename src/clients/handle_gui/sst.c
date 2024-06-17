/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sst
*/

#include "gui.h"

void command_sst(UNUSED char **args, client_t *client)
{
    char *str = NULL;
    UNUSED int _;

    if (tab_len(args) != 2)
        return dl_push_back(&client->to_send, strdup("sbp"));
    get_server()->game->freq = atoi(args[1]);
    _ = asprintf(&str, "sst %d", get_server()->game->freq);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}
