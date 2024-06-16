/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pin
*/

#include "gui.h"

static void send_pin(client_t *client, client_t *tmp)
{
    char *str = NULL;
    UNUSED int _;

    _ = asprintf(&str, "pin %d %d %d %d %d %d %d %d %d %d",
    tmp->fd, tmp->x, tmp->y, tmp->inventory[0], tmp->inventory[1],
    tmp->inventory[2], tmp->inventory[3], tmp->inventory[4],
    tmp->inventory[5], tmp->inventory[6]);
    dl_push_back(&client->to_send, strdup(str));
    free(str);
}

void command_pin(char **args, client_t *client)
{
    lnode_t *tmp = get_server()->clients;

    if (tab_len(args) != 2)
        return dl_push_back(&client->to_send, strdup("sbp"));
    for (; tmp != NULL; tmp = tmp->next)
        if (((client_t *)(tmp->data))->fd == atoi(args[1]))
            break;
    if (tmp == NULL)
        return dl_push_back(&client->to_send, strdup("sbp"));
    send_pin(client, tmp->data);
}
