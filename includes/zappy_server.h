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

enum density {
    FOOD_DENSITY = 50,
    LINEMATE_DENSITY = 30,
    DERAUMERE_DENSITY = 15,
    SIBUR_DENSITY = 10,
    MENDIANE_DENSITY = 10,
    PHIRAS_DENSITY = 8,
    THYSTAME_DENSITY = 5
};

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

typedef struct all_map_infos_s {
    lnode_t *players;
    lnode_t *eggs;
    int ressources[7];
} map_t;

typedef struct all_game_infos_s {
    int width;
    int height;
    int freq;
    map_t **map;
    lnode_t *teams;
    lnode_t *eggs;
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

typedef struct {
    char *message;
    client_t *source;
} yell_infos_t;

typedef unsigned char uchar;

/* ---------PROTOTYPES--------- */

void accept_new_connection(server_t *);
server_t *get_server(void);
connect_t *init_connection(parsing_t *);
game_t *init_game(parsing_t *);
void destroy_server_exit(int);
void destroy_server(void);
void run(server_t *);

/**
  * @ingroup server
  *
  * @brief Initiate all pre-run things.
  *
  * @return 0, just to be able to call at the beggining of main
*/
char init(void);

/**
  * @ingroup server
  *
  * @brief Append data to origin, by re allocating
  *
  * @param origin Origin data, can be NULL, and might get changed
  * @param data Data to be written, can be NULL, and will NOT be changed
  *
  * @warning
  * Please take care when using this function, it should not be harmfull, but
  * read how it works first
*/
void str_append(char *origin, const char *data);

/**
  * @ingroup server
  *
  * @brief Convert item into it's name
  *
  * @param index The ressource to be changed
  * @param out Starting position where to write the name. need to be 10 long
*/
void ressource_from_index(items_t index, char *out);

/**
  * @ingroup server
  *
  * @brief Make x and y valid coordinates
*/
void round_world(int *x, int *y);

#endif /* !ZAPPY_SERVER_H_ */
