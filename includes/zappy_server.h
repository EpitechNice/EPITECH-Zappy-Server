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
    #define LENGTH_COMMAND 4096

/* ---------TYPEDEFS--------- */

typedef struct connection_information {
    int port;
    int socket;
    struct sockaddr_in *address;
} connect_t;

typedef struct all_teams_infos_s {
    char *name;
    int clients_nb;
} team_t;

typedef struct all_game_infos_s {
    int width;
    int height;
    int freq;
    lnode_t *teams;
} game_t;

typedef struct all_server_infos_s {
    bool initialized;
    bool running;
    int fd_max;
    fd_set read_fds;
    fd_set write_fds;
    fd_set error_fds;
    lnode_t *clients;
    connect_t *info;
    game_t *game;
} server_t;

/* ---------PROTOTYPES--------- */

void accept_new_connection(server_t *);
server_t *get_server(void);
connect_t *init_connection(parsing_t *);
game_t *init_game(parsing_t *);
void destroy_server_exit(int);
void destroy_server(void);
void run(server_t *);

#endif /* !ZAPPY_SERVER_H_ */
