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

int main(int argc, char **argv)
{
    parsing_t *p = parse(argc, argv);

    if (p->help) {
        destroy_parsing(p);
        return 0;
    }
    if (!p->ok) {
        destroy_parsing(p);
        fprintf(stderr, ">> Have a look at the -help.\n");
        return 84;
    }
    printf("Port: %i\n", p->port);
    printf("Width: %i\n", p->width);
    printf("Height: %i\n", p->height);
    printf("Names:\n");
    dl_apply_data(p->names, &print_data);
    printf("Clients number: %i\n", p->clients_nb);
    printf("frequency: %i\n", p->freq);
    destroy_parsing(p);
    return 0;
}
