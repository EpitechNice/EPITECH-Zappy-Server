/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_set
*/

#include "ai.h"
#include "gui.h"

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
        if (!strcmp(lressource, ressources[i])) {
            free(lressource);
            return i;
        }
    free(lressource);
    return -1;
}

void command_set(char **args, client_t *client)
{
    int ressource = get_ressource_index(args[1]);

    if (ressource == -1)
        return dl_push_back(&client->to_send, strdup("ko"));
    if (!client->inventory[ressource])
        return dl_push_back(&client->to_send, strdup("ko"));
    get_server()->game->map[client->y][client->x].ressources[ressource] +=
        client->inventory[ressource];
    client->inventory[ressource] = 0;
    dl_push_back(&client->to_send, strdup("ok"));
    LOG(LOG_LEVEL_INFO, "Client of team %s set it's %s", client->team_name,
        args[1]);
    command_pdr(client->fd, ressource);
    client->next_action = get_time() + 7 * 1000 / get_server()->game->freq;
}
