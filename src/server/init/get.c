/*
** EPITECH PROJECT, 2024
** server
** File description:
** network
*/

#include "zappy_server.h"

static void init_server(server_t *server)
{
    memset(server, 0, sizeof(server_t));
    server->initialized = true;
}

server_t *get_server(void)
{
    static server_t server;

    if (!server.initialized)
        init_server(&server);
    return &server;
}
