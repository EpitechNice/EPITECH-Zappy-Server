/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "zappy_server.h"

static void manage(server_t *server)
{
    lnode_t *cl = server->clients;

    if (FD_ISSET(server->info->socket, &server->read_fds))
        return;
    for (; cl; cl = cl->next) {
        server->current_client = (client_t *)(cl->data);
        if (FD_ISSET(((client_t *)(cl->data))->fd, &server->error_fds)) {
            dl_erase(&server->clients, (void *)cl, &is_client, &delete_client);
            return;
        }
        if (FD_ISSET(((client_t *)(cl->data))->fd, &server->read_fds))
            break;
        if (FD_ISSET(((client_t *)(cl->data))->fd, &server->write_fds)) {
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
        destroy_server_exit(84);
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
