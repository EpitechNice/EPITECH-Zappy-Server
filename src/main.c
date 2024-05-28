/*
** EPITECH PROJECT, 2024
** server
** File description:
** main
*/

#include "zappy_server.h"

void print_data(void *data)
{
    printf("\t - %s\n", (char *)data);
}

void is_parsing_ok(parsing_t *p)
{
    if (p->help) {
        destroy_parsing(p);
        destroy_server_exit(0);
    }
    if (!p->ok) {
        destroy_parsing(p);
        fprintf(stderr, ">> Have a look at the -help.\n");
        destroy_server_exit(84);
    }
}

int main(int argc, char **argv)
{
    parsing_t *p = parse(argc, argv);
    server_t *server = get_server();

    is_parsing_ok(p);
    server->info = init_connection(p);
    signal(SIGINT, &sig_handler);
    destroy_parsing(p);
    destroy_server();
    return 0;
}
