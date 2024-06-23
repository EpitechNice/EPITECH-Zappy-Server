/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#include "zappy_server.h"
#include "gui.h"

static void fill_map(server_t *server)
{
    if (get_time() - server->time < (20.0 / (float)server->game->freq) * 1000)
        return;
    spread_ressources(server->game);
    server->time = get_time();
    for (lnode_t *tmp = server->clients; tmp; tmp = tmp->next) {
        if (((client_t *)tmp->data)->status == GUI)
            command_mct((char *[2]){"mct", NULL}, tmp->data);
    }
}

static void check_end(server_t *server, team_t *team)
{
    int nb = 0;

    for (lnode_t *list = server->clients; list != NULL; list = list->next)
        if (((client_t *)list->data)->level == 8 &&
        strcmp(((client_t *)list->data)->team_name, team->name) == 0) {
            nb++;
        }
    if (nb >= 6) {
        LOG(LOG_LEVEL_INFO, "Game has been won by team %s", team->name);
        server->running = false;
        command_seg(team->name);
    }
}

static void manage_game(server_t *server)
{
    if (FD_ISSET(server->info->socket, &server->read_fds))
        return accept_new_connection(server);
    fill_map(server);
    for (lnode_t *tmp = server->game->teams; tmp; tmp = tmp->next)
        check_end(server, tmp->data);
}

static void manage(server_t *server)
{
    lnode_t *cli = server->clients;

    manage_game(server);
    for (; cli; cli = cli->next) {
        if (((client_t *)(cli->data))->status == AI)
            check_ai(((client_t *)(cli->data)), server);
        if (((client_t *)(cli->data))->status == WAITING)
            check_free_eggs(((client_t *)(cli->data)));
        if (FD_ISSET(((client_t *)(cli->data))->fd, &server->read_fds))
            handle_client(((client_t *)(cli->data)));
        if (FD_ISSET(((client_t *)(cli->data))->fd, &server->error_fds)) {
            LOG(LOG_LEVEL_WARNING, "Client %i disconnected",
                ((client_t *)(cli->data))->fd);
            return delete_client(cli->data);
        }
        if (FD_ISSET(((client_t *)(cli->data))->fd, &server->write_fds))
            write_command(((client_t *)(cli->data)));
    }
}

static void clear_server(server_t *server)
{
    lnode_t *clients = get_server()->clients;

    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->error_fds);
    FD_SET(server->info->socket, &server->read_fds);
    for (; clients; clients = clients->next) {
        FD_SET(((client_t *)(clients->data))->fd, &server->read_fds);
        FD_SET(((client_t *)(clients->data))->fd, &server->write_fds);
        FD_SET(((client_t *)(clients->data))->fd, &server->error_fds);
    }
}

static void loop(server_t *server)
{
    clear_server(server);
    if (select(MAX_CLIENTS, &server->read_fds, &server->write_fds,
        &server->error_fds, &get_server()->time_val) < 0) {
        toggle_log_on_stderr(true);
        LOG(LOG_LEVEL_CRITICAL, "Select failed");
        exit(84);
    }
    manage(server);
}

void run(server_t *server)
{
    FD_ZERO(&server->error_fds);
    FD_ZERO(&server->write_fds);
    FD_ZERO(&server->read_fds);
    FD_SET(server->info->socket, &server->read_fds);
    server->running = true;
    while (server->running)
        loop(server);
}
