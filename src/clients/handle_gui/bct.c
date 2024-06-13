/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "zappy_server.h"

void command_bct(char **args, client_t *client)
{
    char *response = NULL;
    map_t **map = ((game_t *)get_server()->game)->map;
    game_t *game = get_server()->game;
    UNUSED int _;

    if (tab_len(args) != 3 || game->width <= atoi(args[0])
    || game->height <= atoi(args[1])
    || atoi(args[0]) < 0 || atoi(args[1]) < 0) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    _ = asprintf(&response, "bct %s %s %d %d %d %d %d %d %d",
    args[1], args[2], map[atoi(args[0])][atoi(args[1])].ressources[FOOD],
    map[atoi(args[0])][atoi(args[1])].ressources[LINEMATE],
    map[atoi(args[0])][atoi(args[1])].ressources[DERAUMERE],
    map[atoi(args[0])][atoi(args[1])].ressources[SIBUR],
    map[atoi(args[0])][atoi(args[1])].ressources[MENDIANE],
    map[atoi(args[0])][atoi(args[1])].ressources[PHIRAS],
    map[atoi(args[0])][atoi(args[1])].ressources[THYSTAME]);
    dl_push_back(&client->to_send, strdup(response));
    free(response);
}
