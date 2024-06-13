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

    LOG(LOG_LEVEL_INFO, "Client of team %s forked itself (at %i %i)",
        client->team_name, client->x, client->y);
    dl_push_back(&game->map[client->y][client->x].eggs, strdup("EGG HAS BEEN PLANTED"));
    dl_push_back(&client->to_send, strdup("ok"));
}