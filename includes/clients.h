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

/* ---------MACROS--------- */

    #define GUI_CONNECT "GRAPHIC"
    #define ABS(alpha) ((alpha) >= 0 ? (alpha) : -(alpha))

/* ---------STRUCTS--------- */

typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
} direction_t;

typedef enum {
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6
} items_t;

typedef enum {
    WAITING,
    AI,
    GUI
} status_t;

typedef struct client_structure_infos {
    bool started_an_incantation;
    short ttl;
    int time_before_action;
    int fd;
    int x;
    int y;
    int level;
    int direction;
    int inventory[7];
    char *buffer;
    char *team_name;
    status_t status;
    lnode_t *to_send;
} client_t;

typedef void(*command_func_t) (const char **, client_t *);

/* ---------PROTOTYPES--------- */

client_t *init_client(int);
void handle_client(client_t *);
void write_command(client_t *);
void free_client(void *);
bool is_client(void *, void *);
void handle_new_ai(client_t *, const char *);
void handle_new_gui(client_t *);
void handle_gui_command(client_t *, const char *);
void command_msz(const char **, client_t *);
void command_bct(const char **, client_t *);
void command_mct(const char **, client_t *);
void command_tna(const char **, client_t *);

void command_forward(const char **args, client_t *client);
void command_right(const char **args, client_t *client);
void command_left(const char **args, client_t *client);
void command_look(const char **args, client_t *client);
void command_inventory(const char **args, client_t *client);
void command_broadcast(const char **args, client_t *client);
void command_co_nbr(const char **args, client_t *client);
void command_fork(const char **args, client_t *client);
void command_eject(const char **args, client_t *client);
void command_take(const char **args, client_t *client);
void command_set(const char **args, client_t *client);
void command_incantation(const char **args, client_t *client);

#endif /* !CLIENTS_H_ */
