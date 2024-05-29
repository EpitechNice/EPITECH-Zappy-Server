/*
** EPITECH PROJECT, 2024
** library
** File description:
** linked_list
*/

#ifndef INCLUDED_DISPLAY_H
    #define INCLUDED_DISPLAY_H

    /*  ---- INCLUDE ----*/

    #include <stdio.h>
    #include <stdlib.h>

    /*  ---- PREPROCESS ----*/

    #define MAX_COMMAND_SIZE 256

    /*  ---- STRUCTURE ----*/

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL,
} log_level_t;

    /*  ---- FUNCTION ----*/

void display_buffer();

#endif /* LINKED_LIST_H_ */
