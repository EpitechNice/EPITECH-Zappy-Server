/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_co_nbr
*/

#include "ai.h"

void command_co_nbr(UNUSED char **args, client_t *client)
{
    char *out = NULL;
    UNUSED int _;

    _ = asprintf(&out, "%i", ((team_t *)get_server()->game->
        teams->data)->clients_nb);
    LOG(LOG_LEVEL_DEBUG, "Client of team %s asked for slots, %i free",
        client->team_name, ((team_t *)get_server()->game->teams->data)->
            clients_nb);
    dl_push_back(&client->to_send, strdup(out));
    free(out);
}
