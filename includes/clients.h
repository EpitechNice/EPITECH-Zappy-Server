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

/* ---------PROTOTYPES--------- */

void free_clients(void *data);
void delete_client(void *data);
bool is_client(void *ref, void *data);
client_t *init_clients(int fd);

#endif /* !CLIENTS_H_ */
