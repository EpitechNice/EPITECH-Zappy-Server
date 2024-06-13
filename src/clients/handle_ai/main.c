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

void handle_new_ai(client_t *client, const char *team_name)
{
    client->team_name = strdup(team_name);
    client->status = AI;
}
