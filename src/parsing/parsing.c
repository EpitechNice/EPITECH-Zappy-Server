/*
** EPITECH PROJECT, 2024
** server
** File description:
** parsing
*/

#include "zappy_server.h"

static int parse_port(parsing_t *p, int argc, char **argv, int i)
{
    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-p\". Expect a value.");
        return -1;
    }
    if (!is_digits(argv[i + 1])) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-p\". Expect an integer");
        return -1;
    }
    p->port = atoi(argv[i + 1]);
    return i + 1;
}

static int parse_width(parsing_t *p, int argc, char **argv, int i)
{
    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-x\". Expect a value.");
        return -1;
    }
    if (!is_digits(argv[i + 1])) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-x\". Expect an integer");
        return -1;
    }
    p->width = atoi(argv[i + 1]);
    return i + 1;
}

static int parse_height(parsing_t *p, int argc, char **argv, int i)
{
    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-y\". Expect a value.");
        return -1;
    }
    if (!is_digits(argv[i + 1])) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-y\". Expect an integer");
        return -1;
    }
    p->height = atoi(argv[i + 1]);
    return i + 1;
}

static int parse_clients_nb(parsing_t *p, int argc, char **argv, int i)
{
    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-c\". Expect a value.");
        return -1;
    }
    if (!is_digits(argv[i + 1])) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-c\". Expect an integer");
        return -1;
    }
    p->clients_nb = atoi(argv[i + 1]);
    return i + 1;
}

static int parse_freq(parsing_t *p, int argc, char **argv, int i)
{
    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-f\". Expect a value.");
        return -1;
    }
    if (!is_digits(argv[i + 1])) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-f\". Expect an integer");
        return -1;
    }
    p->freq = atoi(argv[i + 1]);
    return i + 1;
}

static int parse_names(parsing_t *p, int argc, char **argv, int i)
{
    int j = i + 1;

    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-n\". Expect a value.");
        return -1;
    }
    for (; argv[j] != NULL && argv[j][0] != '-'; j++)
        dl_push_back(&p->names, strdup(argv[j]));
    if (j == i) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-n\". %s",
            "Expect at least one value.");
        return -1;
    }
    return j - 1;
}

static int parse_log(parsing_t *p, int argc, char **argv, int i)
{
    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-l\". Expect a value.");
        return -1;
    }
    opcl_log_file(argv[i + 1]);
    return i + 1;
}

static int parse_debug(parsing_t *p, int argc, char **argv, int i)
{
    char *values[] = {"debug", "info", "warning", "error", "critical", NULL};
    int index;

    if (i + 1 >= argc) {
        p->ok = false;
        LOG(LOG_LEVEL_ERROR, "Invalid argument for \"-d\". Expect a value.");
        return -1;
    }
    to_lower(argv[i + 1]);
    index = get_str_index(values, argv[i + 1]);
    if (index == -1) {
        p->ok = false;
        LOG(LOG_LEVEL_CRITICAL, "Invalid argument for \"-d\". See -help.");
        return -1;
    }
    set_log_level(index);
    return i + 1;
}

static int parse_help(parsing_t *p, int argc, char **argv, int i)
{
    (void) argc;
    (void) argv;
    read_file("./assets/help.txt");
    p->help = true;
    return i + 1;
}

int parse_loop(int argc, char **argv, int i, parsing_t *p)
{
    int (*parse[])(parsing_t *, int, char **, int) = {
        parse_port, parse_width, parse_height, parse_names, parse_clients_nb,
        parse_freq, parse_log, parse_debug, parse_help, NULL};
    char *flags[] = {"-p", "-x", "-y", "-n", "-c", "-f", "-l", "-d",
        "-help", NULL};

    for (int j = 0; flags[j] != NULL; j++)
        if (strcmp(argv[i], flags[j]) == 0)
            return parse[j](p, argc, argv, i);
    LOG(LOG_LEVEL_ERROR, "Unkown flag: \"%s\".", argv[i]);
    p->ok = false;
    return -1;
}
