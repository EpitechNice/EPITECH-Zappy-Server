/*
** EPITECH PROJECT, 2024
** Server
** File description:
** command_broadcast
*/

#include "zappy_server.h"

static int get_dist(int a, int b, int max, bool *used_round)
{
    int alpha = a - b;
    int bravo = ((a > b) ? (max - a + b) : (max - b + a));

    if (used_round)
        *used_round = (ABS(alpha) < ABS(bravo) ? false : true);
    return (ABS(alpha) < ABS(bravo) ? alpha : bravo);
}

static char get_char_from_dir(int x, int y)
{
    bool x_dom = (ABS(x) > ABS(y));

    if (x == 0 && y == 0)
        return 0;
    if (x == 0)
        return (y > 0) ? 4 : 0;
    if (y == 0)
        return (x > 0) ? 6 : 2;
    if (ABS(x) != ABS(y)) {
        if (x_dom)
            return (x > 0) ? 6 : 2;
        return (y > 0) ? 4 : 0;
    }
    if (x > 0)
        return (y > 0) ? 5 : 7;
    return (y > 0) ? 3 : 1;
}

static char get_direction(client_t *origin, client_t *recv)
{
    bool used_round_x;
    bool used_round_y;
    int x = get_dist(recv->x, origin->x, get_server()->game->width,
        &used_round_x);
    int y = get_dist(recv->y, origin->y, get_server()->game->height,
        &used_round_y);
    char c = get_char_from_dir(x, y);

    c += (recv->direction * 2);
    return (c % 8) + 1;
}

static char *build_message(const char *args)
{
    char *out = strdup(args[0]);

    for (int i = 1; args[i]; ++i) {
        str_append(out, " ");
        str_append(out, args[i]);
    }
    return out;
}

static int arr_length(const char **array)
{
    int i = 0;

    for (; array[i]; ++i);
    return i;
}

static char **make_valid(const char **args)
{
    int size = arr_length(args);
    char **out = (char **)malloc(sizeof(char *) * ((size > 1) ? size : 2));
    int i = 0;

    for (; args[i]; ++i)
        out[i] = strdup(args[i]);
    if (size == 1)
        out[1] = strdup(" ");
    return out;
}

static void send_message(void *client, void *infos)
{
    client_t *mclient = (client_t *)client;
    yell_infos_t *yell_infos = (yell_infos_t *)infos;
    char source = get_direction(yell_infos->source, mclient);
    char *message = NULL;
    UNUSED int _;

    if (yell_infos->source == mclient)
        return;
    _ = asprintf(&message, "message %i, %s", source, yell_infos->message);
    dl_push_back(&mclient->to_send, message);
}

void command_broadcast(UNUSED const char **args, client_t *client)
{
    char **argv = make_valid(args);
    char *message = build_message(&argv[1]);
    yell_infos_t *yell_infos = (yell_infos_t *)malloc(sizeof(yell_infos_t));

    yell_infos->message = message;
    yell_infos->source = client;
    dl_apply_data_param(get_server()->clients, send_message, yell_infos);
    free(yell_infos);
    LOG(LOG_LEVEL_INFO, "Client of team %s yelled: %s", client->team_name,
        message);
    free(message);
    free_tab(argv);
    dl_push_back(&client->to_send, strdup("ok"));
}
