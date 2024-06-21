/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"
#include "gui.h"
#include "ai.h"

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

static void to_lower(char *buffer)
{
    for (int i = 0; buffer[i]; ++i)
        buffer[i] = ((buffer[i] >= 65 && buffer[i] <= 90) ?
            buffer[i] + 32 : buffer[i]);
}

void handle_ai_command(client_t *client, const char *buffer)
{
    char **args = stowa(buffer, " \t\n");

    if (!args)
        return;
    if (client->next_action > get_time()) {
        free_tab(args);
        dl_push_back(&client->to_send, strdup("ko"));
        return;
    }
    to_lower(args[0]);
    for (size_t i = 0; i < sizeof(ai_func) / sizeof(ai_func[0]); i++) {
        if (!strncmp(args[0], ai_cmd[i], strlen(ai_cmd[i]))) {
            ai_func[i](args, client);
            free_tab(args);
            return;
        }
    }
    dl_push_back(&client->to_send, strdup("ko"));
    free_tab(args);
}

static void send_infos(client_t *client, int nb_clients, int height, int width)
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

void handle_new_ai(client_t *client, const char *buffer)
{
    game_t *game = get_server()->game;
    lnode_t *teams = game->teams;
    team_t *tmp;
    char *out = NULL;
    UNUSED int _;

    for (; teams; teams = teams->next) {
        tmp = (team_t *)teams->data;
        if (strcmp(tmp->name, buffer) || !tmp->clients_nb)
            continue;
        send_infos(client, tmp->clients_nb, game->height, game->width);
        tmp->clients_nb--;
        client->team_name = strdup(tmp->name);
        _ = asprintf(&out, "pnw %i %i %i %i %i %s", client->fd, client->x,
            client->y, client->direction, client->level, client->team_name);
        command_pnw(out);
        free(out);
        return;
    }
    FD_SET(client->fd, &get_server()->error_fds);
}

static int death(client_t *client)
{
    LOG(LOG_LEVEL_INFO, "Client %i died of hunger", client->fd);
    FD_SET(client->fd, &get_server()->error_fds);
    dprintf(client->fd, "dead\n");
    command_pdi(client->fd);
    return 1;
}

static void check_incantation(UNUSED client_t *client, UNUSED server_t *server)
{
    return;
}

int check_ai(client_t *client, server_t *server)
{
    check_incantation(client, server);
    if ((get_time() - client->last_meal) < (126.0 / (float)server->game->freq) * 1000)
        return 0;
    if (client->inventory[FOOD] == 0)
        return death(client);
    client->inventory[FOOD]--;
    client->last_meal = get_time();
    return 0;
}
