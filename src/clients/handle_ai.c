/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"


void handle_new_ai(client_t *client, char *buffer)
{
    game_t *game = get_server()->game;
    lnode_t *teams = game->teams;
    char *str = NULL;

    while (teams) {
        team_t *tmp = (team_t *)teams->data;
        if (strcmp(tmp->name, buffer) == 0 && tmp->clients_nb > 0) {
            asprintf(&str, "%d", tmp->clients_nb);
            dl_push_back(&client->to_send, str);
            str = NULL;
            tmp->clients_nb--;
            asprintf(&str, "%d %d", game->height, game->width);
            dl_push_back(&client->to_send, str);
            client->status = IA;
            client->team_name = strdup(tmp->name);
            return;
        }
        teams = teams->next;
    }
    return;
}
