/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pie
*/

#include "gui.h"

void command_pie(int x, int y, bool success)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;
    UNUSED int _;

    _ = asprintf(&buffer, "pie %i %i %s", x, y,
    success ? "ok" : "ko");
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI)
            dl_push_back(&tmp->to_send, strdup(buffer));
    }
    free(buffer);
}
