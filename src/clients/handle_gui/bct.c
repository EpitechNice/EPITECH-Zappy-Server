/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "zappy_server.h"

char *command_bct(char **args)
{
    char *response = NULL;
    map_t **map = ((game_t *)get_server()->game)->map;
    game_t *game = get_server()->game;

    if (game->width <= atoi(args[0]) || game->height <= atoi(args[1])
    || atoi(args[0]) < 0 || atoi(args[1]) < 0)
        return strdup("sbp");
    if (tab_len(args) != 3)
        return strdup("sbp");
    asprintf(&response, "bct %d %d %d %d %d %d %d",
    map[atoi(args[0])][atoi(args[1])].food,
    map[atoi(args[0])][atoi(args[1])].linemate,
    map[atoi(args[0])][atoi(args[1])].deraumere,
    map[atoi(args[0])][atoi(args[1])].sibur,
    map[atoi(args[0])][atoi(args[1])].mendiane,
    map[atoi(args[0])][atoi(args[1])].phiras,
    map[atoi(args[0])][atoi(args[1])].thystame);
    return response;
}
