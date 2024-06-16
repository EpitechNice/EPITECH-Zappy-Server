/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ppo
*/

#include "gui.h"

void command_ppo(char **args, client_t *client)
{
    char *str = NULL;
    lnode_t *tmp = get_server()->clients;
    UNUSED int _;

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
    _ = asprintf(&str, "ppo %d %d %d %d",
    ((client_t *)(tmp->data))->fd, ((client_t *)(tmp->data))->x,
    ((client_t *)(tmp->data))->y, ((client_t *)(tmp->data))->direction);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}
