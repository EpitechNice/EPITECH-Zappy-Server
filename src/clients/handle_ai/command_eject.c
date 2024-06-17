/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_eject
*/

#include "ai.h"

static void free_egg(void *egg)
{
    free(egg);
}

static bool cmp_eggs(void *ref, void *egg)
{
    return ref == egg;
}

static void delete_eggs(void *egg)
{
    dl_erase(&get_server()->game->eggs, egg, cmp_eggs, free_egg);
}

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

static void move_him(void *_target, void *_origin)
{
    client_t *target = (client_t *)_target;
    client_t *origin = (client_t *)_origin;
    direction_t final = invert_direction(origin->direction);
    char *out = NULL;
    UNUSED int _;

    if (target == origin)
        return;
    physic_move(target, origin->direction);
    final -= target->direction;
    final += LEFT + 1;
    final %= LEFT + 1;
    _ = asprintf(&out, "eject: %i", get_pos_from_direction(final));
    dl_push_back(&target->to_send, out);
}

void command_eject(UNUSED char **args, client_t *client)
{
    dl_apply_data_param(get_server()->game->map[client->y][client->x].players,
        &move_him, client);
    dl_apply_data(get_server()->game->map[client->y][client->x].eggs,
    delete_eggs);
    LOG(LOG_LEVEL_INFO, "Client of team %s pushed everyone in direction %i",
        client->team_name, client->direction);
    client->next_action_time = get_server()->global_time_stamp + 7;
}
