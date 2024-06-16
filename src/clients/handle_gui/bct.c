/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "gui.h"

void command_bct(char **as, client_t *client)
{
    char *response = NULL;
    map_t **map = ((game_t *)get_server()->game)->map;
    game_t *game = get_server()->game;
    UNUSED int _;

    if (tab_len(as) != 3 || game->width <= atoi(as[0])
    || game->height <= atoi(as[1]) || atoi(as[0]) < 0 || atoi(as[1]) < 0)
        return dl_push_back(&client->to_send, strdup("sbp"));
    _ = asprintf(&response, "bct %s %s %d %d %d %d %d %d %d",
    as[1], as[2], map[atoi(as[0])][atoi(as[1])].ressources[FOOD],
    map[atoi(as[0])][atoi(as[1])].ressources[LINEMATE],
    map[atoi(as[0])][atoi(as[1])].ressources[DERAUMERE],
    map[atoi(as[0])][atoi(as[1])].ressources[SIBUR],
    map[atoi(as[0])][atoi(as[1])].ressources[MENDIANE],
    map[atoi(as[0])][atoi(as[1])].ressources[PHIRAS],
    map[atoi(as[0])][atoi(as[1])].ressources[THYSTAME]);
    dl_push_back(&client->to_send, strdup(response));
    free(response);
}
