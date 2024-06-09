/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** suc
*/

#include "zappy_server.h"

void command_suc(client_t *client)
{
    dl_push_back(&client->to_send, strdup("suc"));
}
