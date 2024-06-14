/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_forward
*/

#include "zappy_server.h"

bool remove_client(void *ref, void *client)
{
    if (ref == client)
        return true;
    return false;
}

static void move_client(char *direction, client_t *client)
{
    switch (client->direction) {
        case UP:
            client->x--;
            strcpy(direction, "up");
            break;
        case RIGHT:
            client->y++;
            strcpy(direction, "right");
            break;
        case DOWN:
            client->x++;
            strcpy(direction, "down");
            break;
        case LEFT:
            client->y--;
            strcpy(direction, "left");
            break;
        default:
            break;
    }
    round_world(&client->x, &client->y);
}

void command_forward(UNUSED char **args, client_t *client)
{
    char direction[6] = {0};

    dl_erase(&get_server()->game->map[client->y][client->x].players, client,
        &remove_client, NULL);
    move_client(direction, client);
    dl_push_back(&get_server()->game->map[client->y][client->x].players,
        client);
    LOG(LOG_LEVEL_DEBUG, "Client of team %s moved forward facing %s",
        client->team_name, direction);
    round_world(&client->x, &client->y);
    dl_push_back(&client->to_send, strdup("ok"));
}
