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
    AI,
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

typedef void(*command_func_t) (char **, client_t *);

/* ---------PROTOTYPES--------- */

client_t *init_client(int);
void handle_client(client_t *);
void write_command(client_t *);
void free_client(void *);
bool is_client(void *, void *);
void handle_new_ai(client_t *, const char *);
void handle_new_gui(client_t *);
void handle_gui_command(client_t *, const char *);
void command_msz(char **, client_t *);
void command_bct(char **, client_t *);
void command_mct(char **, client_t *);
void command_tna(char **, client_t *);
void command_ppo(char **, client_t *);
void command_plv(char **, client_t *);
void command_pin(char **, client_t *);
// void command_sgt(char **, client_t *);
// void command_sst(char **, client_t *);

#endif /* !CLIENTS_H_ */
