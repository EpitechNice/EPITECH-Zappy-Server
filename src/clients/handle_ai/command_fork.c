/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_fork
*/

#include "ai.h"
#include "gui.h"

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
    client->next_action_time = get_server()->global_time_stamp + 42;
    command_pfk(client->fd);
    // command_enw(EGG_ID,client->fd); TODO(FoxOne) : Implement eggs_id
}
