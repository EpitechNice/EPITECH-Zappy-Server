/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** egg
*/

#include "zappy_server.h"
#include "gui.h"

bool get_egg_pos(client_t *client, char *team_name)
{
    egg_t *tmp;

    for (lnode_t *egg = get_server()->game->eggs; egg; egg = egg->next) {
        tmp = (egg_t *)egg->data;
        if (strcmp(tmp->team_name, team_name))
            continue;
        client->x = tmp->x;
        client->y = tmp->y;
        command_ebo(tmp->id);
        destroy_egg(tmp);
        return true;
    }
    return false;
}

static void send_cmds(client_t *client, team_t *tmp, game_t *game)
{
    char *out = NULL;
    UNUSED int _;

    _ = asprintf(&out, "pnw %i %i %i %i %i %s", client->fd, client->x,
        client->y, client->direction + 1, client->level, client->team_name);
    command_pnw(out);
    free(out);
    send_infos(client, tmp->clients_nb, game->height, game->width);
}

void handle_new_ai(client_t *client, const char *buffer)
{
    game_t *game = get_server()->game;
    lnode_t *teams = game->teams;

    client->team_name = strdup(buffer);
    for (team_t *tmp; teams; teams = teams->next) {
        tmp = (team_t *)teams->data;
        if (strcmp(tmp->name, client->team_name))
            continue;
        if (get_egg_pos(client, tmp->name)) {
            tmp->clients_nb--;
            return send_cmds(client, tmp, game);
        }
        client->status = WAITING;
        return;
    }
    client->status = ERROR;
    if (client->status == ERROR)
        return FD_SET(client->fd, &get_server()->error_fds);
}

void send_infos(client_t *client, int nb_clients, int height, int width)
{
    char *out = NULL;
    UNUSED int _;

    _ = asprintf(&out, "%i", nb_clients);
    dl_push_back(&client->to_send, strdup(out));
    free(out);
    out = NULL;
    _ = asprintf(&out, "%i %i", height, width);
    dl_push_back(&client->to_send, strdup(out));
    client->status = AI;
    free(out);
}

void check_free_eggs(client_t *client)
{
    char *out = NULL;
    UNUSED int _;

    if (!get_egg_pos(client, client->team_name))
        return;
    client->status = AI;
    for (lnode_t *tmp = get_server()->game->teams; tmp; tmp = tmp->next)
        if (strcmp(((team_t *)tmp->data)->name, client->team_name) == 0) {
            ((team_t *)tmp->data)->clients_nb--;
            send_infos(client, ((team_t *)tmp->data)->clients_nb,
                get_server()->game->height, get_server()->game->width);
            _ = asprintf(&out, "pnw %i %i %i %i %i %s", client->fd, client->x,
            client->y, client->direction + 1, client->level,
            client->team_name);
            command_pnw(out);
            free(out);
        }
}
