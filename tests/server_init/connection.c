/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** connection
*/

#include <criterion/criterion.h>
#include "zappy_server.h"

Test(init_connection, test1)
{
    parsing_t *p = malloc(sizeof(parsing_t));
    p->port = 4242;
    p->width = 10;
    p->height = 10;
    dl_push_front(&p->names, "toto");
    p->clients_nb = 10;
    p->freq = 100;
    p->ok = true;
    p->help = false;
    connect_t *connect = init_connection(p);

    cr_assert_eq(connect->port, 4242);
    cr_assert_eq(connect->address->sin_addr.s_addr, INADDR_ANY);
    cr_assert_eq(connect->address->sin_family, AF_INET);
    cr_assert_eq(connect->address->sin_port, htons(4242));
    free(connect);
    free(p);
}