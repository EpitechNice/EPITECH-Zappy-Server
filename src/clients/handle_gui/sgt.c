/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sgt
*/

#include "gui.h"

void command_sgt(UNUSED char **args, client_t *client)
{
    char *str = NULL;
    UNUSED int _;

    if (tab_len(args) != 1)
        return dl_push_back(&client->to_send, strdup("sbp"));
    _ = asprintf(&str, "sgt %d", get_server()->game->freq);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}
