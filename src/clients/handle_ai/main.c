/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"

static void delete_client(client_t *client, const char *buffer)
{
    server_t *server = get_server();

    dl_erase(&server->clients, client, is_client, free_client);
    LOG(LOG_LEVEL_WARNING, "Player in team %s left", buffer);
}

static void send_infos(client_t *client, int nb_clients, int height, int width)
{
    char *out = NULL;

    if (asprintf(&out, "%i", nb_clients) <= 0) {
        LOG(LOG_LEVEL_CRITICAL, "Error running asprintf (allocation)");
        return;
    }
    dl_push_back(&client->to_send, out);
    out = NULL;
    if (asprintf(&out, "%i %i", height, width) <= 0) {
        LOG(LOG_LEVEL_CRITICAL, "Error running asprintf (allocation)");
        return;
    }
    dl_push_back(&client->to_send, out);
    client->status = AI;
}

void handle_new_ai(client_t *client, const char *buffer)
{
    game_t *game = get_server()->game;
    lnode_t *teams = game->teams;
    team_t *tmp;

    for (; teams; teams = teams->next) {
        tmp = (team_t *)teams->data;
        if (strcmp(tmp->name, buffer) || !tmp->clients_nb)
            continue;
        send_infos(client, tmp->clients_nb, game->height, game->width);
        tmp->clients_nb--;
        client->team_name = strdup(tmp->name);
        return;
    }
    delete_client(client, buffer);
    return;
}
