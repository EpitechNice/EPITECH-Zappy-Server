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


enum direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum items {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

enum status {
    WAITING,
    IA,
    GUI
};

typedef struct client_structure_infos {
    int fd;
    int x;
    int y;
    int level;
    int direction;
    int inventory[7];
    char *team_name;
    enum status _status;
    mlist_t to_send;
} client_t;

/* ---------PROTOTYPES--------- */

client_t *init_clients(int);
void handle_client(client_t *);

#endif /* !CLIENTS_H_ */
