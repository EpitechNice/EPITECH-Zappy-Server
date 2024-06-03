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
    enum status status;
    lnode_t *to_send;
} client_t;

/* ---------PROTOTYPES--------- */

client_t *init_client(int);
void handle_client(client_t *);
void write_command(client_t *);
void free_client(void *);
bool is_client(void *, void *);
void handle_new_ai(client_t *);

#endif /* !CLIENTS_H_ */
