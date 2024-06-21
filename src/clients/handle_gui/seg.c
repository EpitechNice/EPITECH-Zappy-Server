/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** seg
*/

#include "gui.h"

void command_seg(const char *team)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;
    UNUSED int _;

    if (!team)
        _ = asprintf(&buffer, "seg");
    else
        _ = asprintf(&buffer, "seg %s", team);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
    free(buffer);
}
