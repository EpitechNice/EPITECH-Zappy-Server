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

static egg_t *build_egg(unsigned long id, const char *team, int x, int y)
{
    egg_t *egg = malloc(sizeof(egg_t));

    egg->id = id;
    egg->team_name = strdup(team);
    egg->x = x;
    egg->y = y;
    return egg;
}

static void init_teams(lnode_t *p, game_t *game, parsing_t *parse)
{
    egg_t *egg = NULL;
    int y = 0;
    int x = 0;

    while (p) {
        dl_push_back(&game->teams, (team_t *)make_teams(p, parse->clients_nb));
        for (int i = 0; i < parse->clients_nb; ++i) {
            y = rand() % game->height;
            x = rand() % game->width;
            egg = build_egg(game->global_egg_id, p->data,
                x, y);
            dl_push_back(&game->map[x][y].eggs, egg);
            dl_push_back(&game->eggs, egg);
            game->global_egg_id++;
        }
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

game_t *init_game(parsing_t *p)
{
    game_t *game = malloc(sizeof(game_t));

    memset(game, 0, sizeof(game_t));
    game->width = p->width;
    game->height = p->height;
    game->freq = p->freq;
    game->map = make_map(p->width, p->height);
    init_teams(p->names, game, p);
    spread_ressources(game);
    return game;
}
