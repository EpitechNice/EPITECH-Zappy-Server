/*
** EPITECH PROJECT, 2024
** Server
** File description:
** log
*/

#include "input_output.h"

static log_level_t log_level;
static mlist_t *logs;

call_infos_t *call_infos(const char *file, size_t line, const char *func)
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

void log_data(log_level_t level, const char *message, call_infos_t *infos)
{
    char *out = (char *)malloc(38 + strlen(message) + strlen(infos->file) +
        strlen(infos->func));
    char llevel[20];

    if (level == LOG_LEVEL_DEBUG)
        strcpy("      DEBUG     ", llevel);
    if (level == LOG_LEVEL_INFO)
        strcpy("      INFO      ", llevel);
    if (level == LOG_LEVEL_WARNING)
        strcpy("     WARNING    ", llevel);
    if (level == LOG_LEVEL_ERROR)
        strcpy("      ERROR     ", llevel);
    if (level == LOG_LEVEL_CRITICAL)
        strcpy("/!\\ CRITICAL /!\\", llevel);
    sprintf(out, "[%s] %s:%lu (in %s) - %s", llevel, infos->file, infos->line,
        infos->func, message);
    m_list_add_at_pos(logs, m_list_new(out), MLIST_POS_LAST);
    ffree(infos->file);
    ffree(infos->func);
    ffree(infos);
}
