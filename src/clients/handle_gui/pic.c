/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pic
*/

#include "gui.h"

void command_pic(client_t *client, int *ai_fds, int size)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;
    char *fds = NULL;
    UNUSED int _;

    _ = asprintf(&fds, "%i", ai_fds[0]);
    for (int i = 1; i < size; i++)
        _ = asprintf(&fds, "%s %i", fds, ai_fds[i]);
    _ = asprintf(&buffer, "pic %i %i %i %s",
    client->x, client->y, client->level + 1, fds);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
    free(buffer);
    free(fds);
}
