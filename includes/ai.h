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

/**
 * @brief AI is moving in the current direction
 *
 * @param args Arguments of the command
 * @param client Client who is moving
*/
void command_forward(char **args, client_t *client);

/**
 * @brief AI changing his direction to the right
 *
 * @param args Arguments of the command
 * @param client Client who is moving
*/
void command_right(char **args, client_t *client);

/**
 * @brief AI changing his direction to the left
 *
 * @param args Arguments of the command
 * @param client Client who is moving
*/
void command_left(char **args, client_t *client);

/**
 * @brief AI is looking in the current direction
 *
 * @param args Arguments of the command
 * @param client Client who is looking
*/
void command_look(char **args, client_t *client);

/**
 * @brief AI is looking in his inventory
 *
 * @param args Arguments of the command
 * @param client Client who is looking
*/
void command_inventory(char **args, client_t *client);

/**
 * @brief AI is broadcasting a message
 *
 * @param args Arguments of the command
 * @param client Client who is broadcasting
*/
void command_broadcast(char **args, client_t *client);

/**
 * @brief AI is checking how many clients can connect to his team
 *
 * @param args Arguments of the command
 * @param client Client who is checking
*/
void command_co_nbr(char **args, client_t *client);

/**
 * @brief AI is forking a new client and laying an egg
 *
 * @param args Arguments of the command
 * @param client Client who is forking
*/
void command_fork(char **args, client_t *client);

/**
 * @brief AI is ejecting a client from his tile
 *
 * @param args Arguments of the command
 * @param client Client who is ejecting
*/
void command_eject(char **args, client_t *client);

/**
 * @brief AI is taking an item from the tile
 *
 * @param args Arguments of the command
 * @param client Client who is taking
*/
void command_take(char **args, client_t *client);

/**
 * @brief AI is setting an item on the tile
 *
 * @param args Arguments of the command
 * @param client Client who is setting
*/
void command_set(char **args, client_t *client);

/**
 * @brief AI is starting an incantation
 *
 * @param args Arguments of the command
 * @param client Client who is starting the incantation
*/
void command_incantation(char **args, client_t *client);

#endif /* !AI_H_ */
