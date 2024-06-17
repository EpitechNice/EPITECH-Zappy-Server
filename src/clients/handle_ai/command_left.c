/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_left
*/

#include "zappy_server.h"

void command_left(UNUSED char **args, client_t *client)
{
    if (client->direction == UP) {
        client->direction = LEFT;
        return;
    }
    client->direction--;
    LOG(LOG_LEVEL_DEBUG, "Client of team %s turned left", client->team_name);
    client->next_action_time = get_server()->global_time_stamp + 7;
    dl_push_back(&client->to_send, strdup("ok"));
}
