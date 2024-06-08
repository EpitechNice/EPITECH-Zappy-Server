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
    if (client->to_send != NULL)
        dl_clear(&client->to_send, free);
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

    clients->fd = fd;
    clients->x = 0;
    clients->y = 0;
    clients->level = 1;
    clients->direction = UP;
    clients->status = WAITING;
    clients->to_send = NULL;
    clients->team_name = NULL;
    for (int i = 0; i < 7; i++)
        clients->inventory[i] = 0;
    return (clients);
}
