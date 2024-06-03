/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** clients
*/

#include "zappy_server.h"

client_t *init_clients(int fd)
{
    client_t *clients = (client_t *)fmalloc(sizeof(client_t));

    clients->fd = fd;
    clients->to_send = NULL;
    return (clients);
}

static void handle_commands(client_t *client, char *buffer)
{
    server_t *server = get_server();
    char *data = "TG JESUS\n";

    if (strcmp(buffer, "GUI") == 0) {
        client->_status = GUI;
        client->team_name = "GUI";
        m_list_add_at_pos(&client->to_send, m_list_new((char *)strdup(data)), MLIST_POS_LAST);
    } else if (strcmp(buffer, "AI") == 0) {
        printf("AI\n");
    }
}

static char *read_client(client_t *client)
{
    server_t *server = get_server();
    char *buffer = NULL;
    int value = -1;

    buffer = fmalloc(sizeof(char) * LENGTH_COMMAND);
    if (!buffer)
        return NULL;
    value = read(client->fd, buffer, LENGTH_COMMAND);
    for (int i = 0; i < value; i++)
        if (buffer[i] == '\r' || buffer[i] == '\n')
            buffer[i] = '\0';
    return buffer;
}

void handle_client(client_t *client)
{
    char *buffer = read_client(client);

    if (buffer == NULL)
        return;
    handle_commands(client, buffer);
    ffree(buffer);
}

void write_command(client_t *client)
{
    char *buffer = NULL;
    while (client->to_send != NULL) {
        buffer = (char *)m_list_pop(client->to_send);
        dprintf(client->fd, "%s\n", buffer);
        free(buffer);
    }
}