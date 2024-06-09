/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** enw
*/

#include "zappy_server.h"

void command_enw(int egg, client_t *client)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;

    asprintf(&buffer, "enw %i %i %i %i",
    egg, client->fd, client->x, client->y);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
    free(buffer);
}
