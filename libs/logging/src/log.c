/*
** EPITECH PROJECT, 2024
** Server
** File description:
** log
*/

#include "logging.h"

static log_level_t log_level;
static bool log_on_stderr;

static void get_log_level_str(char *str, log_level_t level)
{
    if (level == LOG_LEVEL_DEBUG)
        strcpy(str, "      DEBUG     ");
    if (level == LOG_LEVEL_INFO)
        strcpy(str, "      INFO      ");
    if (level == LOG_LEVEL_WARNING)
        strcpy(str, "     WARNING    ");
    if (level == LOG_LEVEL_ERROR)
        strcpy(str, "      ERROR     ");
    if (level == LOG_LEVEL_CRITICAL)
        strcpy(str, "/!\\ CRITICAL /!\\");
}

call_infos_t *gci(const char *file, size_t line, const char *func)
{
    call_infos_t *new = (call_infos_t *)malloc(sizeof(call_infos_t));

    new->file = strdup(file);
    new->line = line;
    new->func = strdup(func);
    return new;
}

void set_log_level(log_level_t level)
{
    log_level = level;
}

log_level_t get_log_level(void)
{
    return log_level;
}

void toggle_log_on_stderr(bool value)
{
    log_on_stderr = value;
}

void log_data(call_infos_t *pos, log_level_t level, const char *message, ...)
{
    va_list list;
    char filled_message[MAX_FILLED_MESSAGE_SIZE + 1];
    char out[MAX_LOG_SIZE + 1];
    char llevel[20];
    UNUSED int _;

    va_start(list, message);
    get_log_level_str(llevel, level);
    vsnprintf(filled_message, MAX_FILLED_MESSAGE_SIZE, message, list);
    snprintf(out, MAX_LOG_SIZE, "[%s] %s:%lu (in %s) - %s", llevel, pos->file,
        pos->line, pos->func, filled_message);
    free(pos->file);
    free(pos->func);
    free(pos);
    run_log(out, (level >= get_log_level()), log_on_stderr);
}
