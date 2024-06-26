/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_eject
*/

#include "ai.h"
#include "gui.h"

static direction_t invert_direction(direction_t direction)
{
    switch (direction) {
        case UP:
            return DOWN;
        case RIGHT:
            return LEFT;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        default:
            break;
    }
    return UP;
}

static char get_pos_from_direction(direction_t direction)
{
    switch (direction) {
        case UP:
            return 1;
        case RIGHT:
            return 7;
        case DOWN:
            return 5;
        case LEFT:
            return 3;
        default:
            break;
    }
    return 0;
}

static bool remove_client(void *ref, void *client)
{
    if (ref == client)
        return true;
    return false;
}

static void physic_move(client_t *target, direction_t direction)
{
    int x = target->x;
    int y = target->y;

    if (direction == UP)
        y--;
    if (direction == RIGHT)
        x++;
    if (direction == DOWN)
        y++;
    if (direction == LEFT)
        x--;
    dl_erase(&get_server()->game->map[target->y][target->x].players, target,
        &remove_client, NULL);
    target->x = x;
    target->y = y;
    round_world(&target->x, &target->y);
    dl_push_back(&get_server()->game->map[target->y][target->x].players,
        target);
}

static void move_him(client_t *target, client_t *origin)
{
    direction_t final = invert_direction(origin->direction);
    char *out2[3] = {"ppo", NULL, NULL};
    UNUSED int _ = asprintf(&out2[1], "%d", target->fd);
    char *out = NULL;

    if (target == origin)
        return;
    physic_move(target, origin->direction);
    final -= target->direction;
    final += LEFT + 1;
    final %= LEFT + 1;
    _ = asprintf(&out, "eject: %i", get_pos_from_direction(final));
    dl_push_back(&target->to_send, out);
    command_pex(target->fd);
    for (lnode_t *tmp = get_server()->clients; tmp; tmp = tmp->next)
        if (((client_t *)tmp->data)->status == GUI)
            command_ppo(out2, target);
}

bool egg_cmp(void *ref, void *data)
{
    if (((egg_t *)data)->id == ((egg_t *)ref)->id)
        return true;
    return false;
}

void command_eject(UNUSED char **args, client_t *client)
{
    for (lnode_t *tmp = get_server()->game->map[client->y][client->x].players;
    tmp; tmp = tmp->next)
        move_him(tmp->data, client);
    for (lnode_t *tmp = get_server()->game->map[client->y][client->x].eggs;
    tmp != NULL; tmp = tmp->next) {
        command_edi(((egg_t *)(tmp->data))->id);
    }
    dl_clear(&get_server()->game->map[client->y][client->x].eggs, NULL);
    LOG(LOG_LEVEL_INFO, "Client of team %s pushed everyone in direction %i",
        client->team_name, client->direction);
    client->next_action = get_time() + 7 * 1000 / get_server()->game->freq;
}
