/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** reand_client
*/

#include "zappy_server.h"

static void handle_commands(client_t *client, char *buffer)
{
    char *data = "TG JESUS\n";

    if (strcmp(buffer, "GUI") == 0) {
        client->_status = GUI;
        client->team_name = "GUI";
        dl_push_back(&client->to_send, (char *)strdup(data));
    } else if (strcmp(buffer, "AI") == 0) {
        printf("AI\n");
    }
}

static char *read_client(client_t *client)
{
    server_t *server = get_server();
    char *buffer = NULL;
    int value = -1;

    buffer = malloc(sizeof(char) * LENGTH_COMMAND);
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
    free(buffer);
}
