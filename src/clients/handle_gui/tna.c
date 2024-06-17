/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tna
*/

#include "gui.h"

void command_tna(char **args, client_t *client)
{
    char *response = NULL;
    lnode_t *team = get_server()->game->teams;
    UNUSED int _;

    if (tab_len(args) != 1)
        return dl_push_back(&client->to_send, strdup("sbp"));
    while (team) {
        _ = asprintf(&response, "tna %s", ((team_t *)(team->data))->name);
        dl_push_back(&client->to_send, strdup(response));
        free(response);
        response = NULL;
        team = team->next;
    }
}
