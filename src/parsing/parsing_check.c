/*
** EPITECH PROJECT, 2024
** server
** File description:
** parsing
*/

#include "zappy_server.h"

static void parse_check_port(parsing_t *p)
{
    if (p->port == -1) {
        LOG(LOG_LEVEL_ERROR,
            "Invalid height value. Expect a positive integer.");
        p->ok = false;
    }
}

static void parse_check_width(parsing_t *p)
{
    if (p->width == -1) {
        LOG(LOG_LEVEL_ERROR,
            "Invalid height value. Expect a positive integer.");
        p->ok = false;
    }
}

static void parse_check_height(parsing_t *p)
{
    if (p->height == -1) {
        LOG(LOG_LEVEL_ERROR,
            "Invalid height value. Expect a positive integer.");
        p->ok = false;
    }
}

static bool check_name(char *n1, char *n2, bool same)
{
    if (strcmp(n1, n2) == 0)
        return true;
    return same;
}

static void parse_check_names(parsing_t *p)
{
    bool same = false;

    if (dl_empty(p->names)) {
        LOG(LOG_LEVEL_ERROR, "Invalid names value. %s\n",
            "Expect at least one team.");
        p->ok = false;
        return;
    }
    for (lnode_t *tmp = p->names; tmp != NULL; tmp = tmp->next)
        for (lnode_t *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next)
            same = check_name((char *)tmp->data, (char *)tmp2->data, same);
    if (same) {
        LOG(LOG_LEVEL_ERROR, "2 teams cannot have the same name.\n");
        p->ok = false;
    }
}

static void parse_check_clients_nb(parsing_t *p)
{
    if (p->clients_nb == -1) {
        LOG(LOG_LEVEL_ERROR, "Invalid clientsNb value. %s\n",
            "Expect a positive integer.");
        p->ok = false;
    }
}

static void parse_check_freq(parsing_t *p)
{
    if (p->clients_nb == -1) {
        LOG(LOG_LEVEL_ERROR, "Invalid frequency value. %s\n",
            "Expect a positive integer.");
        p->ok = false;
    }
}

parsing_t *parsing_check(parsing_t *p)
{
    parse_check_port(p);
    parse_check_width(p);
    parse_check_height(p);
    parse_check_names(p);
    parse_check_clients_nb(p);
    parse_check_freq(p);
    return p;
}

void is_parsing_ok(parsing_t *p)
{
    if (p->help) {
        destroy_parsing(p);
        exit(0);
    }
    if (!p->ok) {
        destroy_parsing(p);
        LOG(LOG_LEVEL_INFO, ">> Have a look at the -help.\n");
        exit(84);
    }
}
