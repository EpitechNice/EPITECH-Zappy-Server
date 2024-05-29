/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** clients
*/

#ifndef CLIENTS_H_
    #define CLIENTS_H_

    #include "includes.h"
    #include "zappy_server.h"

/* ---------STRUCTS--------- */

typedef struct client_structure_infos {
    int fd;
    int x;
    int y;
    int level;
    int direction;
    int inventory[7];
    lnode_t *to_send;
} client_t;

    typedef struct client_ai_infos {
        int fd;
        int x;
        int y;
        int level;
        int direction;
        int inventory[7];
        lnode_t *to_send;
    } ai_t;

    typedef struct client_gui_infos {
        int fd;
        lnode_t *to_send;
    } gui_t;

/* ---------PROTOTYPES--------- */

void free_clients(void *);
void delete_client(void *);
void accept_new_connection(server_t *);
bool is_client(void *, void *);
client_t *init_clients(int);

#endif /* !CLIENTS_H_ */
