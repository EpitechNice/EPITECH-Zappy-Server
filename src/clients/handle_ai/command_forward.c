/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_forward
*/

#include "ai.h"
#include "gui.h"

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
    if (client->direction == DOWN) {
        client->x++;
        strcpy(direction, "down");
    }
    if (client->direction == LEFT) {
        client->y--;
        strcpy(direction, "left");
    }
    round_world(&client->x, &client->y);
}

void command_forward(UNUSED char **args, client_t *client)
{
    char direction[6] = {0};
    char *fd = NULL;
    UNUSED int _ = asprintf(&fd, "%d", client->fd);

    dl_erase(&get_server()->game->map[client->x][client->y].players, client,
        &remove_client, NULL);
    move_a_client(direction, client);
    dl_push_back(&get_server()->game->map[client->x][client->y].players,
        client);
    LOG(LOG_LEVEL_DEBUG, "Client of team %s moved forward facing %s",
        client->team_name, direction);
    round_world(&client->x, &client->y);
    dl_push_back(&client->to_send, strdup("ok"));
    for (lnode_t *tmp = get_server()->clients; tmp != NULL; tmp = tmp->next)
        if (((client_t *)(tmp->data))->status == GUI)
            command_ppo((char *[]){"ppo", fd, NULL},
                (client_t *)(tmp->data));
    free(fd);
    client->next_action = get_time() + 7 * 1000 / get_server()->game->freq;
}
