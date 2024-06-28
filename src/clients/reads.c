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
    LOG(LOG_LEVEL_INFO, "Got connection from %s on port %u",
    ip, info.sin_port);
    dl_push_back(&server->clients, (void *)init_client(fd));
    dprintf(fd, "WELCOME\n");
    return;
}

static void waiting_client_command(client_t *client)
{
    char *buffer = dl_pop_front(&client->command_list);

    if (strcmp(buffer, GUI_CONNECT) == 0)
        handle_new_gui(client);
    else
        handle_new_ai(client, buffer);
}

static void handle_commands(client_t *client)
{
    if (client->status == NONE)
        return waiting_client_command(client);
    if (client->status == GUI)
        return handle_gui_command(client);
}

static int read_client(client_t *client, char *buffer)
{
    int value = -1;
    char **commands;

    value = read(client->fd, buffer, LENGTH_COMMAND);
    if (value <= 0) {
        LOG(LOG_LEVEL_WARNING, "Invalid read on fd %i. Closing connection",
        client->fd);
        FD_SET(client->fd, &get_server()->error_fds);
        return 1;
    }
    buffer[value] = '\0';
    commands = stowa(buffer, "\n");
    for (int i = 0; commands[i]; i++)
        dl_push_back(&client->command_list, strdup(commands[i]));
    free_tab(commands);
    return 0;
}

void handle_client(client_t *client)
{
    char buffer[LENGTH_COMMAND + 1];

    if (!read_client(client, buffer))
        handle_commands(client);
}
