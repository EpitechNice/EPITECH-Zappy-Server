/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_right
*/

#include "zappy_server.h"

void command_right(UNUSED char **args, client_t *client)
{
    client->direction++;
    client->direction %= LEFT + 1;
    LOG(LOG_LEVEL_DEBUG, "Client of team %s turned right", client->team_name);
    dl_push_back(&client->to_send, strdup("ok"));
}