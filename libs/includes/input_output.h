/*
** EPITECH PROJECT, 2024
** library
** File description:
** display
*/

#ifndef INCLUDED_DISPLAY_H
    #define INCLUDED_DISPLAY_H

    #define _GNU_SOURCE

    #include <stdarg.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <termios.h>
    #include <time.h>
    #include <unistd.h>

    #include "dlist.h"

#if defined(__GNUC__)
    #define __FUNC__ __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
    #define __FUNC__ __FUNCSIG__
#else
    #define __FUNC__ __func__
#endif

    #define _F __FILE__
    #define _L __LINE__
    #define _U __FUNC__

    #define MAX_COMMAND_SIZE 256
    #define MAX_WORD_SIZE 80

    #define MAX_FILLED_MESSAGE_SIZE 1024
    #define MAX_LOG_SIZE 1200
    #define MAX_LOG_DISPLAY_SIZE 1300

    #define LOG(l, m, ...) log_data(gci(_F, _L, _U), l, m, ##__VA_ARGS__)

    #define UNUSED __attribute__((unused))

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

typedef struct {
    char data[MAX_WORD_SIZE + 1];
    lnode_t *args;
} tab_option_graph_t;

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
call_infos_t *gci(const char *file, size_t line, const char *func);

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
  * @anchor log_level
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
  * @brief Set logging on stderr (true) or stdout (false, default)
  *
  * @param value true to log on STDERR, false to use STDOUT
*/
void toggle_log_on_stderr(bool value);

/**
  * @ingroup io
  *
  * @brief Log data. Used with the LOG macro
  *
  * @param pos Position in code got using the gci function.
  * @param level Logging level (see (log_level)[#log_level])
  * @param message printf like message
  *
  * @danger
  * **DO NOT USE IT RAW** !!!
  * There is a LOG macro (taking a level and a message as parameter).
  * You **HAVE TO** use the macro, and not the log_data function.
  * Unfortunatly, no protections have been implemented, cause we can't.
  *
  * Please also note that this function is defined with the format attribute,
  * so you should not be able to pass invalid printf syntax.
*/
void log_data(call_infos_t *pos, log_level_t level, const char *message, ...)
__attribute__((format(printf, 3, 4)));

// ===== log_file.c =====

/**
  * @ingroup io
  *
  * @brief Return the log file
  *
  * @return The file ptr, or NULL
*/
FILE *get_log_file(void);

/**
  * @ingroup io
  *
  * @brief Open / Close the log file
  *
  * @param filename File to open, or NULL to just close the file
*/
void opcl_log_file(const char *filename);

/**
  * @ingroup io
  *
  * @brief Display data (and log into file)
  *
  * @param out Data to be displayed.
  * @param display If the data needs to be displayed on stdout
  * @param log_on_stderr Define if stderr should be used, instead of stdout
  *
  * This function will display data and log it to logfile (if open)
  * It will display [hour:minute:sec day/mount/year] before data
  * Prefer using the LOG macro, as it will handle logging level,
  * format and more.
*/
void run_log(const char *out, bool display, bool log_on_stderr);

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
