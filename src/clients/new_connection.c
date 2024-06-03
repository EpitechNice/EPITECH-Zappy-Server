/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** new_connection
*/

#include "zappy_server.h"

void accept_new_connection(server_t *server)
{
    struct sockaddr_in info;
    socklen_t len = sizeof(struct sockaddr_in);
    int fd = accept(server->info->socket, (struct sockaddr *) &info, &len);

    if (fd == -1)
        perror("Accept failed\n");
    dl_push_back(&server->clients, (void *)init_client(fd));
    dprintf(fd, "WELCOME\n");
    return;
}
