/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"

const char *ai_cmd[] = {
    "forward", "right", "left", "look", "inventory", "broadcast",
    "connect_nbr", "fork", "eject", "take", "set", "incantation"
};

const command_func_t ai_func[] = {
    command_forward, command_right, command_left, command_look,
    command_inventory, command_broadcast, command_co_nbr,
    command_fork, command_eject, command_take, command_set,
    command_incantation
};

const uchar ai_nb_func = 12;

static inline void to_lower(char *arg)
{
    for (unsigned i = 0; arg[i]; ++i)
        arg[i] = (arg[i] > 0x40 && arg[i] < 0x5b) ? (arg[i] - 0x20) : (arg[i]);
}

void handle_ai_command(client_t *client, const char *buffer)
{
    char **args;
    uchar i = 0;

    str_append(client->buffer, buffer);
    if (buffer[strlen(buffer) - 1] != '\n')
        return;
    args = stowa(client->buffer, " \t\n");
    free(client->buffer);
    client->buffer = NULL;
    to_lower(args[0]);
    for (; i < ai_nb_func; ++i) {
        if (!strcmp(args[0], ai_cmd[i])) {
            free(args[0]);
            ai_func[i](args, client);
            free_tab(args);
            return;
        }
    }
    free_tab(args);
}

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
    dl_push_back(&client->to_send, strdup(out));
    free(out);
    out = NULL;
    if (asprintf(&out, "%i %i", height, width) <= 0)
        LOG(LOG_LEVEL_CRITICAL, "Error running asprintf (allocation)");
    dl_push_back(&client->to_send, strdup(out));
    client->status = AI;
    free(out);
}

void handle_new_ai(client_t *client, const char *buffer)
{
    game_t *game = get_server()->game;
    lnode_t *teams = game->teams;
    team_t *tmp;
    char *out = NULL;

    for (; teams; teams = teams->next) {
        tmp = (team_t *)teams->data;
        if (strcmp(tmp->name, buffer) || !tmp->clients_nb)
            continue;
        send_infos(client, tmp->clients_nb, game->height, game->width);
        tmp->clients_nb--;
        client->team_name = strdup(tmp->name);
        asprintf(&out, "pnw %i %i %i %i %i %s", client->fd, client->x,
            client->y, client->direction, client->level, client->team_name);
        command_pnw(out);
        free(out);
        return;
    }
    delete_client(client, buffer);
    return;
}
