/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pbc
*/

#include "zappy_server.h"

void command_pbc(int ai_id, const char *message)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;
    UNUSED int _;

    _ = asprintf(&buffer, "pbc %i %s", ai_id, message);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
    free(buffer);
}
