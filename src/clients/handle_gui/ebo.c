/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ebo
*/

#include "gui.h"

void command_ebo(int egg)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;
    UNUSED int _;

    _ = asprintf(&buffer, "ebo %i", egg);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
    free(buffer);
}
