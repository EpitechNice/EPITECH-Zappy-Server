/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"
#include "gui.h"
#include "ai.h"

const int infos_rit[][7] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1},
};

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

static int death(client_t *client)
{
    LOG(LOG_LEVEL_INFO, "Client %i died of hunger", client->fd);
    FD_SET(client->fd, &get_server()->error_fds);
    dprintf(client->fd, "dead\n");
    command_pdi(client->fd);
    return 1;
}

static void incantation_end(client_t *client)
{
    char *fd = NULL;
    char *out = NULL;
    UNUSED int _ = asprintf(&fd, "%d", client->fd);
    char *arg[3] = {"plv", fd, NULL};

    client->level++;
    client->is_elevating = false;
    client->incant_time = 0;
    LOG(LOG_LEVEL_INFO, "Incantation success for client %i", client->fd);
    LOG(LOG_LEVEL_INFO, "Client %i is level %i", client->fd, client->level);
    command_pie(client->x, client->y, 1);
    for (lnode_t *gui = get_server()->clients; gui; gui = gui->next) {
        if (((client_t *)gui->data)->status == GUI)
            command_plv(arg, gui->data);
    }
    _ = asprintf(&out, "Current level: %d\n", client->level);
    dl_push_back(&client->to_send, strdup(out));
    free(fd);
    free(out);
}

static void check_incantation(client_t *client)
{
    int nb_of_players_of_level_x = 1;

    if (!client->is_elevating)
        return;
    if (client->incant_time > get_time())
        return;
    dl_apply_data_param(get_server()->game->map[client->y][client->x].players,
        check_level, &nb_of_players_of_level_x);
    if (nb_of_players_of_level_x < infos_rit[client->level - 1][0]) {
        client->is_elevating = false;
        return;
    }
    for (int i = 1; i < 7; ++i)
        if (get_server()->game->map[client->y][client->x].ressources[i] <
            infos_rit[client->level - 1][i]) {
            client->is_elevating = false;
            return;
        }
    incantation_end(client);
}

int check_ai(client_t *client, server_t *server)
{
    check_incantation(client);
    if ((get_time() - client->last_meal) <
    (126.0 / (float)server->game->freq) * 1000)
        return 0;
    if (client->inventory[FOOD] == 0)
        return death(client);
    client->inventory[FOOD]--;
    client->last_meal = get_time();
    return 0;
}
