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
    char *tile_event[2] = {"mct", NULL};
    char *player_event[3] = {"pin", NULL, NULL};
    UNUSED int _ = asprintf(&player_event[1], "%d", client->fd);

    if (ressource == -1)
        return dl_push_back(&client->to_send, strdup("ko"));
    if (!client->inventory[ressource])
        return dl_push_back(&client->to_send, strdup("ko"));
    get_server()->game->map[client->y][client->x].ressources[ressource] +=
        client->inventory[ressource];
    client->inventory[ressource] = 0;
    dl_push_back(&client->to_send, strdup("ok"));
    LOG(LOG_LEVEL_INFO, "Client %d set %s at pos %d %d ",
        client->fd, args[1], client->x, client->y);
    command_pdr(client->fd, ressource);
    for (lnode_t *tmp = get_server()->clients; tmp; tmp = tmp->next)
        if (((client_t *)tmp->data)->status == GUI) {
            command_mct(tile_event, tmp->data);
            command_pin(player_event, tmp->data);
        }
    client->next_action = get_time();
    client->cooldown = 7.0;
}
