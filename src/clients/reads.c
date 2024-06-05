/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** reand_client
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

static void waiting_client_command(client_t *client, char *buffer)
{
    if (strcmp(buffer, "GUI") == 0) {
        client->status = GUI;
        client->team_name = strdup("GUI");
        dl_push_back(&client->to_send, (char *)strdup("GUI init"));
    } else
        handle_new_ai(client, buffer);
}

static void handle_commands(client_t *client, char *buffer)
{
    if (client->status == WAITING)
        return waiting_client_command(client, buffer);
    if (client->status == IA)
        printf("IA\n");
    if (client->status == GUI)
        printf("GUI\n");
}

static char *read_client(client_t *client, char *buffer)
{
    int value = -1;
    server_t *server = get_server();

    value = read(client->fd, buffer, LENGTH_COMMAND);
    if (value <= 0) {
        dl_erase(&server->clients, (void *)client, &is_client, &free_client);
        return NULL;
    }
    for (int i = 0; i < value; i++)
        if (buffer[i] == '\r' || buffer[i] == '\n')
            buffer[i] = '\0';
    return buffer;
}

void handle_client(client_t *client)
{
    char *buffer = malloc(sizeof(char) * LENGTH_COMMAND);
    buffer = read_client(client, buffer);

    if (buffer == NULL) {
        free(buffer);
        return;
    }
    handle_commands(client, buffer);
    free(buffer);
}
