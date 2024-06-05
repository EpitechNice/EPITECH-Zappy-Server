/*
** EPITECH PROJECT, 2024
** server
** File description:
** main
*/

#include "zappy_server.h"

int main(int argc, char **argv)
{
    parsing_t *p = parse(argc, argv);
    server_t *server = get_server();

    signal(SIGINT, &sig_handler);
    set_log_level(LOG_LEVEL_INFO);
    toggle_log_on_stderr(false);
    is_parsing_ok(p);
    server->info = init_connection(p);
    server->game = init_game(p);
    destroy_parsing(p);
    run(server);
    destroy_server();
    return 0;
}
