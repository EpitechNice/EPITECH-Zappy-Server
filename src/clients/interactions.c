/*
** EPITECH PROJECT, 2024
** Zappy-Server
** File description:
** remove
*/

#include "zappy_server.h"

static bool is_egg(void *_ref, void *_obj)
{
    egg_t *ref = (egg_t *)_ref;
    egg_t *obj = (egg_t *)_obj;

    return ref->id == obj->id;
}

void delete_egg(egg_t *egg)
{
    server_t *server = get_server();

    dl_erase(&server->game->eggs, egg, &is_egg, NULL);
    dl_erase(&server->game->map[egg->y][egg->x].eggs, egg, &is_egg, &free_egg);
}

void delete_client(client_t *client)
{
    server_t *server = get_server();

    dl_erase(&server->clients, client, &is_client, NULL);
    dl_erase(&server->game->map[client->y][client->x].players, client,
        &is_client, &free_client);
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
