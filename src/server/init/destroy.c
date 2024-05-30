/*
** EPITECH PROJECT, 2024
** server
** File description:
** network
*/

#include "zappy_server.h"

void destroy_connection(connect_t *connect)
{
    if (connect->socket != -1)
        close(connect->socket);
    if (connect->address != NULL)
        ffree(connect->address);
    ffree(connect);
}

void destroy_server(void)
{
    server_t *server = get_server();

    if (server->info)
        destroy_connection(server->info);
}

void destroy_server_exit(int exit_code)
{
    destroy_server();
    exit(exit_code);
}
