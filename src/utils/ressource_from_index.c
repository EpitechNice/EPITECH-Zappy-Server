/*
** EPITECH PROJECT, 2024
** Server
** File description:
** ressource_from_index
*/

#include "zappy_server.h"

void ressource_from_index(items_t index, char *out)
{
    if (index == FOOD)
        strcpy(out, "food");
    if (index == LINEMATE)
        strcpy(out, "linemate");
    if (index == DERAUMERE)
        strcpy(out, "deraumere");
    if (index == SIBUR)
        strcpy(out, "sibur");
    if (index == MENDIANE)
        strcpy(out, "mendiane");
    if (index == PHIRAS)
        strcpy(out, "phiras");
    if (index == THYSTAME)
        strcpy(out, "thystame");
}