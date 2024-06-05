/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** mct
*/

#include "zappy_server.h"

char *command_mct(char **args)
{
    char *response = NULL;
    // map_t **map = ((game_t *)get_server()->game)->map;
    // game_t *game = get_server()->game;

    if (tab_len(args) != 1)
        return strdup("sbp");
    // asprintf(&response, "mct %d %d %d %d %d %d %d %d %d",
    // game->width, game->height,
    // map[atoi(args[0])][atoi(args[1])].food,
    // map[atoi(args[0])][atoi(args[1])].linemate,
    // map[atoi(args[0])][atoi(args[1])].deraumere,
    // map[atoi(args[0])][atoi(args[1])].sibur,
    // map[atoi(args[0])][atoi(args[1])].mendiane,
    // map[atoi(args[0])][atoi(args[1])].phiras,
    // map[atoi(args[0])][atoi(args[1])].thystame);
    return response;
}