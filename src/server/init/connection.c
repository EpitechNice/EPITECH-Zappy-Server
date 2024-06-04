/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** connection
*/

#include "zappy_server.h"

static void create_socket(connect_t *connect)
{
    connect->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (connect->socket == -1) {
        perror("Error: socket creation failed\n");
        destroy_server_exit(84);
    }
    if (setsockopt(connect->socket, SOL_SOCKET, SO_REUSEADDR,
        &(int){1}, sizeof(int)) < 0) {
        perror("Error: socket option failed\n");
        destroy_server_exit(84);
    }
}

static void bind_socket(connect_t *connect)
{
    connect->address = malloc(sizeof(struct sockaddr_in));
    connect->address->sin_family = AF_INET;
    connect->address->sin_addr.s_addr = INADDR_ANY;
    connect->address->sin_port = htons(connect->port);
    if (bind(connect->socket, (struct sockaddr *)connect->address,
        sizeof(struct sockaddr_in)) == -1) {
        perror("Error: socket binding failed\n");
        destroy_server_exit(84);
    }
}

static void port_socket(connect_t *connect)
{
    socklen_t len;

    if (connect->port == 0) {
        len = sizeof(connect->address);
        if (getsockname(connect->socket, (struct sockaddr *)connect->address,
            &len) == -1) {
            perror("Error: socket port failed\n");
            destroy_server_exit(84);
        }
        connect->port = ntohs(connect->address->sin_port);
    }
}

static void listen_socket(connect_t *connect)
{
    if (listen(connect->socket, MAX_CLIENTS) == -1) {
        perror("Error: socket listen failed\n");
        destroy_server_exit(84);
    }
}

connect_t *init_connection(parsing_t *p)
{
    connect_t *connect = (connect_t *)malloc(sizeof(connect_t));

    connect->port = p->port;
    connect->socket = -1;
    connect->address = NULL;
    create_socket(connect);
    bind_socket(connect);
    port_socket(connect);
    listen_socket(connect);
    return connect;
}
