/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** mct
*/

#include "zappy_server.h"

void command_mct(char **args, client_t *client)
{
    char *response = NULL;
    map_t **map = ((game_t *)get_server()->game)->map;
    game_t *game = get_server()->game;

    if (tab_len(args) != 1) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            asprintf(&response, "bct %d %d %d %d %d %d %d %d %d",
            i, j, map[i][j].food,
            map[i][j].linemate,
            map[i][j].deraumere,
            map[i][j].sibur,
            map[i][j].mendiane,
            map[i][j].phiras,
            map[i][j].thystame);
            dl_push_back(&client->to_send, strdup(response));
            free(response);
            response = NULL;
        }
    }
}
