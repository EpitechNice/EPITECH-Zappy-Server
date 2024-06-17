/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_incantation
*/

#include "ai.h"
#include "gui.h"

// level - 1 to get the index
const int infos_rits[][7] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1},
};
const int max_level = 7;

static int target_level;

static void check_level(void *_client, void *_nb)
{
    client_t *client = (client_t *)_client;
    int *nb = (int *)_nb;

    if (client->level != target_level)
        return;
    (*nb)++;
}

static void event_incantation(client_t *client, int size)
{
    int i = 1;
    int *ai = malloc(sizeof(int) * size);
    lnode_t *players = get_server()->game->map[client->y][client->x].players;

    ai[0] = client->fd;
    for (; players; players = players->next) {
        if (((client_t *)players->data)->level != client->level)
            continue;
        ai[i] = ((client_t *)players->data)->fd;
        i++;
    }
    command_pic(client, ai, size);
    free(ai);
}

void command_incantation(UNUSED char **args, client_t *client)
{
    int nb_of_players_of_level_x = 1;
    char *out = NULL;
    UNUSED int _;

    if (client->level >= max_level)
        return dl_push_back(&client->to_send, strdup("ko"));
    target_level = client->level;
    dl_apply_data_param(get_server()->game->map[client->y][client->x].players,
        check_level, &nb_of_players_of_level_x);
    if (nb_of_players_of_level_x < infos_rits[client->level - 1][0])
        return dl_push_back(&client->to_send, strdup("ko"));
    for (int i = 1; i < 7; ++i)
        if (get_server()->game->map[client->y][client->x].ressources[i] <
            infos_rits[client->level - 1][i])
                return dl_push_back(&client->to_send, strdup("ko"));
    LOG(LOG_LEVEL_INFO, "Client of team %s is starting a level %i ritual",
        client->team_name, client->level);
    _ = asprintf(&out, "Elevation underway\nCurrent level: %i", client->level);
    dl_push_back(&client->to_send, out);
    event_incantation(client, nb_of_players_of_level_x);
}