/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdi
*/

#include "zappy_server.h"

void command_pdi(int ai_id)
{
    server_t *server = get_server();
    lnode_t *clients = server->clients;
    client_t *tmp;
    char *buffer = NULL;

    asprintf(&buffer, "pdi %i", ai_id);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI) {
            dl_push_back(&tmp->to_send, strdup(buffer));
            free(buffer);
            return;
        }
    }
    free(buffer);
}
