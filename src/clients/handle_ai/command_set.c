/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_set
*/

#include "zappy_server.h"

static void to_lower(char *arg)
{
    for (unsigned i = 0; arg[i]; ++i)
        arg[i] = (arg[i] > 0x40 && arg[i] < 0x5b) ? (arg[i] - 0x20) : (arg[i]);
}

static int get_ressource_index(const char *ressource)
{
    char *lressource;
    char *ressources[] = {"food", "linemate", "deraumere", "sibur", "mendiane",
        "phiras", "thystame", NULL};

    if (!ressource)
        return -1;
    lressource = strdup(ressource);
    to_lower(lressource);
    for (int i = 0; ressource[i]; ++i)
        if (!strcmp(lressource, ressources[i]))
            return i;
    return -1;
}

void command_set(char **args, client_t *client)
{
    int ressource = get_ressource_index(args[1]);

    if (ressource == -1) {
        dl_push_back(&client->to_send, strdup("ko"));
        return;
    }
    if (!client->inventory[ressource]) {
        dl_push_back(&client->to_send, strdup("ko"));
        return;
    }
    get_server()->game->map[client->y][client->x].ressources[ressource] +=
        client->inventory[ressource];
    client->inventory[ressource] = 0;
    dl_push_back(&client->to_send, strdup("ok"));
    client->next_action_time = get_server()->global_time_stamp + 7;
    LOG(LOG_LEVEL_INFO, "Client of team %s set it's %s", client->team_name,
        args[1]);
}
