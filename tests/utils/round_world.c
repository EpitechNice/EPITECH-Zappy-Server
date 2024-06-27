/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** round_world
*/

#include <criterion/criterion.h>
#include "zappy_server.h"
#include "utils.h"

Test(utils_tests, test_round_world)
{
    int x = 0;
    int y = 0;
    game_t *game = malloc(sizeof(game_t));

    game->width = 10;
    game->height = 10;
    get_server()->game = game;
    round_world(&x, &y);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(utils_tests, test_round_world2)
{
    int x = -1;
    int y = -1;
    game_t *game = malloc(sizeof(game_t));

    game->width = 10;
    game->height = 10;
    get_server()->game = game;
    round_world(&x, &y);
    cr_assert_eq(x, 9);
    cr_assert_eq(y, 9);
}

Test(utils_tests, test_round_world3)
{
    int x = 10;
    int y = 10;
    game_t *game = malloc(sizeof(game_t));

    game->width = 10;
    game->height = 10;
    get_server()->game = game;
    round_world(&x, &y);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}

Test(utils_tests, test_round_world4)
{
    int x = -10;
    int y = -10;
    game_t *game = malloc(sizeof(game_t));

    game->width = 10;
    game->height = 10;
    get_server()->game = game;
    round_world(&x, &y);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 0);
}
