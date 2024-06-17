/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ai
*/

#ifndef AI_H_
    #define AI_H_

    #include "zappy_server.h"
    #include "clients.h"

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

#endif /* !AI_H_ */
