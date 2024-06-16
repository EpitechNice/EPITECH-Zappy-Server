/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui_send
*/

#include "gui.h"

void send_to_gui(client_t *client)
{
    char *to_send = NULL;
    char *args[2] = {"mct", NULL};

    command_mct(args, client);
    free(to_send);
}