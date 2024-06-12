/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_co_nbr
*/

#include "zappy_server.h"

static int nb_of_clients_in_team;

static void check_if_same_team(void *client, void *team)
{
    client_t *cl = (client_t *)client;
    client_t *te = (char *)team;

    if (!strncmp(cl->team_name, te, ((strlen(cl->team_name) <
        strlen(te)) ? strlen(cl->team_name) : strlen(te))));
        nb_of_clients_in_team++;
}

void command_co_nbr(UNUSED const char **args, client_t *client)
{
    char *out = NULL;
    UNUSED int _;

    nb_of_clients_in_team = 0;
    dl_apply_data_param(&get_server()->clients, check_if_same_team,
        client->team_name);
    _ = asprintf(&out, "%i", ((team_t *)get_server()->game->
        teams->data)->clients_nb - nb_of_clients_in_team);
    LOG(LOG_LEVEL_DEBUG, "Client of team %s asked for slots, %i free",
        client->team_name, ((team_t *)get_server()->game->teams->data)->
            clients_nb - nb_of_clients_in_team);
    dl_push_back(&client->to_send, out);
}