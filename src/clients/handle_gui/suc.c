/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** suc
*/

#include "gui.h"

void command_suc(client_t *client)
{
    dl_push_back(&client->to_send, strdup("suc"));
}
