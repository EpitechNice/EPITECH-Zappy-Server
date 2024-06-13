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
    char *buffer;
    char *team_name;
    status_t status;
    lnode_t *to_send;
} client_t;

typedef struct {
    char *message;
    client_t *source;
} yell_infos_t;

typedef unsigned char uchar;

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
void command_smg(char **);
void command_pnw(const char *);
void command_seg(const char *);
void command_pdi(int);
void command_pex(int);
void command_pfk(int);
void command_ebo(int);
void command_edi(int);
void command_pdr(int, int);
void command_pgt(int, int);
void command_pie(int, int, bool);
void command_pbc(int, const char *);
void command_enw(int, client_t *);
void command_msz(char **, client_t *);
void command_bct(char **, client_t *);
void command_mct(char **, client_t *);
void command_tna(char **, client_t *);
void command_ppo(char **, client_t *);
void command_plv(char **, client_t *);
void command_pin(char **, client_t *);
void command_sgt(char **, client_t *);
void command_sst(char **, client_t *);
void command_suc(client_t *);

void command_forward(char **args, client_t *client);
void command_right(char **args, client_t *client);
void command_left(char **args, client_t *client);
void command_look(char **args, client_t *client);
void command_inventory(char **args, client_t *client);
void command_broadcast(char **args, client_t *client);
void command_co_nbr(char **args, client_t *client);
void command_fork(char **args, client_t *client);
void command_eject(char **args, client_t *client);
void command_take(char **args, client_t *client);
void command_set(char **args, client_t *client);
void command_incantation(char **args, client_t *client);

#endif /* !CLIENTS_H_ */
