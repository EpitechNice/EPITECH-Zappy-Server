/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pnw
*/

#include "gui.h"

void command_pnw(const char *buffer)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;

    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
}
