/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_ai
*/

#include "zappy_server.h"

void handle_gui_command(UNUSED client_t *client, UNUSED const char *buffer)
{
    
    return;
}

void handle_new_gui(client_t *client)
{
    client->status = GUI;
    client->team_name = strdup("GUI");
    return;
}
