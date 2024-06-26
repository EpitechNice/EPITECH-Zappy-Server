/*
** EPITECH PROJECT, 2024
** server
** File description:
** main
*/

#include "zappy_server.h"

int main(int argc, char **argv)
{
    UNUSED char _ = init();
    parsing_t *p = parse(argc, argv);
    server_t *server = get_server();
    size_t seed = time(NULL);

    LOG(LOG_LEVEL_DEBUG, "== Seed: %lu ==", seed);
    srand(seed);
    is_parsing_ok(p);
    LOG(LOG_LEVEL_INFO, "Server has now started...");
    server->info = init_connection(p);
    server->game = init_game(p);
    destroy_parsing(p);
    run(server);
    destroy_server();
    return 0;
}
