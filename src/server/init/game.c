/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** game
*/

#include "zappy_server.h"

static team_t *make_teams(lnode_t *p, int clients_nb)
{
    team_t *team = malloc(sizeof(team_t));

    team->name = strdup(p->data);
    team->clients_nb = clients_nb;
    return team;
}

static void init_teams(lnode_t *p, game_t *game, parsing_t *parse)
{
    while (p) {
        dl_push_back(&game->teams, (team_t *)make_teams(p, parse->clients_nb));
        p = p->next;
    }
}

static map_t **make_map(int width, int height)
{
    map_t **map = malloc(sizeof(map_t *) * height);

    for (int i = 0; i < height; i++)
        map[i] = calloc(width, sizeof(map_t));
    return map;
}

// FOR TESTING PURPOSES
//
// static map_t **make_map(int width, int height)
// {
//     map_t **map = malloc(sizeof(map_t *) * height);

//     for (int i = 0; i < height; i++) {
//         map[i] = malloc(sizeof(map_t) * width);
//         for (int j = 0; j < width; j++)
//             map[i][j] = (map_t){NULL, NULL, {1, 2, 3, 4, 5, 6, 7}};
//     }
//     return map;
// }

game_t *init_game(parsing_t *p)
{
    game_t *game = malloc(sizeof(game_t));

    game->width = p->width;
    game->height = p->height;
    game->freq = p->freq;
    game->teams = NULL;
    game->map = make_map(p->width, p->height);
    init_teams(p->names, game, p);
    return game;
}
