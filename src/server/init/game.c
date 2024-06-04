/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** game
*/

#include "zappy_server.h"

static team_t *make_teams(parsing_t *p)
{
    team_t *team = malloc(sizeof(team_t));

    team->name = strdup(p->names->data);
    team->clients_nb = p->clients_nb;
    return team;
}

static void init_teams(parsing_t *p, game_t *game)
{
    while (p->names) {
        dl_push_back(&game->teams,
        (team_t *)make_teams(p));
        p->names = p->names->next;
    }
}

game_t *init_game(parsing_t *p)
{
    game_t *game = malloc(sizeof(game_t));

    game->width = p->width;
    game->height = p->height;
    game->freq = p->freq;
    init_teams(p, game);
    return game;
}