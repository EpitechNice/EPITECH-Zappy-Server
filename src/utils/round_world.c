/*
** EPITECH PROJECT, 2024
** Server
** File description:
** round_world
*/

#include "zappy_server.h"

void round_world(int *x, int *y)
{
    game_t *game = get_server()->game;

    if (!x && !y)
        return;
    if (x) {
        while ((*x) < 0)
            (*x) += game->height;
        (*x) %= game->height;
    }
    if (y) {
        while ((*y) < 0)
            (*y) += game->width;
        (*y) %= game->width;
    }
}
