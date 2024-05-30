/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** clients
*/

#include "zappy_server.h"

void free_clients(void *data)
{
    client_t *clients = (client_t *) data;

    close(clients->fd);
    if (clients->to_send != NULL)
        m_list_destroy(&clients->to_send, free);
    ffree(clients);
}

client_t *init_clients(int fd)
{
    client_t *clients = (client_t *)fmalloc(sizeof(client_t));

    clients->fd = fd;
    clients->to_send = NULL;
    return (clients);
}

bool is_client(void *ref, void *data)
{
    client_t *client_ref = (client_t *)ref;
    client_t *client = (client_t *)data;

    return client_ref->fd == client->fd;
}

void delete_client(void *data)
{
    client_t *clients = (client_t *)data;

    if (clients->to_send != NULL)
        m_list_destroy(&clients->to_send, ffree);
}
