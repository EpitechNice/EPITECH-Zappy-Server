/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** clients
*/

#include "zappy_server.h"

void free_client(void *data)
{
    client_t *client = (client_t *)data;

    close(client->fd);
    if (!dl_empty(client->to_send))
        dl_clear(&client->to_send, free);
    if (!dl_empty(client->command_list))
        dl_clear(&client->command_list, free);
    if (client->status != WAITING)
        free(client->team_name);
    free(client);
}

bool is_client(void *ref, void *data)
{
    client_t *client_ref = (client_t *)ref;
    client_t *client = (client_t *)data;

    return client_ref->fd == client->fd;
}

client_t *init_client(int fd)
{
    client_t *clients = (client_t *)malloc(sizeof(client_t));

    memset(clients, 0, sizeof(client_t));
    clients->fd = fd;
    clients->level = 1;
    clients->inventory[FOOD] = 10;
    return (clients);
}
