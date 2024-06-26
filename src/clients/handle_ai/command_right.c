/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_right
*/

#include "ai.h"
#include "gui.h"

void command_right(UNUSED char **args, client_t *client)
{
    char *fd = NULL;
    UNUSED int _ = asprintf(&fd, "%d", client->fd);

    client->direction--;
    if (client->direction < 0)
        client->direction = LEFT;
    LOG(LOG_LEVEL_DEBUG, "Client of team %s turned right", client->team_name);
    dl_push_back(&client->to_send, strdup("ok"));
    for (lnode_t *tmp = get_server()->clients; tmp != NULL; tmp = tmp->next)
        if (((client_t *)(tmp->data))->status == GUI)
            command_ppo((char *[]){"ppo", fd, NULL},
                (client_t *)(tmp->data));
    free(fd);
    client->next_action = get_time();
    client->cooldown = 7.0;
}
