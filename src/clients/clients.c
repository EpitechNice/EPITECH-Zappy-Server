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
    if (client->team_name != NULL)
        free(client->team_name);
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
    clients->_status = WAITING;
    clients->to_send = NULL;
    return (clients);
}

void write_command(client_t *client)
{
    char *buffer = NULL;
    while (client->to_send != NULL) {
        buffer = (char *)dl_pop_back(&client->to_send);
        dprintf(client->fd, "%s\n", buffer);
        free(buffer);
    }
}