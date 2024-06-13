/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "zappy_server.h"

static void manage(server_t *server)
{
    lnode_t *cli = server->clients;

    if (FD_ISSET(server->info->socket, &server->read_fds)) {
        accept_new_connection(server);
        return;
    }
    for (; cli; cli = cli->next) {
        if (FD_ISSET(((client_t *)(cli->data))->fd, &server->error_fds)) {
            dl_erase(&server->clients, (void *)cli, &is_client, &free_client);
            return;
        }
        if (FD_ISSET(((client_t *)(cli->data))->fd, &server->read_fds)) {
            handle_client(((client_t *)(cli->data)));
            break;
        }
        if (FD_ISSET(((client_t *)(cli->data))->fd, &server->write_fds)) {
            write_command(((client_t *)(cli->data)));
        }
    }
}

static void clear_server(server_t *server)
{
    lnode_t *clients = get_server()->clients;

    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->error_fds);
    FD_SET(server->info->socket, &server->read_fds);
    for (; clients; clients = clients->next) {
        FD_SET(((client_t *)(clients->data))->fd, &server->read_fds);
        FD_SET(((client_t *)(clients->data))->fd, &server->write_fds);
        FD_SET(((client_t *)(clients->data))->fd, &server->error_fds);
    }
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
        exit(84);
    }
    manage(server);
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
