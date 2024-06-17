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
        LOG(LOG_LEVEL_WARNING, "SIGINT handled, closing server...");
        exit(0);
    }
}
