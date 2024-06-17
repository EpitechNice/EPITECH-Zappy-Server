/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_fork
*/

#include "zappy_server.h"

void command_fork(UNUSED char **args, client_t *client)
{
    game_t *game = get_server()->game;
    team_t *team;

    LOG(LOG_LEVEL_INFO, "Client of team %s forked itself (at %i %i)",
        client->team_name, client->x, client->y);
    for (lnode_t *node = game->teams; node; node = node->next) {
        team = node->data;
        if (strcmp(team->name, client->team_name) == 0) {
            team->clients_nb++;
            break;
        }
    }
    dl_push_back(&game->map[client->y][client->x].eggs,
    strdup("EGG HAS BEEN PLANTED"));
    dl_push_back(&client->to_send, strdup("ok"));
}
