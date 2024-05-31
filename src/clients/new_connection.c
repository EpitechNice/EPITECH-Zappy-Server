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
    client_t *client;
    int fd = accept(server->info->socket, (struct sockaddr *) &info, &len);

    if (fd == -1)
        perror("Accept failed\n");
    client = init_clients(fd);
    m_list_add_at_pos(&server->clients, m_list_new(client), MLIST_POS_LAST);
    dprintf(fd, "WELCOME\n");
    return;
}
