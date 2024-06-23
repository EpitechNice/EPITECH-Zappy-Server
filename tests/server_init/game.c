/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** game
*/

#include <criterion/criterion.h>
#include "zappy_server.h"

Test(init_game, test1)
{
    parsing_t *p = malloc(sizeof(parsing_t));
    p->clients_nb = 2;
    p->height = 10;
    p->width = 10;
    p->freq = 100;
    p->names = NULL;
    game_t *game = init_game(p);

    cr_assert_eq(game->height, 10);
    cr_assert_eq(game->width, 10);
    cr_assert_eq(game->freq, 100);
    cr_assert_eq(game->global_egg_id, 0);
}