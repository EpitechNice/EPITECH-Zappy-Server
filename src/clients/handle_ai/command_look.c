/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_look
*/

#include "ai.h"

static void add_tile(char **out, int x, int y)
{
    map_t *tile = &(get_server()->game->map[x][y]);
    char ressource[11];

    str_append(out, ",");
    if (!dl_empty(tile->players))
        str_append(out, " player");
    if (!dl_empty(tile->eggs))
        str_append(out, " eggs");
    for (int i = 0; i < 7; ++i) {
        if (tile->ressources[i]) {
            ressource_from_index(i, ressource);
            str_append(out, ressource);
            str_append(out, " ");
        }
    }
}

static void new_line(int *x, int *y, client_t *client)
{
    if (client->direction == UP) {
        (*x)--;
        (*y)--;
    }
    if (client->direction == RIGHT) {
        (*x)++;
        (*y)--;
    }
    if (client->direction == DOWN) {
        (*x)++;
        (*y)++;
    }
    if (client->direction == LEFT) {
        (*x)--;
        (*y)++;
    }
    round_world(x, y);
}

static void next_pos(int *x, int *y, client_t *client)
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
    round_world(x, y);
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
            add_tile(&out, x, y);
            next_pos(&x, &y, client);
        }
        to_display += 2;
    }
    str_append(&out, "]");
    dl_push_back(&client->to_send, out);
    client->next_action = get_time();
    client->cooldown = 7.0;
}
