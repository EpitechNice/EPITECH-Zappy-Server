/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** time
*/

#include "zappy_server.h"

size_t get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec / 1000);
}
