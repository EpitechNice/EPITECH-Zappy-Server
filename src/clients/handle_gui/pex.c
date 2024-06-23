/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pex
*/

#include "gui.h"

void command_pex(int ai_id)
{
    lnode_t *clients = get_server()->clients;
    client_t *tmp;
    char *buffer = NULL;
    char *out = NULL;
    UNUSED int _ = asprintf(&out, "%i", ai_id);
    char *cmd[2] = {out, NULL};

    _ = asprintf(&buffer, "pex %i", ai_id);
    for (; clients; clients = clients->next) {
        tmp = (client_t *)clients->data;
        if (tmp->status == GUI) {
            dl_push_back(&tmp->to_send, strdup(buffer));
            command_ppo(cmd, tmp);
        }
    }
    free(buffer);
    free(out);
}
