/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_take
*/

#include "zappy_server.h"

static inline void to_lower(char *arg)
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

void command_take(const char **args, client_t *client)
{
    int ressource = get_ressource_index(args[1]);

    if (ressource == -1) {
        dl_push_back(&client->to_send, strdup("ko"));
        return;
    }
    if (!get_server()->game->map[client->y][client->x].ressources[ressource]) {
        dl_push_back(&client->to_send, strdup("ko"));
        return;
    }
    client->inventory[ressource] += get_server()->game->map[client->y]
        [client->x].ressources[ressource];
    get_server()->game->map[client->y][client->x].ressources[ressource] = 0;
    dl_push_back(&client->to_send, strdup("ok"));
    LOG(LOG_LEVEL_INFO, "Client of team %s took every %s on it's tile",
        client->team_name, args[1]);
}