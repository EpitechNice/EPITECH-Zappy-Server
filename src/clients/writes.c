/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** new_connection
*/

#include "zappy_server.h"

void write_command(client_t *client)
{
    char *buffer = NULL;
    while (client->to_send != NULL) {
        buffer = (char *)dl_pop_back(&client->to_send);
        dprintf(client->fd, "%s\n", buffer);
        free(buffer);
    }
}
