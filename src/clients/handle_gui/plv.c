/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** plv
*/

#include "zappy_server.h"

void command_plv(char **args, client_t *client)
{
    char *str = NULL;
    lnode_t *tmp = get_server()->clients;

    if (tab_len(args) != 2) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    for (; tmp != NULL; tmp = tmp->next)
        if (((client_t *)(tmp->data))->fd == atoi(args[1]))
            break;
    if (tmp == NULL) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    asprintf(&str, "plv %d %d",
    ((client_t *)(tmp->data))->fd, ((client_t *)(tmp->data))->level);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}