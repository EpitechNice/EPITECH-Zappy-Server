/*
** EPITECH PROJECT, 2024
** library
** File description:
** display
*/

#ifndef INCLUDED_DISPLAY_H
    #define INCLUDED_DISPLAY_H

    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include <string.h>

    #include "mlist.h"

#if defined(__GNUC__)
    #define __FUNC__ __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
    #define __FUNC__ __FUNCSIG__
#else
    #define __FUNC__ __func__
#endif

    #define MAX_COMMAND_SIZE 256

    #define LOG(l, m) log_data(l, m, call_infos(__FILE__, __LINE__, __FUNC__))

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL,
} log_level_t;

typedef struct {
    char *file;
    size_t line;
    char *func;
} call_infos_t;

// ===== log.c =====

/**
  * @ingroup io
  *
  * @brief Stack the 3 arguments in a struct.
  *
  * @warning
  * Globally no reason tu manually use that function.
  * Part of the LOG macro
*/
call_infos_t *call_infos(const char *file, size_t line, const char *func);

/**
  * @ingroup io
  *
  * @brief Setter for the log level
  *
  * @param level New logging level, ranging from DEBUG to CRITICAL
*/
void set_log_level(log_level_t level);

/**
  * @ingroup io
  *
  * @brief Getter for the log level
  *
  * @return The current logging level
  *
  * The logging have 5 levels:
  * - DEBUG - basicly any dev-axed infos
  * - INFO - normal information for the user
  * - WARNING - something went wrong, but it's not a big deal
  * - ERROR - something went wrong and it's kinda important
  * - CRITICAL - something went horribly wrong and will 100% break.
  * These are represented by the following constants (variables of the enum
  * log_level_t) :
  * - LOG_LEVEL_DEBUG
  * - LOG_LEVEL_INFO
  * - LOG_LEVEL_WARNING
  * - LOG_LEVEL_ERROR
  * - LOG_LEVEL_CRITICAL
*/
log_level_t get_log_level(void);

/**
  * @ingroup io
  *
  * @brief Log data. Used with the LOG macro
  *
  * @danger
  * **DO NOT USE IT RAW** !!!
  * There is a LOG macro (taking a level and a message as parameter).
  * You **HAVE TO** use the macro, and not the log_data function.
  * Unfortunatly, no protections have been implemented, cause we can't.
*/
void log_data(log_level_t level, const char *message, call_infos_t *infos);

// ===== buffer.c =====

/**
  * @ingroup io
  *
  * @brief Display the buffer.
  *
  * @note
  * This function is usefull when displaying other infos at the same time
  * (like logs :thumbsup:)
*/
void display_buffer(void);

#endif
