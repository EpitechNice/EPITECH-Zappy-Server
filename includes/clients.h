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

typedef struct {
    bool started_an_incantation;
    short ttl;
    int time_before_action;
    int fd;
    int x;
    int y;
    int level;
    int direction;
    int inventory[7];
    char *team_name;
    status_t status;
    lnode_t *to_send;
} client_t;

typedef struct {
    char *message;
    client_t *source;
} yell_infos_t;

typedef void(*command_func_t) (char **, client_t *);

/* ---------PROTOTYPES--------- */

client_t *init_client(int);
void handle_client(client_t *);
void write_command(client_t *);
void free_client(void *);
bool is_client(void *, void *);
void handle_new_ai(client_t *, const char *);
void handle_new_gui(client_t *);

/**
  * @brief Entry point for the processing of GUI's commands
  *
  * @param client Client that sent the command
  * @param buffer Command sent by the client
*/
void handle_gui_command(client_t *client, const char *buffer);

/**
  * @brief Entry point for the processing of AI's commands
  *
  * @param client Client that sent the command
  * @param buffer Command sent by the client
*/
void handle_ai_command(client_t *client, const char *buffer);

#endif /* !CLIENTS_H_ */
