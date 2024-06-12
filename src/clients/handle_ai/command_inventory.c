/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_inventory
*/

#include "zappy_server.h"

void command_inventory(UNUSED const char **args, client_t *client)
{
    char *out = NULL;
    UNUSED int _;

    _ = asprintf(&out, "[food %i, linemate %i, deraumere %i, sibur %i, " \
        "mendiane %i, phiras %i, thystame %i]", client->inventory[0],
        client->inventory[1], client->inventory[2], client->inventory[3],
        client->inventory[4], client->inventory[5], client->inventory[6]);
    LOG(LOG_LEVEL_INFO, "Player of team %s asked for inventory: %s",
        client->team_name, out);
    dl_push_back(&client->to_send, out);
}