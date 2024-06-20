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
    unsigned long global_egg_id;
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
    struct timeval time_val;
} server_t;

typedef struct {
    unsigned long id;
    char *team_name;
    int x;
    int y;
} egg_t;

/* ---------PROTOTYPES--------- */

/**
 * @ingroup server
 *
 * @brief Accept a new connection on the server
 *  and add it to the clients list
 *
 * @param server The server to accept the connection on
*/
void accept_new_connection(server_t *server);

/**
 * @ingroup server
 *
 * @brief Singleton function to get the server
 *
 * @return The server
*/
server_t *get_server(void);

/**
 * @ingroup server
 *
 * @brief Initialize the server
 *
 * @param p The parsing structure with all the informations
 *
 * @return The server connection informations
*/
connect_t *init_connection(parsing_t *p);

/**
 * @ingroup server
 *
 * @brief Initialize the game
 *
 * @param p The parsing structure with all the informations
 *
 * @return The game structure
*/
game_t *init_game(parsing_t *p);

/**
 * @ingroup server
 *
 * @brief Destroy the server
*/
void destroy_server(void);

/**
 * @ingroup server
 *
 * @brief run the server
 *
 * @param server The server to run
*/
void run(server_t *server);

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
  * @param origin Adress of the origin data, might get changed by realloc
  * @param data Data to be written, can be NULL, and will NOT be changed
  *
  * @warning
  * Please take care when using this function, it should not be harmfull, but
  * read how it works first
*/
void str_append(char **origin, const char *data);

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

/**
  * @ingroup server
  *
  * @brief Completly remove a client of the server.
  *
  * @param client Pointer to the client to remove
  *
  * @note
  * This function will also remove the client from the tile it was on
*/
void delete_client(client_t *client);

/**
  * @ingroup server
  *
  * @brief Free an egg
  *
  * @param data egg to be freed
*/
void free_egg(void *data);

/**
  * @ingroup server
  *
  * @brief Move the client from it's tile to the x y tile.
  *
  * @param client Client to move
  * @param x X of the new tile
  * @param y Y of the new tile
*/
void move_client(client_t *client, int x, int y);

/**
  * @ingroup server
  *
  * @brief Spread ressources all over the map
  *
  * @param game Game ptr to use
  *
  * @note
  * You can't controle how / where ressources will go.
  * This will be pure rand() on where will ressources go.
*/
void spread_ressources(game_t *game);

#endif /* !ZAPPY_SERVER_H_ */
