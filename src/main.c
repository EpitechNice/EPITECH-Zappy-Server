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

    is_parsing_ok(p);
    server->info = init_connection(p);
    server->game = init_game(p);
    destroy_parsing(p);
    signal(SIGINT, &sig_handler);
    run(server);
    destroy_server();
    return 0;
}
