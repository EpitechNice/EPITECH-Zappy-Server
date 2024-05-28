/*
** EPITECH PROJECT, 2024
** server
** File description:
** zappy_server
*/

#ifndef ZAPPY_SERVER_H_
    #define ZAPPY_SERVER_H_

/* ---------INCLUDES--------- */

    #include "includes.h"
    #include "parsing.h"
    #include "utils.h"
    #include "clients.h"

/* ---------MACROS--------- */

    #define MAX_CLIENTS 1024

    enum direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

/* ---------TYPEDEFS--------- */

    typedef struct connection_information {
        int port;
        int socket;
        struct sockaddr_in *address;
    } connect_t;

    typedef struct all_server_infos_s {
        bool initialized;
        bool running;
        int fd_max;
        fd_set read_fds;
        fd_set write_fds;
        fd_set error_fds;
        connect_t *info;
        lnode_t *clients;
        client_t *current_client;
    } server_t;

/* ---------PROTOTYPES--------- */

server_t *get_server(void);
connect_t *init_connection(parsing_t *p);
void destroy_server_exit(int);
void destroy_server(void);
void run(server_t *server);

#endif /* !ZAPPY_SERVER_H_ */
