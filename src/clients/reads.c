/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** reand_client
*/

#include "zappy_server.h"

static void get_ip(char *ip, struct sockaddr_in *infos)
{
    inet_ntop(AF_INET, &infos->sin_addr, ip, INET_ADDRSTRLEN);
}

void accept_new_connection(server_t *server)
{
    struct sockaddr_in info;
    socklen_t len = sizeof(struct sockaddr_in);
    int fd = accept(server->info->socket, (struct sockaddr *) &info, &len);
    char ip[INET_ADDRSTRLEN];

    if (fd == -1)
        perror("Accept failed\n");
    get_ip(ip, &info);
    LOG(LOG_LEVEL_INFO, "Got connection from %s on port %u", ip, info.sin_port);
    dl_push_back(&server->clients, (void *)init_client(fd));
    dprintf(fd, "WELCOME\n");
    return;
}

static void waiting_client_command(client_t *client, char *buffer)
{
    if (strcmp(buffer, GUI_CONNECT) == 0)
        handle_new_gui(client);
    else
        handle_new_ai(client, buffer);
}

static void handle_commands(client_t *client, char *buffer)
{
    if (client->status == WAITING)
        return waiting_client_command(client, buffer);
    if (client->status == AI)
        return handle_ai_command(client, buffer);
    if (client->status == GUI)
        return handle_gui_command(client, buffer);
}

static int read_client(client_t *client, char *buffer)
{
    int value = -1;
    server_t *server = get_server();

    value = read(client->fd, buffer, LENGTH_COMMAND);
    if (value <= 0) {
        LOG(LOG_LEVEL_WARNING, "Invalid read on fd %i. Closing connection", client->fd);
        dl_erase(&server->clients, (void *)client, &is_client, &free_client);
        return 1;
    }
    for (int i = 0; i < value; i++)
        if (buffer[i] == '\r' || buffer[i] == '\n')
            buffer[i] = '\0';
    return 0;
}

void handle_client(client_t *client)
{
    char *buffer = malloc(LENGTH_COMMAND + 1);

    if (!buffer)
        return;
    if (read_client(client, buffer) == 1) {
        free(buffer);
        return;
    }
    handle_commands(client, buffer);
    free(buffer);
}
