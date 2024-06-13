/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_look
*/

#include "zappy_server.h"

static void add_tile(char *out, UNUSED int x, UNUSED int y)
{
    map_t *tile = &(get_server()->game->map[y][y]);

    if (!dl_empty(tile->players))
        str_append(out, " player");
    if (!dl_empty(tile->eggs))
        str_append(out, " eggs");
    for (int i = 0; i < 7; ++i) {
        if (tile->ressources[i]) {
            out = realloc(out, strlen(out) + 12);
            out = strcat(out, " ");
            ressource_from_index(i, &out[strlen(out)]);
        }
    }
}

static void new_line(int *x, int *y, client_t *client)
{
    switch (client->direction) {
        case UP:
            (*x)--;
            (*y)--;
            break;
        case RIGHT:
            (*x)++;
            (*y)--;
            break;
        case DOWN:
            (*x)++;
            (*y)++;
            break;
        case LEFT:
            (*x)--;
            (*y)++;
            break;
        default:
            break;
    }
}

static void next(int *x, int *y, client_t *client)
{
    switch (client->direction) {
        case UP:
            (*x)++;
            break;
        case RIGHT:
            (*y)++;
            break;
        case DOWN:
            (*x)--;
            break;
        case LEFT:
            (*y)--;
            break;
        default:
            break;
    }
}

void command_look(UNUSED char **args, UNUSED client_t *client)
{
    int level = client->level;
    int to_display = 3;
    char *out = strdup("[player");
    int x = client->x;
    int y = client->y;

    LOG(LOG_LEVEL_INFO, "Client of team %s is looking.", client->team_name);
    for (; level > 0; --level) {
        new_line(&x, &y, client);
        for (int i = 0; i < to_display; ++i) {
            add_tile(out, x, y);
            next(&x, &y, client);
            round_world(&x, &y);
        }
        to_display += 2;
    }
    dl_push_back(&client->to_send, out);
}