/*
** EPITECH PROJECT, 2024
** Server
** File description:
** log_file
*/

#include "input_output.h"

static FILE *logfile;

FILE *get_log_file(void)
{
    return logfile;
}

void opcl_log_file(const char *filename)
{
    if (logfile)
        fclose(logfile);
    logfile = NULL;
    if (!filename)
        return;
    logfile = fopen(filename, "a+");
    if (!logfile)
        LOG(LOG_LEVEL_ERROR, "Could not open file \"%s\"", filename);
}

void run_log(const char *data, bool display, bool log_on_stderr)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char out[MAX_LOG_DISPLAY_SIZE + 1];

    snprintf(out, MAX_LOG_DISPLAY_SIZE, "[%02i:%02i:%02i %02i/%02i/%i] %s",
        tm.tm_sec, tm.tm_min, tm.tm_hour, tm.tm_mday, tm.tm_mon + 1, tm.tm_year
            + 1900, data);
    if (display)
        fprintf((log_on_stderr ? stderr : stdout), "\r%s\n", out);
    if (get_log_file())
        fprintf(get_log_file(), "%s\n", out);
}
