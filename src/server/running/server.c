/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "zappy_server.h"

static void clear_server(server_t *server)
{
    // struct linked_list_node *users = get_server()->user;

    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->error_fds);
    // FD_SET(server->connect_info->socket, &server->read_fds);
    // for (; users; users = users->next) {
    //     FD_SET(((user_t *)(users->data))->fd, &server->read_fds);
    //     FD_SET(((user_t *)(users->data))->fd, &server->write_fds);
    //     FD_SET(((user_t *)(users->data))->fd, &server->error_fds);
    // }
}

static void loop(server_t *server)
{
    struct timeval tv;

    clear_server(server);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    if (select(MAX_CLIENTS, &server->read_fds,
    &server->write_fds, &server->error_fds, &tv) < 0) {
        perror("Select failed\n");
        destroy_server_exit(84);
    }
    // manage(); TODO @Dan13615 : entry point to manage the server
}

void run(server_t *server)
{
    FD_ZERO(&server->error_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->read_fds);
    FD_SET(server->info->socket, &server->read_fds);
    server->running = true;
    while (server->running)
        loop(server);
}