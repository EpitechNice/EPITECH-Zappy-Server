/*
** EPITECH PROJECT, 2024
** Zappy-Server
** File description:
** remove
*/

#include "zappy_server.h"

void delete_client(client_t *client)
{
    server_t *server = get_server();

    dl_erase(&server->game->map[client->y][client->x].players, client,
        &is_client, &free_client);
    dl_erase(&server->clients, client, &is_client, &free_client);

    LOG(LOG_LEVEL_WARNING, "Client of team %s left", client->team_name);
}

void move_client(client_t *client, int x, int y)
{
    server_t *server = get_server();

    dl_erase(&server->game->map[client->y][client->x].players, client,
        &is_client, &free_client);
    client->x = x;
    client->y = y;
    dl_push_back(&server->game->map[y][x].players, client);
}