/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_forward
*/

#include "ai.h"

bool remove_client(void *ref, void *client)
{
    if (ref == client)
        return true;
    return false;
}

static void move_a_client(char *direction, client_t *client)
{
    if (client->direction == UP) {
        client->x--;
        strcpy(direction, "up");
    }
    if (client->direction == RIGHT) {
        client->y++;
        strcpy(direction, "right");
    }
    if (client->direction == RIGHT) {
        client->x++;
        strcpy(direction, "down");
    }
    if (client->direction == RIGHT) {
        client->y--;
        strcpy(direction, "left");
    }
    round_world(&client->x, &client->y);
}

void command_forward(UNUSED char **args, client_t *client)
{
    char direction[6] = {0};

    dl_erase(&get_server()->game->map[client->y][client->x].players, client,
        &remove_client, NULL);
    move_a_client(direction, client);
    dl_push_back(&get_server()->game->map[client->y][client->x].players,
        client);
    LOG(LOG_LEVEL_DEBUG, "Client of team %s moved forward facing %s",
        client->team_name, direction);
    round_world(&client->x, &client->y);
    client->next_action_time = get_server()->global_time_stamp + 7;
    dl_push_back(&client->to_send, strdup("ok"));
}
