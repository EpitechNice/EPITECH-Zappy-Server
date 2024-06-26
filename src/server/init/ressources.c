/*
** EPITECH PROJECT, 2024
** Zappy-Server
** File description:
** ressources
*/

#include "zappy_server.h"

const int densities[] = {50, 30, 15, 10, 10, 8, 5};
const int nb_ressources = 7;

void spread_ressources(game_t *game)
{
    int size = game->width * game->height;
    int cross = 0;

    for (int i = 0; i < nb_ressources; ++i) {
        cross = densities[i] * size / 100;
        cross = (cross <= 0 ? 1 : cross);
        for (int _ = game->ressources[i]; _ < cross; ++_) {
            game->map[rand() % game->height][rand() % game->width]
                .ressources[i]++;
            game->ressources[i]++;
        }
    }
}
