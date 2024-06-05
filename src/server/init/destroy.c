/*
** EPITECH PROJECT, 2024
** server
** File description:
** network
*/

#include "zappy_server.h"

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
    dl_clear(&game->teams, free);
    for (int i = 0; i < game->height; i++)
        free(game->map[i]);
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

void destroy_server_exit(int exit_code)
{
    destroy_server();
    exit(exit_code);
}
