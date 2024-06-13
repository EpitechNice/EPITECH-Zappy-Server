/*
** EPITECH PROJECT, 2024
** Server merged
** File description:
** inits
*/

#include "zappy_server.h"

char init(void)
{
    signal(SIGINT, &sig_handler);
    set_log_level(LOG_LEVEL_INFO);
    toggle_log_on_stderr(false);
    atexit(destroy_server);
    return 0;
}