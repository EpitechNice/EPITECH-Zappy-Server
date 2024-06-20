/*
** EPITECH PROJECT, 2024
** server
** File description:
** network
*/

#include "zappy_server.h"

static void free_teams(void *data)
{
    team_t *team = (team_t *)data;

    free(team->name);
    free(team);
}

void free_egg(void *data)
{
    egg_t *egg = (egg_t *)data;

    free(egg->team_name);
    free(egg);
}

static void free_map(void *data)
{
    map_t *map = (map_t *)data;

    dl_clear(&map->players, NULL);
    dl_clear(&map->eggs, NULL);
}

void destroy_connection(connect_t *connect)
{
    if (connect->socket != -1)
        close(connect->socket);
    if (connect->address != NULL)
        free(connect->address);
    free(connect);
}

static void destroy_game(game_t *game)
{
    dl_clear(&game->teams, free_teams);
    dl_clear(&game->eggs, free_egg);
    dl_clear(&get_server()->clients, free_client);
    for (int i = 0; i < game->height; ++i) {
        for (int j = 0; j < game->width; ++j)
            free_map(&game->map[i][j]);
        free(game->map[i]);
    }
    free(game->map);
    free(game);
}

void destroy_server(void)
{
    server_t *server = get_server();

    if (server->info)
        destroy_connection(server->info);
    dl_clear(&server->clients, &free_client);
    if (server->game)
        destroy_game(server->game);
    server->initialized = false;
}
