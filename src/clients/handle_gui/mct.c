/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** mct
*/

#include "gui.h"

void command_mct(char **args, client_t *client)
{
    char *response = NULL;
    map_t **map = ((game_t *)get_server()->game)->map;
    game_t *game = get_server()->game;
    UNUSED int _;

    if (tab_len(args) != 1) {
        dl_push_back(&client->to_send, strdup("sbp"));
        return;
    }
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            _ = asprintf(&response, "bct %d %d %d %d %d %d %d %d %d",
            i, j, map[i][j].ressources[FOOD],
            map[i][j].ressources[LINEMATE], map[i][j].ressources[DERAUMERE],
            map[i][j].ressources[SIBUR], map[i][j].ressources[MENDIANE],
            map[i][j].ressources[PHIRAS], map[i][j].ressources[THYSTAME]);
            dl_push_back(&client->to_send, strdup(response));
            free(response);
            response = NULL;
        }
    }
}
