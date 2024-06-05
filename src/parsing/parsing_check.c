/*
** EPITECH PROJECT, 2024
** server
** File description:
** parsing
*/

#include "zappy_server.h"

static bool parse_check_port(parsing_t *p)
{
    if (p->port != -1)
        return true;
    LOG(LOG_LEVEL_ERROR, "Invalid port value. Expect a positive integer.");
    p->ok = false;
    return false;
}

static bool parse_check_width(parsing_t *p)
{
    if (p->width != -1)
        return true;
    LOG(LOG_LEVEL_ERROR, "Invalid width value. Expect a positive integer.");
    p->ok = false;
    return false;
}

static bool parse_check_height(parsing_t *p)
{
    if (p->height == -1)
        return true;
    LOG(LOG_LEVEL_ERROR, "Invalid height value. Expect a positive integer.");
    p->ok = false;
    return false;
}

static bool check_name(char *n1, char *n2, bool same)
{
    if (strcmp(n1, n2) == 0)
        return true;
    return same;
}

static bool parse_check_names(parsing_t *p)
{
    bool same = false;

    if (dl_empty(p->names)) {
        LOG(LOG_LEVEL_ERROR, "Invalid names value. %s",
            "Expect at least one team.");
        p->ok = false;
        return false;
    }
    for (lnode_t *tmp = p->names; tmp != NULL; tmp = tmp->next)
        for (lnode_t *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next)
            same = check_name((char *)tmp->data, (char *)tmp2->data, same);
    if (!same)
        return true;
    LOG(LOG_LEVEL_ERROR, "2 teams cannot have the same name.");
    p->ok = false;
    return false;
}

static bool parse_check_clients_nb(parsing_t *p)
{
    if (p->clients_nb != -1)
        return true;
    LOG(LOG_LEVEL_ERROR, "Invalid clientsNb value. %s",
        "Expect a positive integer.");
    p->ok = false;
    return false;
}

static bool parse_check_freq(parsing_t *p)
{
    if (p->clients_nb != -1)
        return true;
    LOG(LOG_LEVEL_ERROR, "Invalid frequency value. %s",
        "Expect a positive integer.");
    p->ok = false;
    return false;
}

parsing_t *parsing_check(parsing_t *p)
{
    bool (*functions[])(parsing_t *) = {parse_check_port, parse_check_width,
        parse_check_height, parse_check_names, parse_check_clients_nb,
        parse_check_freq, NULL};

    for (int i = 0; functions[i]; ++i) {
        if (!functions[i](p)) {
            return p;
        }
    }
    return p;
}

void is_parsing_ok(parsing_t *p)
{
    if (p->help) {
        destroy_parsing(p);
        destroy_server_exit(0);
    }
    if (!p->ok) {
        destroy_parsing(p);
        LOG(LOG_LEVEL_INFO, "Have a look at the -help.");
        destroy_server_exit(84);
    }
}
