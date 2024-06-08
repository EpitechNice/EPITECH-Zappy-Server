/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"

const char *cmd[] = {
    "msz", "bct", "mct", "tna",
    "ppo", "plv",// "pin", "sgt",
    // "sst"
};

command_func_t _func[] = {
    command_msz, command_bct, command_mct, command_tna,
    command_ppo, command_plv,// command_pin, command_sgt,
    //command_sst
};

void handle_gui_command(client_t *client, const char *buffer)
{
    char **args = stowa(buffer, " \t\n");
    long unsigned int i;

    for (i = 0; i < sizeof(_func) / sizeof(_func[0]); i++)
        if (strncmp(args[0], cmd[i], strlen(cmd[i])) == 0) {
            _func[i](args, client);
            free_tab(args);
            return;
        }
    free_tab(args);
    return;
}

void handle_new_gui(client_t *client)
{
    client->status = GUI;
    client->team_name = strdup("GUI");
    return;
}
