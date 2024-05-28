/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** signal
*/

#include "zappy_server.h"

void sig_handler(int sig)
{
    if (sig == SIGINT) {
        destroy_server_exit(sig);
    }
}