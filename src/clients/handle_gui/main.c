/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "gui.h"

const char *cmd[] = {
    "msz", "bct", "mct", "tna",
    "ppo", "plv", "pin", "sgt",
    "sst"
};

command_func_t _func[] = {
    command_msz, command_bct, command_mct, command_tna,
    command_ppo, command_plv, command_pin, command_sgt,
    command_sst
};

void handle_gui_command(client_t *client)
{
    char *buffer = dl_pop_front(&client->command_list);
    char **args = stowa(buffer, " \t\n");
    long unsigned int i;

    for (i = 0; i < sizeof(_func) / sizeof(_func[0]); i++)
        if (strncmp(args[0], cmd[i], strlen(cmd[i])) == 0) {
            _func[i](args, client);
            free_tab(args);
            return;
        }
    command_suc(client);
    free_tab(args);
    return;
}

static void send_eggs(client_t *client)
{
    char *out = NULL;
    UNUSED int _;
    game_t *game = get_server()->game;

    for (lnode_t *tmp = game->eggs; tmp; tmp = tmp->next) {
        _ = asprintf(&out, "enw %lu %i %i %i",
        ((egg_t *)tmp->data)->id, 0,
        ((egg_t *)tmp->data)->x,
        ((egg_t *)tmp->data)->y);
        dl_push_back(&client->to_send, strdup(out));
        free(out);
        out = NULL;
    }
}

void handle_new_gui(client_t *client)
{
    char *out = NULL;
    UNUSED int _;

    client->status = GUI;
    client->team_name = strdup("GUI");
    for (lnode_t *tmp = get_server()->clients; tmp; tmp = tmp->next) {
        if (((client_t *)tmp->data)->status == AI) {
            _ = asprintf(&out, "pnw %i %i %i %i %i %s",
            ((client_t *)tmp->data)->fd, ((client_t *)tmp->data)->x,
            ((client_t *)tmp->data)->y, ((client_t *)tmp->data)->direction + 1,
            ((client_t *)tmp->data)->level,
            ((client_t *)tmp->data)->team_name);
            command_pnw(out);
            free(out);
            out = NULL;
        }
    }
    send_eggs(client);
    return;
}
