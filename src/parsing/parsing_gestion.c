/*
** EPITECH PROJECT, 2024
** server
** File description:
** parsing
*/

#include "zappy_server.h"

void destroy_parsing(parsing_t *p)
{
    dl_clear(&p->names, free);
    free(p);
}

parsing_t *init_parsing(void)
{
    parsing_t *p = malloc(sizeof(parsing_t));

    p->port = -1;
    p->width = -1;
    p->height = -1;
    p->names = NULL;
    p->clients_nb = -1;
    p->freq = -1;
    p->ok = true;
    p->help = false;
    return p;
}
