/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_fork
*/

#include "ai.h"
#include "gui.h"

static egg_t *build_egg(unsigned long id, const char *team, int x, int y)
{
    egg_t *egg = malloc(sizeof(egg_t));

    egg->id = id;
    egg->team_name = strdup(team);
    egg->x = x;
    egg->y = y;
    return egg;
}

static void end_command_fork(game_t *game, client_t *client, egg_t *egg)
{
    dl_push_back(&game->eggs, egg);
    dl_push_back(&game->map[client->y][client->x].eggs,
    egg);
    dl_push_back(&client->to_send, strdup("ok"));
    client->next_action_time = get_server()->global_time_stamp + 42;
    command_pfk(client->fd);
    command_enw(egg->id, client);
}

void command_fork(UNUSED char **args, client_t *client)
{
    game_t *game = get_server()->game;
    team_t *team;
    egg_t *egg = build_egg(game->global_egg_id, client->team_name,
        client->x, client->y);

    game->global_egg_id++;
    LOG(LOG_LEVEL_INFO, "Client of team %s forked itself (at %i %i)",
        client->team_name, client->x, client->y);
    for (lnode_t *node = game->teams; node; node = node->next) {
        team = node->data;
        if (!strcmp(team->name, client->team_name)) {
            team->clients_nb++;
            break;
        }
    }
    end_command_fork(game, client, egg);
}
